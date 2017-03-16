#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>

#define LL long long
#define FN "ex"
#define SIZE 200000

using namespace std;

LL T, n, m, ans, temp, p, q;

int main() {
    freopen(FN".in", "r", stdin);
    freopen(FN".out", "w", stdout);
    cin >> T;
    for (int iter = 0; iter < T; iter++) {
        scanf("%I64d/%I64d ", &p, &q);
        n = 0;
        temp = q;
        while (temp % 2 == 0) temp /= 2;
        if (p % temp != 0) {
            cout << "Case #" << iter + 1 << ": impossible" << endl;
            continue;
        }
        while (p < q) {
            q /= 2;
            n++;
        }
        cout << "Case #" << iter + 1 << ": " << n << endl;
    }
}






