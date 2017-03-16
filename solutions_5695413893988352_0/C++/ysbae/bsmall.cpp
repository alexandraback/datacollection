#include <iostream>

using namespace std;

char C[30], J[30];
long long sol, sola, solb;

void printStr(long long a, int len) {
    char out[30];

    for (int i = len - 1; i >= 0; i--) {
        out[i] = (a % 10) + '0';
        a /= 10;
    }
    out[len] = 0;
    cout << out;
}

long long abs(long long a) {
    return (a >= 0 ? a : -a); 
}

long long mmin(char *a, long long init) {
    long long res = init;
    for (int i = 0; i < strlen(a); i++) {
        res *= 10;
        if (a[i] != '?') 
            res += a[i] - '0';
    }
    return res;
}

long long mmax(char *a, long long init) {
    long long res = init;
    for (int i = 0; i < strlen(a); i++) {
        res *= 10;
        if (a[i] != '?') 
            res += a[i] - '0';
        else
            res += 9;
    }
    return res;
}

void updatesol(long long tsol, long long tsola, long long tsolb) {
    if (sol == -1 || sol > tsol || (sol == tsol && sola > tsola) || (sol == tsol && sola == tsola && solb > tsolb)) {
        sol = tsol;
        sola = tsola;
        solb = tsolb;
    }
}

int valid(char *a, long long t, int from) {
    for (int i = from; i >= 0; i--) {
        if (!(a[i] == '?' || (a[i] - '0') == (t % 10)))
            return 0;
        t /= 10;
    }
    return 1;
}

int main() {
    int T, tc;
    char sol1[30], sol2[30];
    long long a;
    long long b;

    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cout << "Case #" << tc << ": ";

        cin >> C >> J;

        sol = -1;
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 1000; j++) {
                if (valid(C, i, strlen(C) - 1) && valid(J, j, strlen(J) - 1)) {
                    updatesol(abs(i - j), i, j);
                }
            }
        }
        printStr(sola, strlen(C));
        cout << ' ';
        printStr(solb, strlen(C));
        cout << endl;
    }
    return 0;
}
