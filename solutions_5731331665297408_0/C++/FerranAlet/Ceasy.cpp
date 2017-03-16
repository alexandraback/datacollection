//Done by Mycroft Grey
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
#define Debug(v) cerr << #v << " = "; for(int wow=0;wow<v.size();++wow) cerr<<v[wow]<<' '; cerr<<endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
#define RFOR(x,y) for(int x=y-1;x>=0;--x)
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;

VVB G;
/*VI papi;

VI millor (int pos,bool ok){ //posicio, pare, bitmask necessitaré papi??
  VI res;
  ok=false;
  for(int i=0;i<n;++i){
    if(i==papi[pos]){ //Si és el meu papi puc tornar
      
    }
    else if(papi[i]==-1 && G[pos][i]){ //Si no està visitat
    }
  }
}
*/
int main(){
//  ios_base::sync_with_stdio(false);
  freopen("Csmall.out","w",stdout);
  freopen("Csmall.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    int n,m;
    cin>>n>>m;
    vector<pair<string,int> > aux(n);
    FOR(i,n) cin>>aux[i].first;
    FOR(i,n) aux[i].second=i;
    sort(aux.begin(),aux.end());
    VI conv(n);
    FOR(i,n) conv[aux[i].second]=i;
    G = VVB (n,VB(n,false));
    int a,b;
    FOR(i,m){
      cin>>a>>b;
      a=conv[a-1]; b=conv[b-1];
      G[a][b]=G[b][a]=true;
    }
    VI perm(n);
    FOR(i,n) perm[i]=i;
    cout<<"Case #"<<cas<<": ";
    do{
      stack<int> papi;
      papi.push(perm[0]);
      bool nop=false;
      for(int pos=1;pos<n;++pos){
        while(!papi.empty() && !G[papi.top()][perm[pos]]) papi.pop();
        if(papi.empty()) {nop=true; break;}
        papi.push(perm[pos]);
      }
      if(!nop){
        FOR(i,n) cout<<aux[perm[i]].first;
        cout<<endl;
        break;
      }
    }while(next_permutation(perm.begin(),perm.end()));
    /*FOR(i,n){
      papi= VI(n,-1);
      bool ok=true;
      VI sol = millor(i,0,ok);
    }*/
  }
}
