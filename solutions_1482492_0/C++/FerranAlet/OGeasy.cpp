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
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;

ifstream fin("BSS.in");
ofstream fout("BSS.out");

int main(){
//ios_base::sync_with_stdio(false);
    int cases;
    fin>>cases;
    FORU(cas,cases){
        fout<<"Case #"<<cas<<":"<<endl;
        double d;
        fin>>d;
        int n,A;
        fin>>n>>A;
        //fout<<A<<endl;
        VD p(n),temps(n);
        FOR(i,n) fin>>temps[i]>>p[i];
        //Recalcular últims valors!!!!!
        FOR(i,n){   
            if(p[i]>d){
    //            cerr<<p[n-1]<<' '<<d<<" !!!!!"<<endl;
                if(i>1)  temps[i]=temps[i-1]+((d-p[i-1])/(p[i]-p[i-1]))*(temps[i]-temps[i-1]);
                else temps[i]=((d)/(p[i]))*(temps[i]);
                p[i]=d;
                n=i;
    //            cerr<<"Nou temps";
               // fout<<fixed;
               // fout<<setprecision(9)<<temps[n-1]<<endl;
               // debug(temps[n-1]);
            }
        }
        VD acc(A);
        FOR(i,A) fin>>acc[i];
        //Recordar idea
        //sort(acc.begin(),acc.end());
        FOR(ai,A){
            double pv=0.,pd=p[0];
            for(int i=1;i<n;++i){
                //Puc arribar
                double t=temps[i]-temps[i-1];
                double vc=(p[i]-p[i-1])/t;
                if(pv*t+0.5*acc[ai]*t*t>=pd+vc*t){
                    pd=0.;
                    pv=vc;
                }
                else{
                    pd=pd+vc*t-pv*t-t*t*0.5*acc[ai];
                    pv=pv+acc[ai]*t;
                }
            }
            if(pd<EPS){
                fout<<fixed;
//                cerr<<"           !!";
                fout<<setprecision(9)<< temps[n-1]<<endl;
            }
            else{
                double ttt=(sqrt((2*acc[ai]*pd+pv*pv))-pv)/acc[ai];
                debug(ttt);
                fout<<fixed;
//                cerr<<"              ";
                fout<<setprecision(9)<< temps[n-1]+ttt<<endl;
            }
        }
    }
    system("pause");
}
