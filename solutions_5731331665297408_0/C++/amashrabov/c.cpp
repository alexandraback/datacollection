#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

#define TEST "small"
const int N = 100;
string zip[N];
vi g[N];
int pdfs[N];

int n, m;

bool can(int v, int cand)
{
    vector<char> visited(n);
    forn (i, n)
        if (pdfs[i] != -1)
            visited[i] = true;
    while (v >= 0)
    {
        bool was = false;
        for (int to: g[v])
            if (to == cand)
            {
                was = true;
                break;
            }
        if (was)
            break;
        v = pdfs[v];
    }
    assert(v >= 0); 
    queue<int> q;
    int u = v;
    while (v >= 0)
    {
        q.push(v);
        v = pdfs[v];
    }
    q.push(cand);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int to: g[v])
            if (!visited[to]) {
                q.push(to);
                visited[to] = true;
            }
    }
    forn (i, n)
        if (!visited[i]) return false;
    pdfs[cand] = u;
    return true;
}

void solve()
{
    string res;
    cin >> n >> m;
    forn (i, n)
    {
        cin >> zip[i];
        g[i].clear();
    }
    forn (i, m)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int st = 0;
    forn (i, n)
        if (zip[i] < zip[st])
            st = i;
    res += zip[st];
    forn (i, n) pdfs[i] = -1;
    pdfs[st] = -31;
    int v = st;
    int q = 1;
    while (q != n)
    {
        vi reach(n,-1);
        int cv = v;
        while (v >= 0)
        {
            for (int to: g[v])
            if (pdfs[to] == -1 && reach[to] == -1)
            {
                reach[to] = v;
            }
            v = pdfs[v];
        } 
        assert(v == -31);
        
        vector<pair<string, int> > cand;
        forn (i, n)
        if (reach[i] >= 0)
        {
            cand.pb(mp(zip[i], i));
        }

        sort(all(cand));
        bool changed = false;
        v = cv;
        for (auto w: cand)
        if (can(v, w.se))
        {
            res += w.fi;
            v = w.se;
            changed = true;
            break;
        }
        assert(changed);
        ++q;
    }

    cout << res << "\n";
}

int main() {
#ifndef TEST
	freopen("input.txt", "r", stdin);
#else 
    freopen(TEST".in", "r", stdin);
    freopen(TEST".out", "w", stdout);
#endif
    int T;
    cin >> T;
    for1 (t, T)
	{
		cout << "Case #" << t << ": ";
	    solve();
    }
	return 0;
}
