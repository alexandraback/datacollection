#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define x first
#define y second
#define PB push_back
#define REP(i,n) for (int i = 0; i < int(n); ++i)
#define FORE(i,a,b) for (int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef queue<int> Q;
typedef priority_queue<int> PQ;

template <class Ta, class Tb> inline Tb cast(Ta a) {stringstream ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const ll INF = 1000000000000000000LL;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int n, m;

int fmem[500];
int f(int k) { //solve k straight
    int ans = k;
    if (fmem[k]!=-1) return fmem[k];
    for (int a=1;a<=n;++a) for (int b=1;b<=m;++b) {
        if (a>1 and b>1) { //forma go-style
            int ret = 2*(a-2) + 2*(b-2);
            if (k <= a*b-4) {
                ans=min(ans, ret);
                //cerr << "can cover " << k << " with go " << a << ", " << b << " -> " << ret << endl;
            }
            if (k <= a*b-3) ans=min(ans, ret+1);
            if (k <= a*b-2) ans=min(ans, ret+2);
            if (k <= a*b-1) ans=min(ans, ret+3);
        }
        if (k <= a*b) {
            if (a==1 and b==1) ans=min(ans, 1);
            else ans=min(ans, 2*a+2*b-4); //full rectangle
        }
    }
    return fmem[k]=ans;
}

int mem[500];

int dp(int k) {
    if (k==0) return 0;
    int &ans = mem[k];
    if (ans!=-1) return ans;
    ans = k;
    for (int i=1;i<=k;++i) {
        ans=min(ans, f(i) + dp(k-i));
    }
    return ans;
}

int main() {
    int t; cin >> t;
    for (int cas=1; cas<=t;++cas) {
        cout << "Case #" << cas << ": ";
        int k;
        cin >> n >> m >> k;
        memset(fmem,-1,sizeof(fmem));
        memset(mem,-1,sizeof(mem));
        int ans = dp(k); //single zone
        cout << ans << endl;
    }
}
