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
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("A-small-attempt3.in", "r",  stdin));
    freopen("A-small-attempt3.out", "w", stdout);
    cin >> n;
    forn (i, n) {
        cin >> k;
        cout << "Case #" << i + 1 << ": ";
        if (k == 0) {
            cout << "INSOMNIA\n";
            continue;
        }
        forn (i, 10) jj[i] = 0;
        qq = 0;
        for (ll p = 1; ; p++) {
            c = p * k;
            while (c) {
                jj[c % 10]++;
                if (jj[c  %10] == 1) qq++;
                c /= 10;
            }
            if (qq == 10) {
                cout << p * k << "\n";
                break;
            }
        }
    }
    return 0;
}

