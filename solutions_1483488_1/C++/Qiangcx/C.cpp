#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

#define Fup(i, s, t) for (int i = s; i <= t; i ++)
#define Fdn(i, s, t) for (int i = s; i >= t; i --)
#define Path(i, s) for (int i = s; i; i = d[i].next)

using namespace std;

int use[2000010];
int x[10];

void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    memset(use, 0, sizeof(use));
    Fup(k, a, b - 1){
        int t = k, now = 0;
        while (t > 0){
            x[now ++] = t % 10;
            t /= 10;
        }
        Fup(j, 0, now - 2){
            int c = 0;
            Fup(i, 0, now - 1)
                c = c * 10 + x[(j + now - i) % now];
            if (c > k && c <= b && use[c] < k){
                use[c] = k;
                ans ++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
//    freopen("temp.in", "r", stdin);
//    freopen("temp.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    Fup(i, 1, t){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
