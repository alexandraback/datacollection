#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
typedef unsigned long long ull;

ull abs(ull a, ull b) {
    return a > b ? a - b : b - a;
}

ull pow(int p) {
    ull ret = 1;
    while (p--) ret *= 10ull;
    return ret;
}

int select_digit(string& A, string& B, ull a, ull b, int i, int n) {
    int p = n - i - 1;
    int d = 0;

    if (i < n - 1 && A[i+1] == '?') {
        while (d < 9
            && abs(a + pow(p), b) < abs(a, b)
            && a + pow(p) <= b
        ) {
            a += pow(p);
            d++;
        }
    } else if (i < n - 1 && B[i+1] == '?') {
        while (d < 9
            && (abs(a + pow(p), b) < abs(a, b)
                || (a + pow(p) > b && a + pow(p) - b <= 9))
        ) {
            a += pow(p);
            d++;
        }
    } else {
        while (d < 9 && abs(a + pow(p), b) < abs(a, b)) {
            a += pow(p);
            d++;
        }
    }

    return d;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string C, J;
        cin >> C >> J;
        int n = C.size();

        ull c = 0, j = 0;
        for (int i = 0; i < n; i++)
            if (C[i] != '?')
                c += (C[i] - '0') * pow(n - i - 1);
        for (int i = 0; i < n; i++)
            if (J[i] != '?')
                j += (J[i] - '0') * pow(n - i - 1);

        for (int i = 0; i < n; i++) {
            if (C[i] == '?')
                c += pow(n - i - 1) * select_digit(C, J, c, j, i, n);
            if (J[i] == '?')
                j += pow(n - i - 1) * select_digit(J, C, j, c, i, n);
        }

        cout << "Case #" << t << ": ";
        cout << setw(n) << setfill('0') << c;
        cout << " ";
        cout << setw(n) << setfill('0') << j;
        cout << endl;
    }

    return 0;
}
