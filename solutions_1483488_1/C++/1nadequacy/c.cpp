#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <sstream>
#include <queue>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)

const int maxn = 2000500;

vector<int> a[maxn];


int getnum(string& s)
{
    int res = 0;
    forn (i, sz(s)) res = res*10 + s[i]-'0';
    return res;
}

int main()
{

    freopen("a.in", "r", stdin)
/    freopen("a.out", "w", stdout);

    forn (i, maxn)
    {
        ostringstream sout; sout << i;
        string s = sout.str();
        string t = s;
        forn (j, sz(s))
        {
            if (t[0] != '0')
            {
                int x = getnum(t);
                if (x < i) a[i].pb(x);
            }
            rotate(t.begin(), t.begin()+1, t.end());

        }
        sort(a[i].begin(), a[i].end());
        a[i].resize(unique(a[i].begin(), a[i].end())-a[i].begin());
    }


    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt)
    {
        int l, r; scanf("%d %d", &l, &r);
        int res  = 0;
        for (int x=l; x<=r; ++x)
            forn (i, sz(a[x])) if (a[x][i] >= l && a[x][i] <= r) ++res;
        printf("Case #%d: %d\n", tt, res);
    }

    return 0;
}
