#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)
#define MAXN 300

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef vector <long long> vll;

int tests;
int n;
vector <string> s;
string t;
vector <int> cnt(MAXN, 0), d(MAXN, 0);
vector <int> l(MAXN, 0), r(MAXN, 0);
vector <int> z(MAXN, 0), w(MAXN, 0);
vector <int> mark(MAXN, 0);
ll val = 0;
const ll MOD = 1000000007;
bool flag;

string process(string s) {
    string res;
    res += s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            res += s[i];
        }
    }
    forn (i, res.size()) {
        cnt[res[i]]++;
    }
    return res;
}

ll factorial(ll x) {
    ll res = 1;
    for (ll i = 1; i <= x; i++) {
        res *= i;
        res %= MOD;
    }
    return res;
}

void dfs(int c, int p = -1) {
    mark[c] = 1;
    //printf(">%d\n", c);
    if (r[c] && r[c] != p ) {
        if (mark[r[c]]) {
            flag = false;
            return;
        }
        dfs(r[c], c);
    }
    if (l[c] && l[c] != p) {
        if (mark[l[c]]) {
            flag = false;
            return;
        }
        dfs(l[c], c);
    }
}

ll solve() {
    cin >> n;
    forn (i, n) {
        cin >> t;
        s.pb(process(t));
    }
    ll pair = 0;
    forn (i, n) {
        if (s[i].size() > 2) {

            for (int j = 1; j < s[i].size() - 1; j++) {
                if (cnt[s[i][j]] != 1) {
                    return 0;
                }
            }
            t = "";
            t += s[i][0];
            t += s[i][s[i].size() - 1];
            if (t[0] == t[1]) return 0;
            s[i] = t;
            //cout << ">" << s[i] << endl;
        }
        if (s[i].size() == 2) {
           // cout << s[i] << endl;
            if (r[s[i][0]]) return 0;
            if (l[s[i][1]]) return 0;
            r[s[i][0]] = s[i][1];
            l[s[i][1]] = s[i][0];
            pair++;
        }
        if (s[i].size() == 1) {
            z[s[i][0]]++;
        }
        for (int j = 0; j < s[i].size(); j++) {
            if (!w[s[i][j]]) val++;
            w[s[i][j]]++;
        }
    }
    //cout << "val =  " << val << endl;
    //cout << "pair =  " << pair << endl;
    ll ans = 1;
    for (int i = 0; i < MAXN; i++) {
        ans *= factorial(z[i]);
        ans %= MOD;
    }
    for (int i = 0; i < MAXN; i++) {
        if (!mark[i]) dfs(i);
    }
    if (!flag) return 0;
    ans *= factorial(val - pair);

    ans %= MOD;
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> tests;
    forn (it, tests) {
        s.clear();
        val = 0;
        flag = true;
        cnt = vector <int> (MAXN, 0);
        d   = vector <int> (MAXN, 0);
        l   = vector <int> (MAXN, 0);
        r   = vector <int> (MAXN, 0);
        z   = vector <int> (MAXN, 0);
        w   = vector <int> (MAXN, 0);
        mark   = vector <int> (MAXN, 0);
        printf("Case #%d: ", it + 1);
        cout << solve() << endl;
    }
    //freopen("output.txt", "w", stdout);
    return 0;
}
