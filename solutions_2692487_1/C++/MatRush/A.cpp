#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>
#include <cmath>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline int sgn(double x) {
    return x < -eps ? -1 : x > eps;
}
int a[111];
int main() {
    //freopen("A-large-practice.in", "r", stdin);
    //freopen("A-large-practice.out", "w", stdout);
    long long A, n;
    int cas;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        //scanf("%d %d", &A, &n);
        cin >> A >> n;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = 0x3F3F3F3F;
        long long tA = A;
        for (int i = 0; i <= n; i++) {
            A = tA;
            int j = 0;
            int tmp = n - i;
            for (; j < i; j++) {
                if (A > a[j]) {
                    A += a[j];
                } else {
                    break;
                }
            }
            bool flag = false;
            for (int k = j; k < i; k++) {
                while (A <= a[k]) {
                    if (A == 1) {
                        flag = true;
                        break;
                    }
                    A += A - 1;
                    tmp++;
                }
                A += a[k];
            }
            if (!flag) {
                ans = min(ans, tmp);
            }
        }
        printf("Case #%d: ", T);
        printf("%d\n", ans);
    }
    return 0;
}
