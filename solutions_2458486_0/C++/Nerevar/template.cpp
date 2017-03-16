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
#include <string.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

const int NMAX = 20;
const int KMAX = 205;

int n, k;
vector<int> a[NMAX];
int t[NMAX];
bool used[1 << NMAX];
int cnt[KMAX];
vector<int> cur, best;

void rec(int mask)
{
    if (!best.empty()) return;
    if (mask == (1 << n) - 1)
    {
        best = cur;
        return;
    }
    if (used[mask]) return;
    used[mask] = true;

    forn(i, n)
    {
        if (mask & (1 << i)) continue;

        if (cnt[t[i]] == 0) continue;

        cnt[t[i]]--;
        forv(j, a[i]) cnt[a[i][j]]++;
        cur.pb(i);

        rec(mask | (1 << i));

        if (!best.empty()) return;
        cur.pop_back();

        cnt[t[i]]++;
        forv(j, a[i]) cnt[a[i][j]]--;
    }
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    memset(used, 0, sizeof(used));
    memset(cnt, 0, sizeof(cnt));
    cin >> k >> n;
    forn(i, k)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    forn(i, n)
    {
        int m;
		cin >> t[i];
        cin >> m;		
        a[i] = vector<int>(m);
        forn(j, m) cin >> a[i][j];
    }
    best.clear(); 
    cur.clear();

    rec(0);

    if (best.empty())
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        forv(i, best)
        {
            if (i) cout << " ";
            cout << best[i] + 1;
        }
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
