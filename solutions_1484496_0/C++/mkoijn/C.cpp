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
#define CLC(ACT,V) (*({ACT;static __typeof(V) ret;ret=(V);&ret;}))
#define FIRST(P,A,B,COND) CLC(VAR(P,A);for(;P<(B);++P)if(COND)break,P)
#define LAST(P,A,B,COND) CLC(VAR(P,B);while((A)<=(--P))if(COND)break,P)
#define EXISTS(P,A,B,COND) (FIRST(P,A,B,COND)<(B))
#define FORALL(P,A,B,COND) (!(EXISTS(P,A,B,!(COND))))
#define EXISTSI(I,C,COND) CLC(VAR(I,(C).begin());for(;I!=(C).end();I++)if(COND)break,I)!=(C).end()
#define FORALLI(I,C,COND) (!(EXISTSI(I,C,!(COND))))
#define PB push_back
#define PF(I,V) V.insert(V.begin(),I)
#define EB(V) V.erase(V.rbegin());
#define EF(V) V.erase(V.begin());
#define SGN(X) (((X)>0)?1:(((X)<0)?-1:0))
#define LD(X) ((ld)(X))
#define LL(X) ((ll)(X))
#define BIT_CHECK(X,N) (X&(1<<N))
#define BIT_SET(X,N) (X|=(1<<N))
#define BIT_CLEAR(X,N) (X&=~(1<<N))
#define BIT_TOGGLE(X,N) (X^=(1<<N))
#define BIT_LOWEST(X) (__builtin_ffsll((unsigned long long)X))
#define BIT_COUNT(X) (__builtin_popcountll((unsigned long long)X))
template<class T> inline void wypisz(const T& x){FOREACH(I,x)cout<<*I<<" ";cout<<endl;}

const long long INFTY=(long long)(2147483647)*(long long)(2147483647)*(long long)2;
const int INF=0x7f7f7f7f;
const long double EPS=10e-12;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> VI;


int main(){
  int T;
  cin>>T;
  FOR(t,1,T){
    int N;
    cin>>N;
    int tx;
    VI s;
    REP(i,N) {cin>>tx; s.PB(tx);}
    int m=0;
    map<ll,int> q;
    while(m<(2<<N)){
      ll w=0;
      REP(i, N){
        if(BIT_CHECK(m,i)) w+=s[i];
      }
      if(q.find(w)!=q.end()){
        cout<<"Case #"<<t<<":\n";
        REP(i, N-1) if(BIT_CHECK(q[w],i)) cout<<s[i]<<" ";
        if(BIT_CHECK(q[w],(N-1))) cout<<s[N-1];
        cout<<endl;
        REP(i, N-1) if(BIT_CHECK(m,i)) cout<<s[i]<<" ";
        if(BIT_CHECK(m,(N-1))) cout<<s[N-1];
        cout<<endl;
        goto nast;
      } else {
        q[w]=m;
//        cout<<"wpis "<<m<<" s "<<w<<endl;
      }
      m++;
    }
    cout<<"Case #"<<t<<":\nImpossible\n";
nast:;
  }
  return 0;
}

