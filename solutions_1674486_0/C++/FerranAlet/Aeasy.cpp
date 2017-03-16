//Done by Grey Matter
//Fet per Ferran Alet

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<numeric>
#include<set>
#include<sstream>
#include<list>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) //cerr << #x << " = " << x << endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;

ifstream fin("Asmall0.in");
ofstream fout("Asmall0.out");

inline void multiplica(VVI &w,VVI &v){
    int n=v.size();
    VVI aux(n,VI(n));
    FOR(i,n){
        FOR(j,n){
            FOR(k,n){
                aux[i][j]+=v[i][k]*w[k][j];
            }
        }
    }
    w=aux;
}

int main(){
//ios_base::sync_with_stdio(false);
    int casos;
    fin>>casos;
    FORU(cas,casos){
        fout<<"Case #"<<cas<<": ";
        bool b=false;
        int n;
        fin>>n;
        VVI v(n,VI(n));
        FOR(i,n){
            int m,a;
            fin>>m;
            FOR(j,m){
                fin>>a;
                --a;
                v[i][a]=1;
            }
        }
        VVI w=v;
        VVI aux=w;
        /*FOR(i,n) {
            FOR(j,n) {
                if(w[i][j]>1) b=true;
                cerr<<w[i][j]<<' ';
            }
            cerr<<endl;
        }
        cerr<<endl;
        */
        FOR(c,n+1){
            if(b) break;
            multiplica(w,v);
            FOR(i,n) {
                FOR(j,n) {
                    aux[i][j]+=w[i][j];
                    if(aux[i][j]>1) b=true;
                    //cerr<<aux[i][j]<<' ';
                }
                //cerr<<endl;
            }
           // cerr<<endl;
        }
        if(b) fout<<"Yes"<<endl;
        else fout<<"No"<<endl;
    }
    system("pause");
}
