#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

#define NMAX 105
#define ALP 255

int n;
string s[NMAX];
int b[ALP], e[ALP], m[ALP], a[ALP];
bool ok;

bool used[NMAX];

void process(string& s, int id)
{
    bool one = true;
    forv(i, s)
        if (s[i] != s[0]) one = false;
    if (one)
    {
		if (m[s.back()] != -1)
			ok = false;

        a[s[0]]++;
		used[id] = true;
        return;
    }

    if (b[s[0]] != -1 || m[s[0]] != -1) 
    {
        ok = false;
        return;
    }
    if (e[s.back()] != -1 || m[s.back()] != -1) 
    {
        ok = false;
        return;
    }

    b[s[0]] = id;
    e[s.back()] = id;

    int l = 0; 
    while (l < (int)s.size())
    {
        int r = l;
        while (r < (int)s.size() && s[r] == s[l]) r++;
        if (l != 0 && r != (int)s.size())
        {
            if (m[s[l]] != -1 || b[s[l]] != -1 || e[s[l]] != -1 || a[s[l]] > 0)
            {
                ok = false;
                return;
            }
            m[s[l]] = id;
        }
        l = r;
    }
}


const ll mod = 1000000007;

ll fact[NMAX];

void solve(int test)
{
    printf("Case #%d: ", test);

    cin >> n;
    forn(i, n) cin >> s[i];

    memset(b, -1, sizeof(b));
    memset(e, -1, sizeof(e));
    memset(m, -1, sizeof(m));
    
    memset(a, 0, sizeof(a));
    memset(used, 0, sizeof(used));

    ok = true;

    forn(i, n)
    {
        process(s[i], i);
    }
    if (!ok) 
    {
        cout << 0 << endl;
        return;
    }

    int next[NMAX];
    int prev[NMAX];

    memset(next, -1, sizeof(next));
    memset(prev, -1, sizeof(prev));

    forn(i, ALP)
    {
        if (b[i] != -1 && e[i] != -1) 
        {
            next[e[i]] = b[i];
            prev[b[i]] = e[i];
        }
    }


    int comp = 0;
    forn(i, n)
    {
        if (used[i]) continue;
        int u = i;

        while (u != -1 && !used[u])
        {
            used[u] = true;
            u = next[u];
        }

        if (u != -1) //cycle!
        {
            cout << 0 << endl;
            return;
        }

        used[i] = false; u = i;

        while (u != -1 && !used[u])
        {
            used[u] = true;
            u = prev[u];
        }
        if (u != -1) //cycle!
        {
            cout << 0 << endl;
            return;
        }

        comp++;
    }

    ll ans = 1;

    forn(i, ALP)
    {
        if (a[i] > 0 && b[i] == -1 && e[i] == -1) comp++;
        if (a[i] > 0) ans = (ans * fact[a[i]]) % mod;
    }

    ans = (ans * fact[comp]) % mod;

    cout << ans << endl;
}
int main()
{
    freopen(CIN_FILE, "rt", stdin);
    freopen(COUT_FILE, "wt", stdout);

    fact[0] = 1;

    for1(i, NMAX - 1)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int tc;
    scanf("%d\n", &tc);
    forn(it, tc) solve(it + 1);
    
    return 0;
}
