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

//const int N = 16, J = 50;
const int N = 32, J = 500;

int rnd(int n) { return rand() % n; }
int rnd(int a, int b) { return a + rnd(b-a); }
int rndPair(int a, int b, int &x, int &y) {
    x = rnd(a,b);
    y = rnd(a,b-1);
    if (y >= x) y++;
    if (x > y) swap(x,y);
}

void gen(vi &a, vi &b) {
    int last = rnd(N/2,N);
    int x,y; rndPair(1,last,x,y);
    a = {0,x,y,last};
    b = {0,N-1-last};
}

ll pot[11][N], cnt[2*N+2];
bool check(vi &a, vi &b, vector<bool> &c) {
    memset(cnt,0,sizeof cnt);
    for (int x : a) for (int y : b) 
        if (++cnt[x+y] > 1) return false;
    c.resize(N);
    forn(i,N) c[i] = cnt[i];
    return true;
}

map<vector<bool>,vi> res;

void print(vector<bool> &prod, vi &b) {
    for (int i = N-1; i >= 0; --i) cout << prod[i];
    forsn(base,2,11) {
        ll d = 0;
        for (int y : b) d += pot[base][y];
        cout << ' ' << d;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    srand(42);

    forn(b,11) {
        pot[b][0] = 1;
        forsn(i,1,N) pot[b][i] = pot[b][i-1]*b;
    }

    cout << "Case #1:\n";
    vi a,b;
    vector<bool> c;
    while (si(res) < J) {
        gen(a,b);
        if (check(a,b,c)) res[c] = b;
    }
    for (auto &cb : res) {
        tie(c,b) = cb;
        print(c,b);
    }
    return 0;
}
