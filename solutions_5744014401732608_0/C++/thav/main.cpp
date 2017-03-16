#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

bool matrix[55][55];

void printSol(int n) {
    cout << "POSSIBLE\n";
    for(int i = 0; i < n; i++, cout << '\n')
        for(int j = 0; j < n; j++)
            cout << matrix[i][j];

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    string c, j;
    int casos;
    cin >> casos;
    for(int cas = 1; cas <= casos; cas++) {
        int b, m;
        memset(matrix, 0, sizeof(matrix));
        cout << "Case #" << cas << ": ";
        cin >> b >> m;
        for(int i = 0; i < b; i++)
            for(int j = i + 1; j < b; j++)
                matrix[i][j] = 1;
        if((1 << (b - 2)) < m) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        if((1 << (b - 2)) == m) {
            printSol(b);
            continue;
        }

        matrix[0][b - 1] = 0;
        for(int i = 0; i < b - 2; i++) {
            if((m & (1 << i)) == 0) {
                matrix[0][b - 2 - i] = 0;
            }
        }
        printSol(b);
    }
}
