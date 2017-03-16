#include <fstream>
using namespace std;

ifstream sf("tttt.in");
ofstream vf("tttt.out");

int n;
char t[4][4];

int check (char a, char b, char c, char d) {
    if (a == 'T') a = b;
    else if (b == 'T') b = a; 
    else if (c == 'T') c = a;   
    else if (d == 'T') d = a;  
    if (a == b && a == c && a == d) {
        if (a == 'X') return 1;
        else if (a == 'O') return 2;
    }   
    return 0;
}

int main () {
    sf >> n;
    for (int i = 1; i <= n; i++) {
        vf << "Case #" << i << ": ";
        bool gotRoom = false;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                sf >> t[j][k];   
            }   
        }
        
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (!gotRoom && t[j][k] == '.') gotRoom = true;
            }   
        }
        int temp;
        temp = check(t[0][0], t[0][1], t[0][2], t[0][3]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[1][0], t[1][1], t[1][2], t[1][3]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[2][0], t[2][1], t[2][2], t[2][3]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[3][0], t[3][1], t[3][2], t[3][3]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[0][0], t[1][0], t[2][0], t[3][0]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[0][1], t[1][1], t[2][1], t[3][1]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[0][2], t[1][2], t[2][2], t[3][2]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[0][3], t[1][3], t[2][3], t[3][3]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[0][0], t[1][1], t[2][2], t[3][3]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        temp = check(t[0][3], t[1][2], t[2][1], t[3][0]);
        if (temp == 1) {
            vf << "X won" << endl;
            continue;   
        }
        else if (temp == 2) {
            vf << "O won" << endl;
            continue;   
        }
        if (gotRoom) vf << "Game has not completed" << endl;
        else vf << "Draw" << endl;
    }       
}
