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
#define PB push_back
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}
const long double EPS=10e-9;

typedef long double ld;
typedef vector<int> VI;
#define DEBUG 0
    ld s[205];
    ld p[205];
    int N;
    
inline VI dop(ld q){
  VI ret;
  ld m=1000000000;
  REP(i, N){
    if(s[i]>q){
      if(s[i]==m){
        ret.PB(i);
      } else if(s[i]<m){
        m=s[i];
        ret.clear();
        ret.PB(i);
      }
    }
  }
      if(DEBUG){  cout<<"dop ("<<(double)m<<", "<<(double)q<<"):"; wypisz(ret);cout<<"\n";}
  return ret;
}

inline VI dm(){
  VI ret;
  ld m=1000000000;
  REP(i, N){
      if(s[i]==m){
        ret.PB(i);
      } else if(s[i]<m){
        m=s[i];
        ret.clear();
        ret.PB(i);
      }
  }
      if(DEBUG){  cout<<"dm ("<<(double)m<<"):"; wypisz(ret);cout<<"\n";}
  return ret;
}

int main(){
  int T;
  cin>>T;
  FOR(t,1,T){
    cin>>N;
    ld x=0;
    REP(i,N) {cin>>s[i]; x+=s[i]; p[i]=0;}
    ld y=0;
          if(DEBUG){
    cout<<"ping\n";
REP(i, N) cout<<(double)s[i]<<" ";
    cout<<"\n";
REP(i, N) cout<<(double)p[i]<<" ";
        cout<<"\n\n";}
    while(y<1-EPS){
      VI m=dm();
      if(SZ(m)==N){
        ld q=(1-y)/N;
        REP(i, N){
          p[i]+=q;
        }
        break;
      } else {
        VI m2=dop(s[m[0]]);
        ld dif=s[m2[0]]-s[m[0]];
      if(DEBUG)        cout<<"dif1 "<<(double)dif<<endl;
        ld q=dif/x; //proc dla 1
      if(DEBUG)                cout<<"q "<<(double)q<<endl;
        ld q2=MIN(q*SZ(m), 1-y); //suma proc rzecz dla wszystkich
      if(DEBUG)                cout<<"q2 "<<(double)q2<<endl;
        q=q2/SZ(m); //proc rzecz dla 1
      if(DEBUG)                cout<<"q "<<(double)q<<endl;
        y+=q2;
        dif=q*x;//przyr rzecz dla 1
      if(DEBUG)                cout<<"dif2 "<<(double)dif<<endl;
        REP(i, SZ(m)) {s[m[i]]+=dif; p[m[i]]+=q;}
      }
      if(DEBUG){
    cout<<"ping\n";
REP(i, N) cout<<(double)s[i]<<" ";
    cout<<"\n";
REP(i, N) cout<<(double)p[i]<<" ";
        cout<<"\n\n";
      }
    }
    printf("Case #%d:", t);
    REP(i, N) printf(" %.7lf",(double)(100*p[i]));
    printf("\n");
//    cout<<"Case #"<<t<<": "<<ret<<endl;
  }
  return 0;
}

