//Done by Ferran Alet

#include<bits/stdc++.h>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) //cerr << #x << " = " << x << endl
#define Debug(v) //cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define DEBUG(M) //cerr << #M <<":"<<endl; for(int iM=0;iM<M.size();++iM) { for(int jM=0;jM<M[iM].size();++jM) cerr<<M[iM][jM]<<' '; cerr<<endl;} cerr<<endl
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
    //freopen("B-small-sol-big.out","w",stdout);
    freopen("B-large-sol.out","w",stdout);
    //freopen("B-small-attempt0.in","r",stdin);
    freopen("B-large.in","r",stdin);
    //freopen("rank_sample.in","r",stdin);
    DRI(casos);
    FORU(cas,casos){
        debug(cas);
        DRI(n);
        VVI v(2*n-1,VI(n));
        FOR(i,2*n-1){
            FOR(j,n) cin>>v[i][j];
        }
        VB pillat(2*n-1,false);
        int res = -1;
        int tipus = 0;
        VVI T(n, VI(n));
        FOR(i,n){
            debug(i);
            int minim = INF;
            VI sol;
            cerr<<'a'<<endl;
            FOR(j,2*n-1){
                if(pillat[j]) continue;
                if(v[j][i]<minim) sol.clear();
                minim = min(minim,v[j][i]);
                if(v[j][i]==minim) sol.push_back(j);
            }
            cerr<<'b'<<endl;
            if(sol.size()==1) res = i;
            //Encaixo com a fila? :)
            bool b = true;
            FOR(j,i){
                if(T[i][j]!=v[sol[0]][j]) b = false;
            }
            //cerr<<'c'<<endl;
            //debug(sol.size());
            FOR(i,sol.size()) pillat[sol[i]] = true;
            if(b){ //El 0 es una fila --> desaparegut es columna
                //cerr<<"HIHI"<<endl;
                /*debug(T[i].size());
                debug(T.size());
                debug(sol[0]);
                debug(v[sol[0]].size());
                debug(sol[1]);
                debug(v[sol[1]].size());*/
                FOR(j,n) T[i][j] = v[sol[0]][j];
                if(sol.size()==1) tipus = 0;
                else FOR(j,n) T[j][i] = v[sol[1]][j];
                cerr<<"HAHA"<<endl;
            }
            else{
                cerr<<"HIHI!"<<endl;
                debug(T[i].size());
                debug(T.size());
                debug(sol[0]);
                debug(v[sol[0]].size());
                debug(sol[1]);
                debug(v[sol[1]].size());
                FOR(j,n) T[j][i] = v[sol[0]][j];
                if(sol.size()==1) tipus = 1;
                else FOR(j,n) T[i][j] = v[sol[1]][j];
                cerr<<"HAHA!"<<endl;
            }
        }
        debug(res);
        debug(tipus);
        DEBUG(T);
        cerr<<"HEY"<<endl;
        cout << "Case #"<<cas<<": ";
        VI solu, sold;
        FOR(i,n) solu.push_back(T[res][i]);
        FOR(i,n) sold.push_back(T[i][res]);
        bool bu = false, bd= false;
        FOR(j,2*n-1) if(solu==v[j]) bu=true;
        FOR(j,2*n-1) if(sold==v[j]) bd=true;
        if(!bu) FOR(i,n) {if(i) cout <<' '; cout <<solu[i];}
        else FOR(i,n) {if(i) cout <<' '; cout <<solu[i];}
        cout <<endl;
    }
}
