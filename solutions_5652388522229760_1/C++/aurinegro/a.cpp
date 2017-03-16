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

const int N = 1e6 + 10;

int sol[N];
bool seen[10];

int total;
void paint(int n) {
    while (n) {
        int d = n%10;
        if (!seen[d]) {
            total++;
            seen[d] = true;
        }
        n /= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    forsn(i,1,N) {
        fill_n(seen,10,0); total = 0;
        for (int x = i; total < 10; x += i) {
            sol[i] = x;
            paint(x);
        }
    }

    int ncas; cin >> ncas;
    forn(cas, ncas) {
        cout << "Case #" << cas+1 << ": ";
        int n; cin >> n;
        if (n == 0) cout << "INSOMNIA\n";
        else cout << sol[n] << '\n';
    }
    return 0;
}
