#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

int n, m, k, r;
vector< vector<int> > a;
vector<int> cur;
vector< map<int, int> > cnt;

void rec(int p)
{
    if (p == n)
    {
        a.pb(cur);
        cnt.pb(map<int, int>());
        forn(mask, (1 << n))
        {
            int prod = 1;
            forn(i, n) if (mask & (1 << i)) prod *= cur[i];
            cnt[cnt.size()-1][prod]++;
        }
        return;
    }

    for (int i = 2; i <= m; i++)
    {
        cur[p] = i;
        rec(p + 1);
    }
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d:\n", tc);
    cin >> r >> n >> m >> k;

    cur = vector<int>(n, 0);
    a.clear();
    rec(0);

    forn(it, r)
    {
        vector<int> b(k);
        forn(i, k) cin >> b[i];

        double maxp = 0;
        int best = 0;

        forv(i, a)
        {
            double curp = 1.0;
            forn(j, k)
            {
                curp *= (double)(cnt[i][b[j]]) / (1 << n);
            }

            if (curp > maxp)
            {
                maxp = curp;
                best = i;
            }
        }

        forn(i, n) cout << a[best][i];
        cout << endl;
    }
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
