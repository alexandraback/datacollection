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

ll t, n, k, c, qq, jj[11], kk[11];
string s = "3 2 3 2 5 2 3 2 3", s1 = "";

ll prime(ll k) {
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0)
        re i;
    re 0;
}
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    assert(freopen("C-large.in", "r",  stdin));
    freopen("C-large.out", "w", stdout);
    cin >> t >> n >> k;
    cout << "Case #1:\n";
    s1 = "1";
    forn (i, n - 2)
        s1 += "0";
    s1 += "1";
    vector<int> pp;
    for (int i = 0; i < (1 << 7); i++) {
        int k = 0;
        forn (j, 7) {
            if (i & (1 << j)) k++;
        }
        if (k == 4) pp.push_back(i);
    }
    forn (i, sz(pp)) {
        //cout << "KKE\n";
        forn (j, sz(pp)) {
            if (k == 0) re 0;
            int q = 0;
            ll kk = 1, p1 = 1;
            for (int nu = 1; nu < 15; nu += 2) {
                s1[nu] = s1[nu + 1] = '0';
                if (pp[i] & (1 << q)) {
                    s1[nu] = '1';
                }
                if (pp[j] & (1 << q)) {
                    s1[nu + 1] = '1';
                }
                kk = (kk * 4LL + s1[nu] - '0') * 4LL + s1[nu + 1] - '0';
                p1 = (p1 * 10LL + s1[nu] - '0') * 10LL + s1[nu + 1] - '0';
                q++;
            }
            kk = kk * 4LL + 1;
            p1 = p1 * 10LL + 1;
            kk = prime(kk);
            p1 = prime(p1);
            if (kk && p1) {
                k--;
                cout << s1 << " 3 2 " << 5 << " 2 5 2 3 2 " << 11 << "\n";
            }
        }
    }
    return 0;
}

