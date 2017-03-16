#include <cmath>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int tot, n, m;
double ans, p[100010];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tot;
    int num = 0;
    while (num < tot) {
        ++num;
        cin >> m >> n;
        for (int i = 1; i <= m; ++i)
            cin >> p[i];
        ans = 2+n;
        double tmp = 1;
        for (int i = 0; i <= m; ++i) {
            if (2*n+m-2*i+2-tmp*(n+1) < ans)
                ans = 2*n+m-2*i+2-tmp*(n+1);
            tmp *= p[i+1];
        }
        printf("Case #%d: %.7lf\n", num, ans);
    }
}
