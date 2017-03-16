#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)



int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(7);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T = 0;
    cin >> T;
    int const maxl = 16;
    int const maxn = 4;
    forn(Case,T)
    {
        double c,f,x;
        cin >> c >> f >> x;
        double curSpeed = 2.0;
        double curTime = 0.0;
        double ans = x/curSpeed;
        while (curTime < ans)
        {
            curTime += c/curSpeed;
            curSpeed += f;
            mins(ans, curTime + x/curSpeed);
        }
        cout << "Case #" << Case+1 << ": " << ans << "\n";
    }
    return 0;
}
