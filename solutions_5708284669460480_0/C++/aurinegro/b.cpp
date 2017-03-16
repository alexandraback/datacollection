#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cout << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

vi pre;
vector<int> prefix_function (string s) {
	int n = (int) s.length();
	vector<int> pi (n);
	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

int k,l,s;
vvi aut;
string kb, pat; 

double memo[110][110];
double go(int from, int pref) {
    if (pref == l) return 1 + go(from, pre[pref]);
    if (from == s) return 0;

    double &res = memo[from][pref];
    if (res > -.5) return res;

    res = 0;
    forn(i,k) res += go(from+1, aut[pref][kb[i]]);
    res /= k;
    return res;
}

bool check() {
    forn(i,si(pat)) {
        bool found = false;
        forn(j,si(kb)) if (kb[j] == pat[i]) found = true;
        if (!found) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);

    int T; cin >> T;
    cout << fixed << setprecision(10);
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": ";
        cin >> k >> l >> s;

        cin >> kb >> pat;


        if (!check()) { cout << 0 << endl; continue; }

        pat += '#';
        int n = (int) pat.length();
        pre = prefix_function(pat);
        aut = vvi(n, vector<int> (300));
        for (int i=0; i<n; ++i)
            for (char c='A'; c <= 'Z'; c++)
                if (i > 0 && c != pat[i])
                    aut[i][c] = aut[pre[i-1]][c];
                else
                    aut[i][c] = i + (c == pat[i]);

        forn(i,110) forn(j,110) memo[i][j] = -1;

        double res = 1 + (s-l) / (l - pre[l]);
        res -= go(0,0);
        cout << res << endl;
    }
    
    return 0;
}
