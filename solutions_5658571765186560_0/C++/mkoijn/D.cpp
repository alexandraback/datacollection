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
int X, R, C;

inline bool test(int q){
  bool ret=false;
  for(int i=0; i<=C-R-1; i++){
    int a=i*R, b=(C-R-1-i)*R;
    a+=q*(R-1);
    b+=(R-q)*(R-1);
    if(a%X==0&&b%X==0){
      ret=true;
      break;
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
    VI x=parsei(line);
    X=x[0], R=x[1], C=x[2];
    if(R>C) swap(R,C);
    bool bad=false;
    if(X>=8) bad=true;
    if(X>C) bad=true;
    if(X>=2*R+1) bad=true;
    if((R*C)%X!=0) bad=true;
    if(!bad&&R>1&&C>R&&X==2*R){
      for(int i=0; i<=R; i++){
        if(!test(i)){
          bad=true;
          break;
        }
      }
    }
    cout<<"Case #"<<stringify(tt)<<": "<<(bad?"RICHARD":"GABRIEL")<<"\n";
  }

  return 0;
}
