#include <bits/stdc++.h>
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
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

bool pres[2600];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int ncas; cin >> ncas;
    forn(cas, ncas) {
        cout << "Case #" << cas+1 << ": ";
        int n; cin >> n;
        memset(pres,0,sizeof pres);
        forn(_,2*n-1) forn(_,n) {
            int x; cin >> x;
            pres[x] = !pres[x];
        }
        vector<int> res;
        forn(i,2600) if (pres[i]) res.pb(i);
        forn(i,n) {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}
