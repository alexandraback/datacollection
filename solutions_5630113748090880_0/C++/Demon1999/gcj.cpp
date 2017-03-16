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

int t, n, ak, kk[3000];

string s, ans;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("B-small-attempt0.in", "r",  stdin));
    freopen("B-small-attempt0.out", "w",  stdout);
    cin >> t;
    forn (i, t) {
        forn (i, 3000) kk[i] = 0;
        cin >> n;
        forn (j, 2 * n - 1) {
            forn (p, n) {
                cin >> ak;
                kk[ak]++;
            }
        }
        cout << "Case #" << i + 1 << ": ";
        forn (i, 3000)
            if (kk[i] % 2)
                cout << " " << i;
        cout << "\n";
    }
    return 0;
}

