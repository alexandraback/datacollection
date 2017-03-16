#include <vector>
#include <list>
#include <cassert>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <string> vs;
const int INF = 0x3f3f3f3f;
const int MAXN = 200;
const int ITER = 100000;
const long double EPS = 1e-11;

int s[MAXN];
int n,total;

bool works(int ind, long double val)
{
    long double left = 100-val;
    for (int i=0; i<n; i++)
    {
        if (i == ind) continue;
        left -= 100*max((long double)0.0, (((s[ind] + total*(val/100)) - s[i]) / total) + EPS);
    }
    return (left < 0);
}

void solve()
{
    cout << setprecision(15);
    cin >> n;
    total = 0;
    for (int i=0; i<n; i++)
        cin >> s[i], total += s[i];

    for (int cur = 0; cur < n; cur++)
    {
        if (works(cur,0)) cout << 0 << ' ';
        else
        {
            long double hi = 100, lo = 0, mid = 50;
            for (int i=0; i<ITER; i++)
            {
                if (works(cur,mid))
                    hi = mid;
                else
                    lo = mid;
                mid = (hi+lo)/2;
            }
            cout << mid << ' ';
        }
    }
    cout << endl;
}

int main()
{
    int t; cin >> t;
    for (int kase=1; kase<=t; kase++)
    {
        cout << "Case #" << kase << ": ";
        solve();
    }
    return 0;
}
