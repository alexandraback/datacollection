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

template<class T> inline string stringify(T x,int p=16){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VS parse(string s,char ch=' '){string a;VS wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(a);a="";} if(!a.empty()) wyn.PB(a);return wyn;}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

inline
string comp(const string &x){
  string ret="";
  int n=SZ(x);
  if(n>0){
    char c=x[0];
    ret+=c;
    FOR(i,1,n-1){
      if(x[i]!=c){
        c=x[i];
        ret+=c;
      }
    }
  }
  return ret;
}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(tt,1,T){
    getline(cin, line);
    string q=comp(line);
    int n=SZ(q);
    int ret=n;
    if(q[n-1]=='+') ret--;
    cout<<"Case #"<<stringify(tt)<<": "<<stringify(ret)<<"\n";
  }

  return 0;
}
