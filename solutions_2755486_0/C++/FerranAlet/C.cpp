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
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef pair<PII,PII> atac;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;

ifstream fin("C-small.in");
ofstream fout("C-small.out");


int main(){
 // ios_base::sync_with_stdio(false);
  int casos;
  fin>>casos;
  for(int cas=1;cas<=casos;++cas){
    int n;
    fin>>n;
    vector<atac> v;
    for(int i=0;i<n;++i){
      int d,atacs,w,e,strength,delta_d,delta_p,delta_s;
      fin>>d>>atacs>>w>>e>>strength>>delta_d>>delta_p>>delta_s;
      for(int j=0;j<atacs;++j,d+=delta_d,w+=delta_p,e+=delta_p,strength+=delta_s){
        v.push_back(atac(PII(d,strength),PII(w,e)));
      }
    }
    sort(v.begin(),v.end());
    VI gw(1000); //gw[x]= alsada de la x-500
    int res=0;
    int inici=0;
    for(int i=0;i<v.size();){
   //   cerr<<i<<' '<<v[i].first.first;
      //Comprovo successful
      for(int j=i;j<v.size();++j){
        if(v[j].first.first!=v[i].first.first) break; //diferent dia bitch
        bool cool=false;
        for(int k=v[j].second.first;k<v[j].second.second && !cool;++k){
          if(gw[k+500]<v[j].first.second) cool=true;
        }
        if(cool) res++;
      }
      for(int j=i;;++j){
        if(j>=v.size() or v[j].first.first!=v[i].first.first) {//diferent dia o end bitch
          i=j;
          break; 
        }
        for(int k=v[j].second.first;k<v[j].second.second;++k){
          gw[k+500]=max(gw[k+500],v[j].first.second);
        }
      }
      //cerr<<' '<<res<<endl;
    }
    fout<<"Case #"<<cas<<": "<<res<<endl;
  }
  system("pause");
}  
