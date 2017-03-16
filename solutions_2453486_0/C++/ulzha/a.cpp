#include <iostream>
using namespace std;

char b[4][5];

bool line(int r, int c, int dr, int dc, char x) {
    for (int i = 0; i < 4; i++) {
        char b = ::b[r + i * dr][c + i * dc];
        
        if (b != x && b != 'T') return false;
    }
    
    return true;
}

bool won(char x) {
    if (line(0, 0, 1, 1, x) || line(0, 3, 1, -1, x)) return true;
    
    for (int i = 0; i < 4; i++) {
        if (line(0, i, 1, 0, x) || line(i, 0, 0, 1, x)) return true;
    }
    
    return false;
}

int main() {
    int nt, it;

    cin >> nt;
    for (it = 1; it <= nt; it++) {
        int i, j;
        bool dot = false;
        
        for (i = 0; i < 4; i++) {
            cin >> b[i];
            for (j = 0; j < 4; j++) if (b[i][j] == '.') dot = true;
        }

        cout << "Case #" << it << ": ";
        if (won('X')) {
            cout << "X won";
        } else if (won('O')) {
            cout << "O won";
        } else if (dot) {
            cout << "Game has not completed";
        } else {
            cout << "Draw";
        }
        cout << endl;
    }
}
