#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
#define pb push_back
#define MP make_pair
#define fi  first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)
#define SZ(X) ((int)(v).size())
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define READ freopen("a.in","r",stdin);freopen("a.out","w",stdout)
void read(string t)
{
    freopen((t+".in").c_str(),"r",stdin);
    freopen((t+".out").c_str(),"w",stdout);
}
const int inf = 0x3f3f3f3f;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef pair<int,int> pii;
template <class T>
void Max(T &a, T b) { a=max(a, b); }
ll f(ll a)
{
    ll c=0;
    for (;a ; a/=10) c=c*10+a%10;
    return c;
}
const int N = 1000100;
bool vis[N];
int d[N];
void bfs(ll n=0)
{
    queue<ll> q;
    memset(vis, 0, sizeof vis);
    memset(d, 63, sizeof d);
    q.push(1);
    d[1]=1;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        if (u>=N) break;
        ll v = f(u);
        if (v<N && d[v]==inf) {
            d[v]=d[u]+1;
            q.push(v);
        }
        v = u+1;
        if (v<N && d[v]==inf) {
            d[v]=d[u]+1;
            q.push(v);
        }
    }
}
int main()
{
    READ;
    ll n;
    int re, ca=1;
    bfs();
    cin>>re;

    while(re--) {
        cin>>n;
        printf("Case #%d: %d\n", ca++, d[n]);
    }
}
