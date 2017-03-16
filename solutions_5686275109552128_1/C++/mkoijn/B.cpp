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

typedef vector<int> VI;

template<class T> inline string stringify(T x,int p=9){ostringstream o;o.precision(p);o<<x;o.flush();return o.str();}
inline VI parsei(string s,char ch=' '){string a="";VI wyn;REP(i,(int)s.size()) if(s[i]!=ch) a+=s[i];else if(!a.empty()){wyn.PB(atoi(a.c_str()));a="";} if(!a.empty()) wyn.PB(atoi(a.c_str()));return wyn;}

inline int CEIL(int a,int b){return a%b?a/b+1:a/b;}

inline int sqrtint(int x){
  int ret=sqrt(x);
  int x2=ret+1;
  if(x2*x2==x) ret=x2;
  return ret;
}

int main(){
  int T;
  cin>>T;
  string line;
  getline(cin, line);
  FOR(i,1,T){
    getline(cin, line);
    getline(cin, line);
    VI x=parsei(line);
    SRT(x);
    int n=SZ(x);
    int ret=x[n-1];
    int k=sqrtint(ret);
    int p=CEIL(ret,k);
    int p2=CEIL(ret,2);
    if(n>1 && x[n-2]>p2) p2=x[n-2];
    if(p*k<ret) p++;
    int q=0;

    for(int j=p; j<=p2; j++){
      for(; q<n; q++) if(x[q]>j) break;
      int ret2=j;
      for(int jj=q; jj<n; jj++){
        int pom=CEIL(x[jj],j)-1;
        ret2+=pom;
      }
      if(ret2<ret) ret=ret2;
    }
    cout<<"Case #"<<stringify(i)<<": "<<stringify(ret)<<"\n";
  }

  return 0;
}
