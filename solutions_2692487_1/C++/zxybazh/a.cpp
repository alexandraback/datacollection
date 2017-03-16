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
#define N 11111

int n, m, k, t, p, T, a[N], ans;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    re(T);
    for (int _ = 1; _ <= T; _++) {
        re2(m, n);
        for (int i = 0; i < n; i++) re(a[i]);
        sort(a, a + n);
        t = 0; ans = n;
        for (int i = 0; i < n; i++) {
            if (m > a[i]) m += a[i]; else {
                if (m == 1) break;
                while (m <= a[i]) {
                    m += m-1;
                    t++;
                }
                m += a[i];
            }
            ans = min(ans, t + (n-i-1));
        }
        cout << "Case #" << _ << ": " << ans << endl;
    }
    return 0;
}

