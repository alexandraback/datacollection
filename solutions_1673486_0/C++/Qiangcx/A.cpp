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

#define maxn 100010
#define Fup(i, s, t) for (int i = s; i <= t; i ++)
#define Fdn(i, s, t) for (int i = s; i >= t; i --)
#define Path(i, s) for (int i = s; i; i = d[i].next)

using namespace std;

double p[maxn], P[maxn], s[maxn];
int a, b, t;

void init()
{
    cin >> a >> b;
    Fup(i, 1, a)
        cin >> p[i];
    s[0] = 1.0;
    Fup(i, 1, a)
        s[i] = s[i - 1] * p[i];
}

void solve()
{
    P[0] = s[a];
    Fup(i, 1, a)
        P[i] = s[a - i] * (1 - p[a - i + 1]);
    Fup(i, 1, a)
        P[i] = P[i] + P[i - 1];
    double ans = 2 + b;
    Fup(i, 0, a){
        double t = P[i] * (2 * i + b - a + 1) + (1 - P[i]) * (2 * i + 2 * b - a + 2);
        ans = min(ans, t);
    }
    cout << ans << endl;
}

int main()
{
//    freopen("temp.in", "r", stdin);
//    freopen("temp.out", "w", stdout);
    ios::sync_with_stdio(false);
    cout << fixed;
    cout.precision(6);
    cin >> t;
    Fup(i, 1, t){
        cout << "Case #" << i << ": ";
        init();
        solve();
    }
    return 0;
}
