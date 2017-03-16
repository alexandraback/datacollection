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
    cout << setprecision(3);
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int T = 0;
    cin >> T;
    forn(Case,T)
    {
        int n = 0;
        cin >> n;
        vector<double> a(n);
        forn(i,n)
            cin >> a[i];
        sort(a.begin(), a.end());

        vector<double> b(n);
        forn(i,n)
            cin >> b[i];
        sort(b.begin(), b.end());

//        forn(i,n)
//            cout << a[i] << " \n"[i == n-1];
//        forn(i,n)
//            cout << b[i] << " \n"[i == n-1];

        int index = 0;
        forn(i,n)
        {
            if (b[i] > a[index])
                ++index;
        }

        int start = 0;
        while (start < n && b[n-start-1] > a[n-1])
            ++start;
        int ansIndex = 0;
        for(;start < n; ++start)
        {
            if (a[start] > b[ansIndex])
                ++ansIndex;
        }
        cout << "Case #" << Case+1 << ": ";
        cout << ansIndex << " " << n-index << "\n";
    }
    return 0;
}
