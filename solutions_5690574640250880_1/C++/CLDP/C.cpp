#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

char x[55][55];

int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        int R, C, M;
        cin >> R >> C >> M;
        cout << "Case #" << times << ":" << endl;
        if (M == R * C - 1) {
            for (int i = 0; i < R - 1; ++i) {
                for (int j = 0; j < C; ++j) cout << "*";
                cout << endl;
            }
            for (int j = 0; j < C - 1; ++j) cout << "*";
            cout << "c" << endl;
            continue;
        }
        if (R == 1) {
            for (int j = 0; j < M; ++j) cout << "*";
            for (int j = M; j < C - 1; ++j) cout << ".";
            cout << "c" << endl;
            continue;
        }
        if (C == 1) {
            for (int i = 0; i < M; ++i) cout << "*" << endl;
            for (int i = M; i < R - 1; ++i) cout << "." << endl;
            cout << "c" << endl;
            continue;
        }
        
        if (M == R * C - 2 || M == R * C - 3) {
            cout << "Impossible" << endl;
            continue;
        }
        if (R == 2) {
            if (M & 1) {
                cout << "Impossible" << endl;
                continue;
            }
            for (int j = 0; j < 2; ++j) {
                for (int i = 0; i < C; ++i) {
                    if (i < M / 2) cout << "*"; else 
                    if (j == 1 && i == C - 1) cout << "c"; else cout << ".";
                }
                cout << endl;
            }
            continue;
        }
        if (C == 2) {
            if (M & 1) {
                cout << "Impossible" << endl;
                continue;
            }
            for (int i = 0; i < R; ++i) {
                if (i < M / 2) cout << "**" << endl; else 
                if (i == R - 1) cout << ".c" << endl; else cout << ".." << endl;
            }
            continue;
        }
        
        for (int i = 0; i < R; ++i)
         for (int j = 0; j < C; ++j) x[i][j] = '*';
        
        M = R * C - M;
        
        if (M == 5 || M == 7) {
            cout << "Impossible" << endl;
            continue;
        }
        
        if (M >= 2 * R + 2 * C - 4) {
            for (int i = 0; i < C; ++i) x[0][i] = x[1][i] = '.';
            for (int i = 0; i < R; ++i) x[i][0] = x[i][1] = '.';
            M -= 2 * R + 2 * C - 4;
            for (int i = 2; i < R; ++i)
             for (int j = 2; j < C; ++j) {
                 if (M > 0) x[i][j] = '.';
                 --M;
             }
            
            x[0][0] = 'c';
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) cout << x[i][j];
                cout << endl;
            }
            continue;
        }
        if (M % 2 == 0) {
            for (int i = 0; i < C; ++i) {
                if (M > 0) x[0][i] = x[1][i] = '.';
                M -= 2;
            }
            for (int i = 2; i < R; ++i) {
                if (M > 0) x[i][0] = x[i][1] = '.';
                M -= 2;
            }
            
            x[0][0] = 'c';
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) cout << x[i][j];
                cout << endl;
            }
            continue;
        }
        
        bool flag = false;
        for (int i = 2; i <= R; ++i) {
            if (M % i == 0 && M / i > 1 && M / i <= C) {
                for (int p = 0; p < i; ++p)
                 for (int q = 0; q < M / i; ++q) x[p][q] = '.';
                x[0][0] = 'c';
                flag = true;
            }
            /*
            if (M / i > 1 && M / i <= C && M % i % 2 == 0 && M - M / i * i <= 2 * (R - i)) {
                for (int p = 0; p < i; ++p)
                 for (int q = 0; q < M / i; ++q) x[p][q] = '.';
                M -= M / i * i;
                x[0][0] = 'c';
                for (int p = i; p < R; ++p) {
                    if (M > 0) x[p][0] = x[p][1] = '.';
                    M -= 2;
                }
                flag = true;
            }
            */
            
        }
        if (flag) {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) cout << x[i][j];
                cout << endl;
            }
            continue;
        }
        
        flag = false;
        if (R > C) {
            swap(R, C);
            flag = true;
            for (int i = 0; i < R; ++i)
             for (int j = 0; j < C; ++j) x[i][j] = '*';
        }
        
        int k = 0;
        while (M >= 2 * C) {
            M -= C;
            for (int j = 0; j < C; ++j) x[k][j] = '.';
            ++k;
        }
        for (int j = 0; j < (M + 1) / 2; ++j) x[k][j] = '.';
        ++k;
        
        M -= (M + 1) / 2;
        cerr << times << endl;
        for (int j = 0; j < M; ++j) x[k][j] = '.';
        
        
        
        x[0][0] = 'c';
        if (flag) {
            for (int i = 0; i < C; ++i) {
                for (int j = 0; j < R; ++j) cout << x[j][i];
                cout << endl;
            }
        } else {
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) cout << x[i][j];
                cout << endl;
            }
        }
    }
    return 0;
}
