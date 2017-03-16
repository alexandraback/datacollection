#include <iostream>
#include <string>

using namespace std;

typedef int table[1000][1000];
table c, c1, matr, answer;

void multiply(const table a, const table b, table c, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        for (int k = 0; k < n; k++) {
                                c[i][j] += a[i][k] * b[k][j];
                        }
                }
        }
}

void copy_matr(table a, const table b, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        a[i][j] = b[i][j];
                }
        }
}

void sum(table a, const table b, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        a[i][j] += b[i][j];
                }
        }
}

void nulle(table a, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        a[i][j] = 0;
                }
        }
}

string ans(const table a, int n) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        if (a[i][j] > 1) {
                                return "Yes";
                        }
                }
        }
        return "No";
}

void print(table matr, int n) {
        for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                        cout << matr[j][k] << ' ';
                }
                cout << endl;
        }
        cout << endl;
}

int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
                int n;
                cin >> n;
                nulle(matr, n);
                for (int j = 0; j < n; j++) {
                        int l;
                        cin >> l;
                        for (int k = 0; k < l; k++) {
                                int y;
                                cin >> y;
                                matr[j][y - 1] = 1;
                        }
                }
        //        print(matr, n);
                copy_matr(c, matr, n);
                copy_matr(answer , matr, n);
                for (int j = 0; j < n - 1; j++) {
                        multiply(c, matr, c1, n);
                        copy_matr(c, c1, n);
                        sum(answer, c, n);
                        nulle(c1, n);
                }
                cout << "Case #" << i + 1 << ": " << ans(answer, n) << endl;
        }
        return 0;
}
