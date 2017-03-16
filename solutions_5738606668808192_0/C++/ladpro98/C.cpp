#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int a[N];
int Div[N];
int n;
int J;

bool ok() {
    for (int base = 2; base <= 10; ++base) {
        bool found = false;
        for (int d = 2; d <= 100; ++d) {
            int mod = 0;
            int power = 1;
            for (int i = n - 1; i >= 0; --i) {
                if (a[i]) mod = (mod + power) % d;
                power = power * base % d;
            }
            if (mod == 0) {
                Div[base] = d;
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

void show() {
    for (int i = 0; i < n; ++i) cout << a[i];
    cout << ' ';
    for (int i = 2; i <= 10; ++i) cout << Div[i] << ' ';
    cout << endl;
}

int main() {
    freopen("C1.out", "w", stdout);
    cout << "Case #1:\n";
    n = 32; J = 500;
    for (int mask = 0; ; ++mask) {
        a[0] = a[n - 1] = 1;
        for (int i = 1; i + 1 < n; ++i)
            a[i] = mask >> (i - 1) & 1;
        if (ok()) {
            show();
            --J;
        }
        if (J == 0) break;
    }
    return 0;
}
