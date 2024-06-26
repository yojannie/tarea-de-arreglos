#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cedulas;
vector<string> nombres;
vector<int> tipos_empleado;
vector<double> precios_hora;
vector<int> horas_laboradas;
vector<double> salarios_ordinarios;
vector<double> aumentos;
vector<double> salarios_brutos;
vector<double> deducciones_ccss;
vector<double> salarios_netos;

void mostrar_datos_empleado(int index) {
    cout << "\ncedula: " << cedulas[index] << endl;
    cout << "nombre empleado: " << nombres[index] << endl;
    cout << "tipo empleado: " << tipos_empleado[index] << endl;
    cout << "salario por hora: " << precios_hora[index] << endl;
    cout << "cantidad de horas: " << horas_laboradas[index] << endl;
    cout << "salario ordinario: " << salarios_ordinarios[index] << endl;
    cout << "aumento: " << aumentos[index] << endl;
    cout << "salario bruto: " << salarios_brutos[index] << endl;
    cout << "deducción ccss: " << deducciones_ccss[index] << endl;
    cout << "salario neto: " << salarios_netos[index] << endl;
}

void mostrar_estadisticas(int cant_operarios, double acum_neto_operarios, int cant_tecnicos, double acum_neto_tecnicos, int cant_profesionales, double acum_neto_profesionales) {
    double promedio_neto_operarios = cant_operarios ? acum_neto_operarios / cant_operarios : 0;
    double promedio_neto_tecnicos = cant_tecnicos ? acum_neto_tecnicos / cant_tecnicos : 0;
    double promedio_neto_profesionales = cant_profesionales ? acum_neto_profesionales / cant_profesionales : 0;

    cout << "\nestadísticas:" << endl;
    cout << "1) cantidad empleados tipo operarios: " << cant_operarios << endl;
    cout << "2) acumulado salario neto para operarios: " << acum_neto_operarios << endl;
    cout << "3) promedio salario neto para operarios: " << promedio_neto_operarios << endl;
    cout << "4) cantidad empleados tipo técnico: " << cant_tecnicos << endl;
    cout << "5) acumulado salario neto para técnicos: " << acum_neto_tecnicos << endl;
    cout << "6) promedio salario neto para técnicos: " << promedio_neto_tecnicos << endl;
    cout << "7) cantidad empleados tipo profesional: " << cant_profesionales << endl;
    cout << "8) acumulado salario neto para profesionales: " << acum_neto_profesionales << endl;
    cout << "9) promedio salario neto para profesionales: " << promedio_neto_profesionales << endl;
}

void agregar_empleado() {
    string cedula, nombre;
    int tipo_empleado, horas;
    double precio_hora;

    cout << "ingrese la cedula del empleado: ";
    cin >> cedula;
    cout << "ingrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "ingrese el tipo de empleado (1-operario, 2-tecnico, 3-profesional): ";
    cin >> tipo_empleado;
    cout << "ingrese el precio por hora: ";
    cin >> precio_hora;
    cout << "ingrese la cantidad de horas laboradas: ";
    cin >> horas;

    double salario_ordinario = precio_hora * horas;
    double aumento = 0;

    switch (tipo_empleado) {
        case 1: aumento = salario_ordinario * 0.15; break;
        case 2: aumento = salario_ordinario * 0.10; break;
        case 3: aumento = salario_ordinario * 0.05; break;
    }

    double salario_bruto = salario_ordinario + aumento;
    double deduccion_ccss = salario_bruto * 0.0917;
    double salario_neto = salario_bruto - deduccion_ccss;

    cedulas.push_back(cedula);
    nombres.push_back(nombre);
    tipos_empleado.push_back(tipo_empleado);
    precios_hora.push_back(precio_hora);
    horas_laboradas.push_back(horas);
    salarios_ordinarios.push_back(salario_ordinario);
    aumentos.push_back(aumento);
    salarios_brutos.push_back(salario_bruto);
    deducciones_ccss.push_back(deduccion_ccss);
    salarios_netos.push_back(salario_neto);

    cout << "empleado agregado correctamente." << endl;
}

