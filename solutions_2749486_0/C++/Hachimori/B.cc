#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#define r first
#define c second
using namespace std;
typedef pair<int,int> Data;
const int BUF = 1000;


int row, col;

void read() {
    cin >> col >> row;
}


void work(int cases) {
    string ans = "";
    if (row > 0) {
        while (row > 0) {
            row--;
            ans += "SN";
        }
    }
    else {
        while (row < 0) {
            row++;
            ans += "NS";
        }
    }

    if (col > 0) {
        while (col > 0) {
            col--;
            ans += "WE";
        }
    }
    else {
        while (col < 0) {
            col++;
            ans += "EW";
        }
    }

    cout << "Case #" << cases << ": " << ans << endl;
}


int main() {
    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        read();
        work(i + 1);
    }
    return 0;
}
