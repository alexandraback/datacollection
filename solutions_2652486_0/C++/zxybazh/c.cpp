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

int n, m, k, t, nk, p, r, a[11], hash[11111];
bool flag;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("ou.txt", "w", stdout);
    re(n);re2(r,n); re2(m,k);
    puts("Case #1:"); t = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < k; j++) re(a[j]);
        flag = false;
        for (int a1 = 2; a1 <= m; a1++) {
            if (flag) break;
            for (int a2 = 2; a2 <= m; a2++) {
                if (flag) break;
                for (int a3 = 2; a3 <= m; a3++) {
                        if (flag) break;
                        t++;
                        hash[a1] = hash[a2] = hash[a3] = hash[a1*a2] = hash[a1*a3] = hash[a2*a3] = hash[a1*a2*a3] = hash[1] = t;
                        for (int j = 0; j < k; j++) if (hash[a[j]] != t) {flag = true; break;}
                        flag = !flag;
                        if (flag) printf("%d%d%d\n", a1, a2, a3);
                    }
            }
        }
        if (!flag) printf("222\n");
    }
    return 0;
}

