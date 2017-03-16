#include <iostream>

using namespace std;

int n;
string t[4];

bool voitto(int y, int x, int ys, int xs, char m) {
    for (int i = 0; i < 4; i++) {
        if (t[y][x] != m && t[y][x] != 'T') {
            return false;
        }
        y += ys;
        x += xs;
    }
    return true;
}

bool valmis() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (t[i][j] == '.') return false;
        }
    }
    return true;
}

void tutki(int n) {
    char v = 'D';
    for (int i = 0; i < 4; i++) {
        if (voitto(0, i, 1, 0, 'X')) v = 'X';
        if (voitto(0, i, 1, 0, 'O')) v = 'O';
        if (voitto(i, 0, 0, 1, 'X')) v = 'X';
        if (voitto(i, 0, 0, 1, 'O')) v = 'O';
    }
    if (voitto(0, 0, 1, 1, 'X')) v = 'X';
    if (voitto(0, 0, 1, 1, 'O')) v = 'O';
    if (voitto(3, 0, -1, 1, 'X')) v = 'X';
    if (voitto(3, 0, -1, 1, 'O')) v = 'O';
    cout << "Case #" << n << ": ";
    if (v == 'D') {
        if (valmis()) {
            cout << "Draw\n";
        } else {
            cout << "Game has not completed\n";
        }
    } else {
        cout << v << " won\n";
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> t[j];
        }
        tutki(i+1);
    }
}
