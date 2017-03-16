#include<iostream>
#include<complex>
#include<vector>
#include<string>

#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<sstream>
#include<unistd.h>
#include<valarray>
#include<numeric>
#include<algorithm>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>

#include<fstream>
#include<time.h>
#include<unordered_set>
using namespace std;

#define NDEBUG
#include<assert.h>
#define SZ(X) ((int)X.size())
#define CLR(X) memset(X,0,sizeof(X))
#define MAX(A,B) (((A)>(B))?(A):(B))
#define MIN(A,B) (((A)<(B))?(A):(B))
#define MOD(A,B) (((A)%(B)+(B))%(B))
#define MP make_pair
#define FI first
#define SE second
#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define RFOREACH(I,C) for(VAR(I,(C).rbegin());I!=(C).rend();I++)
#define ALL(X) (X).begin(),(X).end()
#define SRT(X) sort((X).begin(),(X).end())
#define PB push_back

typedef vector<string> VS;
typedef vector<int> VI;
typedef long long ll;
typedef vector<ll> VL;

template<class T> inline string stringify(T x,int p=20){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

int k, c, s;
VL w;
int p;

#define DEB 0

void go(int off=1, int g=1, ll acc=0){
  if(g<c){
    ll acc2=(acc+(off-1))*k;
    int off2=off+1;
    if(off2>k) off2=k;
    if(DEB) cout<<"go "<<off<<" "<<g<<" "<<acc<<"\t"<<off2<<" "<<acc2<<"\n";
    go(off2, g+1, acc2);
  }else{
    p=off+1;
    w.PB(acc+off);
    if(DEB) cout<<"go end "<<off<<" "<<g<<" "<<acc<<"\t"<<p<<" "<<(acc+off)<<"\n";
  }
}



int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    cin>>k>>c>>s;
    getline(cin, line);
    w.clear();
    p=1;
    if(DEB) cout<<"in "<<k<<" "<<c<<" "<<s<<"\n";
    while(p<=k) go(p);
    
    if(SZ(w)>s) {cout<<"Case #"<<stringify(tt)<<": IMPOSSIBLE\n"; }
    else{
      string ret="Case #"+stringify(tt)+":";
      FOR(i,0,SZ(w)-1) ret+=" "+stringify(w[i]);
      cout<<ret<<"\n";
    }
  }

  return 0;
}
