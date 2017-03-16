#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <set>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

#define forn(i,n) for(int i = 0; i < (int)n; ++i)
#define _mp(a,b) make_pair(a,b)
#define _pb(x) push_back(x)
#define mins(a,b) a = min(a,b)
#define maxs(a,b) a = max(a,b)

int main() {
   ios_base::sync_with_stdio(false);
//    cout << fixed;
//    cout << setprecision(9);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T = 0;
    cin >> T;
    forn(test, T)
    {
        cout << "Case #"<< test+1 << ": ";
        int a,b,k;
        cin >> a >> b >> k;
        int ans = 0;
        forn(i,a)
            forn(j,b)
                if ((i&j) < k)
                    ++ans;
        cout << ans << "\n";
    }

    return 0;
}
