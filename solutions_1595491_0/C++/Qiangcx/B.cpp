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

#define maxn 110
#define Fup(i, s, t) for (int i = s; i <= t; i ++)
#define Fdn(i, s, t) for (int i = s; i >= t; i --)
#define Path(i, s) for (int i = s; i; i = d[i].next)

using namespace std;

int x[maxn];
int n, s, p;

void init()
{
    cin >> n >> s >> p;
    Fup(i, 1, n)
        cin >> x[i];
}

void solve()
{
    int ans = 0;
    Fup(i, 1, n)
        if (x[i] >= p + 2 * max(p - 1, 0))
            ans ++;
        else
            if (s > 0 && x[i] >= p + 2 * max(p - 2, 0)){
                ans ++;
                s --;
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
        init();
        solve();
    }
    return 0;
}
