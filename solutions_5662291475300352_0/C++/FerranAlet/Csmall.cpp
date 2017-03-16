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
    freopen("Cnano.out","w",stdout);
    freopen("Cnano.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        DRI(n);
        vector<ll> minim,maxim;
        FOR(i,n){
            DRIII(x,H,m);
            FOR(h,H){
                minim.push_back((360LL-x)*(m+h));
                maxim.push_back((720LL-x)*(m+h));
            }
        }
        ll h = minim.size();
        ll res = 0; //Anant a tota pastilla!
        //debug(h);
        FOR(S,(1<<h)){
            //debug(S);
            vector<PII> v;
            FOR(i,h) if((S&(1<<i))!=0) {
                v.push_back(PII(minim[i],1));
                v.push_back(PII(maxim[i],0));
            }
            sort(v.begin(),v.end());
            ll pos=0;
            ll cont=__builtin_popcount (S);
            if(cont<=res) continue;
            bool primer = true;
            while(pos<v.size()){
                while(pos<v.size() && (primer or v[pos].first==v[pos-1].first)){
                    cont+=(v[pos].second==1 ? -1: 1);
                    ++pos;
                    primer = false;
                }
                primer = true;
                if(cont==0) {res=__builtin_popcount(S); /*cerr<<":) "<<endl;*/ break;}
            }
        }
        cout<<"Case #"<<cas<<": "<<ll(minim.size())-res<<endl;
    }
}
