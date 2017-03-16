#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define LD long double
#define VI vector<int>
#define PB push_back
#define MP make_pair
#define re(x) scanf("%d", &x)
#define re2(x,y) scanf("%d%d", &x, &y)
#define wt(x) printf("%d ", x)
#define wl(x) printf("%d\n", x)
#define N 2222

double fac(int p) {
    double ans = 1;
    for (int i = 2; i <= p; i++) ans *= (double)i;
    return ans;
}

double c(int x, int y) {
    double ans = fac(x)/fac(y)/fac(x-y);
    return ans;
}

int n, m, k, t, p, T, x, y;
double ans, mod;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    re(T);
    for (int _ = 1; _ <= T; _++) {
        re(n); re2(x, y);
        if (n == 1) {
            if (x == 0 && y == 0) printf("Case #%d: %.7lf\n", _, 1.0);
            else printf("Case #%d: %.7lf\n", _, 0.0);
        } else {
            n--; k = 2; t = 0;
            while (n >= 2*k+1) {
                t+=2; n -= 2*k+1; k += 2;
            }
            if (t+2 == abs(x)+y && x == 0) {
                printf("Case #%d: %.7lf\n", _, 0.0);continue;
            }
            if (abs(x) + y <= t) {printf("Case #%d: %.7lf\n", _, 1.0);continue;}
            if (abs(x) + y >t+2) {printf("Case #%d: %.7lf\n", _, 0.0);continue;}
            ans = 0; mod = 0;
            for (int p = max(0, n-t-2); p <= min(n, t+2); p++)
                mod += c(n, p);
            for (int p = max(y+1, n-t-2); p <= min(n, t+2); p++) {
                ans += c(n, p);
            }
            //cout << n << endl;
            //cout << max(0, n-t-2) << " " << min(n, t+2) << endl;
            //cout << mod << endl;
            if (abs(mod) < 1e-7) printf("Case #%d: %.7lf\n", _, mod); else
            printf("Case #%d: %.7lf\n", _, ans/mod);
        }
    }
    return 0;
}

