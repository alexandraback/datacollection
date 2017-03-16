/*
 * This is my code,
 * my code is amazing...
 */
//Template v3.0 alfa 1 
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define pll pair<ll,ll>
#define pld pair<lld,lld>
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define INF 1000000000000000047
const char en='\n';
#define prime 47
#define lprime 1000000000000000009
#define lldmin LDBL_MIN
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define FOR(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);i--)
#define REP(i,b) for(ll i=0;i<(ll)(b);i++)
#define FORE(i,b) for(auto i=(b).begin(); i!=(b).end(); i++)
#define sqr(a) (a)*(a)
#define dst(a,b) sqr((a).ff-(b).ff)+sqr((a).ss-(b).ss)
#define mdst(a,b) abs((a).ff-(b).ff)+abs((a).ss-(b).ss)
//debug
#define debug 1
#define dbg(x) if(debug) cout<<#x<<"="<<(x)<<";"<<endl;
using namespace std;

template <class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>&par) {
  out<<"("<<par.ff<<", "<<par.ss<<") ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  REP(i, v.size()){if(i) out<<" ";cout<<v[i];}
  return out;
}







int main(){
	ios::sync_with_stdio(false);
        cin.tie(0);

        int T;
        cin>>T;
        FOR(t,1,T){
            cout<<"Case #"<<t<<": ";
        
            int a,b,c,kk;
            cin>>a>>b>>c>>kk;
            vpll V;
            FOR(i,1,a)FOR(j,1,b)
                V.PB(MP(i,j));
            sort(V.begin(),V.end());

	    vector<pair<pll,ll>>naj;
            //cout<<"zacinam"<<endl;
            //cout<<V.size()<<endl;
            do{
                //cout<<"vector"<<endl;
                //cout<<V<<endl;
                REP(i,V.size()){

                    map<pll,ll>A,B,C;
                    vector<pair<pll,ll>>R;
                    FOR(ii,0,V.size()-1)FOR(k,1,c){
                        int i=V[ii].ff,j=V[ii].ss;
                        if(A[MP(i,j)]==kk || B[MP(j,k)]==kk || C[MP(i,k)]==kk)continue;
                        R.PB(MP(MP(i,j),k));
                        //cout<<i<<" "<<j<<" "<<k<<en;
                        A[MP(i,j)]++;
                        B[MP(j,k)]++;
                        C[MP(i,k)]++;
                    }

                    if(R.size()>naj.size()){
                        naj=R;
                    }
                }




            }while(next_permutation(V.begin(),V.end()));
        
        
            cout<<naj.size()<<en;
            REP(i,naj.size()){
                cout<<naj[i].ff.ff<<" "<<naj[i].ff.ss<<" "<<naj[i].ss<<endl;
            } 
        
        
        
        }






}
