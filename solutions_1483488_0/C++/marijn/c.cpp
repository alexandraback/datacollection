#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int log10(int a) {
    int i = 1;
    for (int m = 10; m <= a; m*=10) i++;
    return i;
}

int main() {
    int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    int n; scanf("%d", &n);
    for (int c = 1; c <= n; c++) {
        int ans = 0;
        int a, b;
        scanf("%d %d", &a, &b);
        for (int n = a; n <= b; n++) {
            int l = log10(n);
            int gotm[20]; int nm = 0;
            for (int i = 1; i < l; i++) {
                int r = n % pow10[i];
                int rem = (n - r) / pow10[i];
                int m = r * pow10[l-i] + rem;
                if (m > n && m <= b) {
                    bool ok = true;
                    for (int j = 0; j < nm; j++) if (gotm[j] == m) ok = false;
                    if (ok) {
                        ans++;
                        gotm[nm++] = m;
                    }
//                    cout << n << " " << m << endl;
                }
            }
        }
        cout << "Case #" << c << ": " << ans << endl;
    }
    return 0;
}