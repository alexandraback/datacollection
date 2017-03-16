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


string a[3024];

bool func(int x, int y)
{
    if (sz(a[x]) != sz(a[y])) return false;
    string s = a[x];
    forn (i, sz(s))
    {
        if (s == a[y]) return true;
        rotate(s.begin(), s.begin()+1, s.end());
    }
    return false;
}

int main()
{

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    forn (i, 1024) 
    {
        ostringstream sin; sin << i;
        a[i] = sin.str();
    }

    int tc; scanf("%d", &tc);
    for (int tt=1; tt<=tc; ++tt)
    {
        int l, r; scanf("%d %d", &l, &r);
        int res  = 0;
        for (int x=l; x<=r; ++x)
            for (int y=x+1; y<=r; ++y)
                res += func(x, y);
        printf("Case #%d: %d\n", tt, res);
    }

    return 0;
}