void consultar_empleado(string cedula) {
    vector<string>::iterator it = find(cedulas.begin(), cedulas.end(), cedula);
    if (it != cedulas.end()) {
        int index = distance(cedulas.begin(), it);
        mostrar_datos_empleado(index);
    } else {
        cout << "empleado no encontrado." << endl;
    }
}

void modificar_empleado(string cedula) {
    vector<string>::iterator it = find(cedulas.begin(), cedulas.end(), cedula);
    if (it != cedulas.end()) {
        int index = distance(cedulas.begin(), it);
        string nombre;
        int tipo_empleado, horas;
        double precio_hora;

        cout << "ingrese el nuevo nombre del empleado: ";
        cin.ignore();
        getline(cin, nombre);
        cout << "ingrese el nuevo tipo de empleado (1-operario, 2-tecnico, 3-profesional): ";
        cin >> tipo_empleado;
        cout << "ingrese el nuevo precio por hora: ";
        cin >> precio_hora;
        cout << "ingrese la nueva cantidad de horas laboradas: ";
        cin >> horas;

        double salario_ordinario = precio_hora * horas;
        double aumento = 0;

        switch (tipo_empleado) {
            case 1: aumento = salario_ordinario * 0.15; break;
            case 2: aumento = salario_ordinario * 0.10; break;
            case 3: aumento = salario_ordinario * 0.05; break;
        }

        double salario_bruto = salario_ordinario + aumento;
        double deduccion_ccss = salario_bruto * 0.0917;
        double salario_neto = salario_bruto - deduccion_ccss;

        nombres[index] = nombre;
        tipos_empleado[index] = tipo_empleado;
        precios_hora[index] = precio_hora;
        horas_laboradas[index] = horas;
        salarios_ordinarios[index] = salario_ordinario;
        aumentos[index] = aumento;
        salarios_brutos[index] = salario_bruto;
        deducciones_ccss[index] = deduccion_ccss;
        salarios_netos[index] = salario_neto;

        cout << "empleado modificado correctamente." << endl;
    } else {
        cout << "empleado no encontrado." << endl;
    }
}

void borrar_empleado(string cedula) {
    vector<string>::iterator it = find(cedulas.begin(), cedulas.end(), cedula);
    if (it != cedulas.end()) {
        int index = distance(cedulas.begin(), it);

        cedulas.erase(cedulas.begin() + index);
        nombres.erase(nombres.begin() + index);
        tipos_empleado.erase(tipos_empleado.begin() + index);
        precios_hora.erase(precios_hora.begin() + index);
        horas_laboradas.erase(horas_laboradas.begin() + index);
        salarios_ordinarios.erase(salarios_ordinarios.begin() + index);
        aumentos.erase(aumentos.begin() + index);
        salarios_brutos.erase(salarios_brutos.begin() + index);
        deducciones_ccss.erase(deducciones_ccss.begin() + index);
        salarios_netos.erase(salarios_netos.begin() + index);

        cout << "empleado eliminado correctamente." << endl;
    } else {
        cout << "empleado no encontrado." << endl;
    }
}

int main() {
    char continuar;
    int cant_operarios = 0, cant_tecnicos = 0, cant_profesionales = 0;
    double acum_neto_operarios = 0, acum_neto_tecnicos = 0, acum_neto_profesionales = 0;

    do {
        agregar_empleado();

        cout << "¿desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

    for (size_t i = 0; i < cedulas.size(); ++i) {
        switch (tipos_empleado[i]) {
            case 1: acum_neto_operarios += salarios_netos[i]; cant_operarios++; break;
            case 2: acum_neto_tecnicos += salarios_netos[i]; cant_tecnicos++; break;
            case 3: acum_neto_profesionales += salarios_netos[i]; cant_profesionales++; break;
        }
    }

    mostrar_estadisticas(cant_operarios, acum_neto_operarios, cant_tecnicos, acum_neto_tecnicos, cant_profesionales, acum_neto_profesionales);

    return 0;
}



