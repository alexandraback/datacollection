#include <bits/stdc++.h>
using namespace std;
#define MEM(a) memset(a,0,sizeof(a))
#define rp(i,a,n) for ( i=a;i<n;i++)
#define pr(i,a,n) for ( i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define IT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MAX 105000
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<ll> vll;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int dr[8] = {1,1,0,-1,-1,-1, 0, 1};
int dc[8] = {0,1,1, 1, 0,-1,-1,-1};
int dh[4] = {0, 1, 0, -1};
int dv[4] = {-1, 0, 1, 0};
ll p[100][100];
void solve(int yy)
{
    ll b,m; cin>>b>>m;//cout<<b<<' '<<m<<endl;
    ll i,j,k;
    cout<<"Case #"<<yy<<":";
    if(b==2&&m>1){cout<<" IMPOSSIBLE"<<endl; return;}
    if(b==2&&m==1) { cout<<" POSSIBLE"<<endl<<"01"<<endl<<"00"<<endl;return ;}
    if(m>(((b-1)*(b-2))/2+1)) {cout<<" IMPOSSIBLE"<<endl; return;}
    cout<<" POSSIBLE"<<endl;MEM(p);
    ll sm=m-1;
    p[0][b-1]=1;

    rp(i,1,b-1)
    {
        if(sm==0) break;
        if(sm>=i)
        {
            rp(j,0,i) p[j][i]=1;
            p[j][b-1]=1;
            sm-=i;
        }
        else
        {
            rp(j,0,sm) {p[j][i]=1; p[i][b-1]=1;}
            sm=0;
        }


    }
        rp(i,0,b) {rp(j,0,b) cout<<p[i][j];cout<<endl;}
return ;
}
int main()
{
freopen("in.in","r",stdin);
  freopen("out.txt","w",stdout);
    int t,y;cin>>t;
    rp(y,1,t+1) solve(y);
    return 0;
}
