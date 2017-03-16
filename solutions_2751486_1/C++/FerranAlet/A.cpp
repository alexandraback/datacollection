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
typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;

ifstream fin("a-large.in");
ofstream fout("a-large.out");


int main(){
 // ios_base::sync_with_stdio(false);
  int casos;
  fin>>casos;
  for(int cas=1;cas<=casos;++cas){
    cerr<<cas<<endl;
    string s; int n;
    fin>>s>>n;
    int m=s.size();
    VB vb(m);
    VI l(m,-1);
    int cons=0;    
    for(int i=m-1;i>=0;--i){
      if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u') cons++;
      else cons=0;
      if(cons>=n) vb[i]=true;
      else vb[i]=false;
    }
    int last=-1;
    for(int i=0;i+n-1<m;++i){
      if(vb[i]) last=i;
      l[i+n-1]=last;
    }
    long long res=0;
    for(int i=0;i<m;++i)res+=l[i]+1; //un poc lol
    fout<<"Case #"<<cas<<": "<<res<<endl;
    //for(int i=0;i<m;++i) cerr<<vb[i]<<' ';
   // cerr<<endl;
   // for(int i=0;i<m;++i) cerr<<l[i]<<' ';
  //  cerr<<endl;
  //  cerr<<endl<<endl<<endl;
  }
  system("pause");
}  
