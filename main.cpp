#include <iostream>

using namespace std;

int tabla_de_joc [3][3];
string i1,i2,i3,i4,i5,i6,i7,i8,i9;

void draw_table(){
    for (int i = 0; i < 250; ++i) { std::cout << endl; } // Clear Screen
    cout << endl;
    cout << "  "<<i1<< "  |  "<<i2<<"  | "<<i3<<"  "<< endl;
    cout << "----------------"<< endl;
    cout << "  "<<i4<< "  |  "<<i5<<"  | "<<i6<<"  "<< endl;
    cout << "----------------"<< endl;
    cout << "  "<<i7<< "  |  "<<i8<<"  | "<<i9<<"  "<< endl;
    cout << endl;
}

int check_win (){
    for (int i=0; i<2; i++ ) {
        // Linie
        if (tabla_de_joc[0][0] == i && tabla_de_joc[0][1] == i && tabla_de_joc[0][2] == i) return 1;
        if (tabla_de_joc[1][0] == i && tabla_de_joc[1][1] == i && tabla_de_joc[1][2] == i) return 1;
        if (tabla_de_joc[2][0] == i && tabla_de_joc[2][1] == i && tabla_de_joc[2][2] == i) return 1;
        // Coloana
        if (tabla_de_joc[0][0] == i && tabla_de_joc[1][0] == i && tabla_de_joc[2][0] == i) return 1;
        if (tabla_de_joc[0][1] == i && tabla_de_joc[1][1] == i && tabla_de_joc[2][1] == i) return 1;
        if (tabla_de_joc[0][2] == i && tabla_de_joc[1][2] == i && tabla_de_joc[2][2] == i) return 1;
        // Diagonala
        if (tabla_de_joc[0][0] == i && tabla_de_joc[1][1] == i && tabla_de_joc[2][2] == i) return 1;
        if (tabla_de_joc[0][2] == i && tabla_de_joc[1][1] == i && tabla_de_joc[2][0] == i) return 1;
    }
    return 0;
}

void init_table (){
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            tabla_de_joc[i][j] = -1;
}

void afisare (){
    for (int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << tabla_de_joc[i][j] << " ";
        }
        cout << endl;
    }
}

int add_to_table (int val, int i, int j){
    if ( tabla_de_joc[i][j] == -1) {
        tabla_de_joc[i][j] = val;
        return 1;
    }
    return 0;
}

int s_player(){
    // Init
    i1 = "1"; i2 = "2"; i3 = "3";
    i4 = "4"; i5 = "5"; i6 = "6";
    i7 = "7"; i8 = "8"; i9 = "9";
    draw_table();
}
int m_player(){
    // Init
    int num;
    i1 = "1"; i2 = "2"; i3 = "3";
    i4 = "4"; i5 = "5"; i6 = "6";
    i7 = "7"; i8 = "8"; i9 = "9";

    init_table();

    while (1) {
        label:
        draw_table();
        cout << " Player 1 | Alege un numar de la 1 la 9 : " << endl << endl;
        cin >> num;
        if (num > 0 && num < 10) {
            if (num == 1) { if (tabla_de_joc[0][0] == -1) {i1 = "X"; add_to_table(1,0,0);} else goto label; }
            if (num == 2) { if (tabla_de_joc[0][1] == -1) {i2 = "X"; add_to_table(1,0,1);} else goto label; }
            if (num == 3) { if (tabla_de_joc[0][2] == -1) {i3 = "X"; add_to_table(1,0,2);} else goto label; }
            if (num == 4) { if (tabla_de_joc[1][0] == -1) {i4 = "X"; add_to_table(1,1,0);} else goto label; }
            if (num == 5) { if (tabla_de_joc[1][1] == -1) {i5 = "X"; add_to_table(1,1,1);} else goto label; }
            if (num == 6) { if (tabla_de_joc[1][2] == -1) {i6 = "X"; add_to_table(1,1,2);} else goto label; }
            if (num == 7) { if (tabla_de_joc[2][0] == -1) {i7 = "X"; add_to_table(1,2,0);} else goto label; }
            if (num == 8) { if (tabla_de_joc[2][1] == -1) {i8 = "X"; add_to_table(1,2,1);} else goto label; }
            if (num == 9 ){ if (tabla_de_joc[2][2] == -1) {i9 = "X"; add_to_table(1,2,2);} else goto label; }
        }
        if (check_win() == 1) { draw_table(); cout << endl << "Player 1 a castigat"; break; }
        label_1:
        draw_table();
        cout << " Player 2 | Alege un numar de la 1 la 9 : " << endl << endl;
        cin >> num;
        if (num > 0 && num < 10) {
            if (num == 1) { if (tabla_de_joc[0][0] == -1) { i1 = "0"; add_to_table(0,0,0); } else goto label_1; };
            if (num == 2) { if (tabla_de_joc[0][1] == -1) { i2 = "0"; add_to_table(0,0,1); } else goto label_1; };
            if (num == 3) { if (tabla_de_joc[0][2] == -1) { i3 = "0"; add_to_table(0,0,2); } else goto label_1; };
            if (num == 4) { if (tabla_de_joc[1][0] == -1) { i4 = "0"; add_to_table(0,1,0); } else goto label_1; };
            if (num == 5) { if (tabla_de_joc[1][1] == -1) { i5 = "0"; add_to_table(0,1,1); } else goto label_1; };
            if (num == 6) { if (tabla_de_joc[1][2] == -1) { i6 = "0"; add_to_table(0,1,2); } else goto label_1; };
            if (num == 7) { if (tabla_de_joc[2][0] == -1) { i7 = "0"; add_to_table(0,2,0); } else goto label_1; };
            if (num == 8) { if (tabla_de_joc[2][1] == -1) { i8 = "0"; add_to_table(0,2,1); } else goto label_1; };
            if (num == 9) { if (tabla_de_joc[2][2] == -1) { i9 = "0"; add_to_table(0,2,2); } else goto label_1; };

        }
        if (check_win() == 1) { draw_table(); cout << endl << "Player 2 a castigat"; break; }
    }
}

// 1. MENIU
void meniu(){
    cout << "-------------------------"<< endl;
    cout << "---Multiplayer X SI 0----"<< endl;
    cout << "-------------------------"<< endl;
    cout << "1. Start"<< endl;
    cout << "2. Exit" << endl;
    cout << ">";
}
void meniu_optiune (){
    int v;
    meniu();
    cin >> v;
    if (v > 0 && v < 4) {
        if (v == 1) m_player();
        if (v == 2) exit (-1);
    }
    else {
        cout << "-- Optiunea nu exista --";
        meniu_optiune();
    }
}

int main() {
    meniu_optiune();
    return 0;
}