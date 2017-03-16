#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;

const int n = 4;


bool killX (char ch) {
    if (ch == '.' || ch == 'O') {
        return true;
    }
    return false;
}

bool killO (char ch) {
    if (ch == '.' || ch == 'X') {
        return true;
    }
    return false;
}

void solve(int test) {
    vector<string> vec(n);

    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    bool xWon = false;
    bool oWon = false;
    int used = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec[i][j] != '.') {
                ++used;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        bool x = true;
        bool o = true;
        for (int j = 0; j < n; ++j) {
            if (killX(vec[i][j])) x = false;
            if (killO(vec[i][j])) o = false;
        }
        if (x) xWon = true;
        if (o) oWon = true;
    }
    for (int j = 0; j < n; ++j) {
        bool x = true;
        bool o = true;
        for (int i = 0; i < n; ++i) {
            if (killX(vec[i][j])) x = false;
            if (killO(vec[i][j])) o = false;
        }
        if (x) xWon = true;
        if (o) oWon = true;
    }
    bool x = true;
    bool o = true;
    for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
        if (killX(vec[i][j])) x = false;
        if (killO(vec[i][j])) o = false;
    }
    if (x) xWon = true;
    if (o) oWon = true;

    x = true;
    o = true;
    for (int i = 0, j = n - 1; i < n && j >= 0; ++i, --j) {
        if (killX(vec[i][j])) x = false;
        if (killO(vec[i][j])) o = false;
    }
    if (x) xWon = true;
    if (o) oWon = true;

    cout << "Case #" << test << ": ";
    if (xWon) {
        cout << "X won\n";
    }
    else if (oWon) {
        cout << "O won\n";
    }
    else if (used == n * n) {
        cout << "Draw\n";
    }
    else {
        cout << "Game has not completed\n";
    }
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; ++test) {
        solve(test);
    }
    return 0;
}
