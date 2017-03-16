#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#define pb push_back
#define MAXN 3
#define INF 0x3f3f3f3f
using namespace std;

string c;
string j;
vector <string> pos[MAXN + 5];
int n;

int check(string a, string b) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int tonum(string a) {
    int r = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        r = 10 * r + a[i] - '0';
    }
    return r;
}

void backtrack(int got, string x, int size) {
    if (got >= size) {
        pos[size].pb(x);
        return;
    }

    for (int i = 0; i <= 9; i++) {
        string aux = x;
        aux += i + '0';
        backtrack(got + 1, aux, size);
    }
    return;
}

int main(void) {
    int t;

    for (int size = 1; size <= MAXN; size++) {
        backtrack(0, "", size);
    }

    scanf(" %d", &t);
    for (int caso = 1; caso <= t; caso++) {
        cin >> c >> j;
        int n = (int)c.size();
        int best_delta = INF;
        string best_cod = "";
        string best_jam = "";

        for (int i = 0; i < (int)pos[n].size(); i++) {
            for (int k = 0; k < (int)pos[n].size(); k++) {
                if (check(pos[n][i], c) && check(pos[n][k], j)) {
                    int a = tonum(pos[n][i]);
                    int b = tonum(pos[n][k]);
                    if (abs(a - b) < best_delta) {
                        best_delta = abs(a - b);
                        best_cod = pos[n][i];
                        best_jam = pos[n][k];
                    } else if (abs(a - b) == best_delta) {
                        if (a < tonum(best_cod)) {
                            best_cod = pos[n][i];
                            best_jam = pos[n][k];
                        } else if (a == tonum(best_cod)) {
                            if (b < tonum(best_jam)) {
                                best_jam = pos[n][k];
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: ", caso);
        cout << best_cod << " " << best_jam << endl;
    }
    return 0;
}
