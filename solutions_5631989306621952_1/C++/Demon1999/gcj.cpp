#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int t;
string s, ans;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("A-large.in", "r",  stdin));
    freopen("A-large.out", "w",  stdout);
    cin >> t;
    forn (i, t) {
        cin >> s;
        ans = "";
        forn (j, sz(s)) {
            int pos = 0;
            while (pos < sz(ans) && ans[pos] == s[j]) pos++;
            //cout << pos << " ";
            if (pos < sz(ans) && ans[pos] < s[j]) {
                string tt = "";
                tt += s[j];
                tt += ans;
                ans = tt;
            }
            else ans += s[j];
        }
        cout << "Case #" << i + 1 << ": " << ans << "\n";
    }
    return 0;
}

