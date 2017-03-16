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

int tc,n,ans;
string s[100],r;
vector<int> p;
int pos[256];

inline bool ok(){
    int cur=0;
    rep(i,n) rep(j,sz(s[ p[i] ])){
        if (pos[ s[ p[i]][j]  ]!=-1 && cur!=pos[ s[ p[i]][j]  ]+1) return false;
        //cout<<s[p[i]][j];
        pos[ s[ p[i]][j]  ]=(cur++);
    }
    return true;
}

int main(){
    freopen("b.inp","r",stdin);
    freopen("b.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>tc;
    lfo(tt,1,tc){
        cin>>n;
        rep(i,n){
            s[i]="";
            cin>>r;
            s[i]+=r[0];
            lfo(t,1,sz(r)-1) if (r[t]!=r[t-1]) s[i]=s[i]+r[t];
        }
        p.clear();
        rep(i,n) p.pb(i);
        lfo(c,'a','z') pos[c]=-1;
        ans=0;
        do{
            lfo(c,'a','z') pos[c]=-1;
            ans+=ok();
            //cout<<'\n';
        } while (next_permutation(p.begin(),p.end()));
        cout<<"Case #"<<tt<<": "<<ans<<'\n';
    }
    return 0;
}
