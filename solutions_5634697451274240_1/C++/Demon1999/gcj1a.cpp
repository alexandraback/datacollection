#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

ll n, k, c, qq, jj[10];
string s;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("B-large.in", "r",  stdin));
    freopen("B-large.out", "w", stdout);
    cin >> n;
    forn (i, n) {
        cin >> s;
        int k = 0;
        cout << "Case #" << i + 1 << ": ";
        forn (i, sz(s)) {
            if (i && s[i]!= s[i - 1]) k++;
        }
        if (s[sz(s) - 1] == '-') cout << k + 1 << "\n";
        else cout << k << "\n";
    }
    return 0;
}

