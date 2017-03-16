#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define lfo(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define rfo(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define lfoe(i,v) for(typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define st first
#define nd second
#define pb push_back
#define sz(s) (int)(s.size())

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b) { T r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
typedef unsigned long long ll;
typedef pair<ll,ll> II;
const int oo=int(1e9)+7;
const int dx[]={1,0,0,-1};
const int dy[]={0,-1,1,0};
const int N=int(1e6)+10;

int n,m,k,tc,p[22],cnt,ans;
int minr[22],maxc[22],maxr[22],minc[22],dem[1<<20|1];

int main(){
    freopen("c.inp","r",stdin);
    freopen("c.out","w",stdout);
    ios_base::sync_with_stdio(false);
    p[0]=1;
    lfo(i,1,21) p[i]=p[i-1]*2;
    rep(i,p[20]) dem[i]=__builtin_popcount(i);
    cin>>tc;
    lfo(tt,1,tc){
        cin>>n>>m>>k;
        ans=n*m;
        for(int s=0,pp=n*m;s<p[pp];++s){
            rep(i,n) minr[i]=22,maxr[i]=-1;
            rep(i,m) minc[i]=22,maxc[i]=-1;
            //memset(maxc,-1,sizeof maxc);
            //memset(maxr,-1,sizeof maxr);
            //rep(i,22) minc[i]=minr[i]=22;
            rep(i,n) rep(j,m) if (s&p[i*m+j]){
                minr[i]=min(minr[i],j);
                maxr[i]=max(maxr[i],j);
                minc[j]=min(minc[j],i);
                maxc[j]=max(maxc[j],i);
            }
            cnt=0;
            rep(i,n) rep(j,m) if (minr[i]<=j && j<=maxr[i] && minc[j]<=i && i<=maxc[j]) cnt++;
            if (cnt>=k) ans=min(ans,dem[s]);
        }
        cout<<"Case #"<<tt<<": "<<ans<<'\n';
    }
    return 0;
}
