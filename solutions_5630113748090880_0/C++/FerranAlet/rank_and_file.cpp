//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) cerr << #M <<":"<<endl; for(int iM=0;iM<M.size();++iM) { for(int jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORS(x,y) for(int x=0;x<int(y.size());++x)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
#define DRI(x) int x; cin>>x
#define DRII(x,y) int x,y; cin>>x>>y
#define DRIII(x,y,z) int x,y,z; cin>>x>>y>>z
#define PB push_back
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;
typedef vector<VP> VVP;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("B-small-sol.out","w",stdout);
    freopen("B-small-attempt0.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        debug(cas);
        cout << "Case #"<<cas<<": ";
        DRI(n);
        VVI v(2*n-1,VI(n));
        FOR(i,2*n-1){
            FOR(j,n) cin>>v[i][j];
        }
        sort(v.begin(),v.end());
        //DEBUG(v);
        VI real_sol;
        VVI test_cols = {{1,2,3,6},{3,4,8,9},{7,8,10,12},{9,10,12,15}};
        FOR(S,1<<(2*n-1)){
            int uns = 0;
            FOR(k,(2*n-1)) if((S&(1<<k))!=0) ++uns;
            if(uns!=n) continue;
            //debug(uns);
            //cerr<<'a'<<endl;
            VVI cols(n, VI(n));
            int f = 0;
            FOR(k,2*n-1){
                if((S&(1<<k))!=0){
                    FOR(j,n){
                        cols[j][f] = v[k][j];
                    }
                    ++f;
                }
            }
            //debug(f);
            //DEBUG(cols);
            //cerr<<'b'<<endl;
            f = 0;
            bool liat = false;
            VI sol;
            FOR(k,2*n-1){
                if((S&(1<<k))==0){
                    bool b = true;
                    //cerr<<k<<" vs "<<v.size()<<endl;
                    FOR(j,n){
                        if(cols[f][j]!=v[k][j]) b = false;
                    }
                    if(!b) {
                        if(sol.size()==0) sol = cols[f];
                        else {
                            liat = true;
                            break;
                        }
                        --k;
                    }
                    ++f;
                }
            }
            if(!liat){
                if(sol.size()==0) real_sol = cols[f];
                else real_sol = sol;
            }
        }
        //Debug(real_sol);
        //cerr<<'c'<<endl;
        FOR(i,n){
            if(i) cout <<' ';
            cout << real_sol[i];
        }
        cout<<endl;
    }
}
