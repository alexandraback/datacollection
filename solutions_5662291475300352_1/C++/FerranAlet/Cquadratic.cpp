//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(ll wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) cerr << #M <<":"<<endl; for(ll iM=0;iM<M.size();++iM) { for(ll jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
#define FOR(x,y) for(ll x=0;x<y;x++)
#define FORS(x,y) for(ll x=0;x<ll(y.size());++x)
#define FORU(x,y) for(ll x=1;x<=y;x++)
#define RFOR(x,y) for(ll x=y-1;x>=0;--x)
#define DRI(x) ll x; cin>>x
#define DRII(x,y) ll x,y; cin>>x>>y
#define DRIII(x,y,z) ll x,y,z; cin>>x>>y>>z
#define PB push_back
#define SZ(X) ((ll)(X).size())
#define ALL(X) (X).begin(), (X).end()

using namespace std;

typedef long long ll;
typedef pair<ll,ll> PII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<string> VS;
typedef map<ll,ll> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;
typedef vector<VP> VVP;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("Csmall2.out","w",stdout);
    freopen("Csmall2.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        debug(cas);
        DRI(n);
        vector<ll> minim,maxim;
        FOR(i,n){
            DRIII(x,H,m);
            FOR(h,H){
                FOR(cops,10){
                    if(cops==0) minim.push_back((360LL-x)*(m+h));
                    else minim.push_back(-1);
                    maxim.push_back((360LL*(cops+2LL)-x)*(m+h));
                }
            }
        }
        vector<PII> v;
        FOR(i,minim.size()) {
            v.push_back(PII(minim[i],1));
            v.push_back(PII(maxim[i],0));
        }
        sort(v.begin(),v.end());
        ll pos=0;
        bool primer = true;
        ll res = INF;
        ll cont= minim.size();
        while(pos<v.size()){
            while(pos<v.size() && (primer or v[pos].first==v[pos-1].first)){
                cont+=(v[pos].second==1 ? -1: 1);
                ++pos;
                primer = false;
            }
            primer = true;
            res = min(res,cont);
        }
        cout<<"Case #"<<cas<<": "<<res<<endl;
    }
}
