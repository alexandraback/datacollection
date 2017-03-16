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
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;
typedef vector<PII > VP;

VVI res; 
ll A,B,C;

ll calc(int pos, ll S){ //0 si són = 1LL si més petit
  //cerr<<pos<<' '<<S<<endl;
  if(pos==-1LL) return 1LL;
  if(res[pos][S]!=-1LL) return res[pos][S];
  res[pos][S]=0;
  //000
  ll SS=S;
  if(((1LL<<pos)&A)!=0) SS|=1LL; if(((1LL<<pos)&B)!=0) SS|=2; if(((1LL<<pos)&C)!=0) SS|=4;
  res[pos][S]+=calc(pos-1LL,SS);
  //001LL
  if(((1LL<<pos)&A)!=0 or (S&1LL)!=0) {
    SS=S;
    if((1LL<<pos)&B) SS|=2; if((1LL<<pos)&C) SS|=4;
    res[pos][S]+=calc(pos-1LL,SS);
  }
  //01LL0
  if(((1LL<<pos)&B)!=0 or (S&2)!=0) {
    SS=S;
    if((1LL<<pos)&A) SS|=1LL; if((1LL<<pos)&C) SS|=4;
    res[pos][S]+=calc(pos-1LL,SS);
  }
  //1LL1LL1LL
  if( (((1LL<<pos)&C)!=0 or (S&4)!=0) and (((1LL<<pos)&A)!=0 or (S&1LL)!=0) and (((1LL<<pos)&B)!=0 or (S&2)!=0)) {
    SS=S;
    res[pos][S]+=calc(pos-1LL,SS);
  }
  return res[pos][S];
}

int main(){
//  ios_base::sync_with_stdio(false);
  freopen("Bsmall.out","w",stdout);
  freopen("Bsmall.in","r",stdin);
  int casos;
  cin>>casos;
  FORU(cas,casos){
    cin>>A>>B>>C;
    --A; --B; --C;
    res = VVI(40,VI(10,-1));
    cout<<"Case #"<<cas<<": "<<calc(35,0)<<endl;
  }
 // system("pause");
}
