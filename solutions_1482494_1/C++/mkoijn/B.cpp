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

typedef vector<int> VI;

typedef map<int,VI> mt;
int N, N2;
int da[2100];
int ev[1100];
mt m1s, m2s;

inline void dod1s(int k, int p){
  mt::iterator it=m1s.find(k);
  if(it==m1s.end()){
    VI t;
    t.PB(p);
    m1s[k]=t;
  } else{
    m1s[k].PB(p);
  }
}

inline void dod2s(int k, int p){
  mt::iterator it=m2s.find(k);
  if(it==m2s.end()){
    VI t;
    t.PB(p);
    m2s[k]=t;
  } else{
    m2s[k].PB(p);
  }
}

inline int ex1(int k){
  mt::iterator it=m1s.find(k);
  if(it==m1s.end()){
    return 0;
  } else return 1;
}
inline int ex2(int k){
  mt::iterator it=m2s.find(k);
  if(it==m2s.end()){
    return 0;
  } else return 1;
}

int ac=0;

inline int znajdz2(){
  int r1=-1;
  FOR(i,0,ac){
    if(ex2(i)){
      int n=SZ(m2s[i]);
      FOR(j, 0, n-1){
        if(ev[m2s[i][j]]==0){
          return m2s[i][j];
        } else if(ev[m2s[i][j]]==1){
          r1=m2s[i][j];
        }
      }
    }
  }
  return r1;
}

inline int znajdz1(){
  int r=-1;
  int m=-1;
  FOR(i,0,ac){
    if(ex1(i)){
      int n=SZ(m1s[i]);
      FOR(j, 0, n-1){
        if(ev[m1s[i][j]]==0){
          if(da[2*m1s[i][j]+1]>m) {
            m=da[2*m1s[i][j]+1];
            r=m1s[i][j];
          }
        }
      }
    }
  }
  return r;
}

int main(){
  int T;
  cin>>T;
  FOR(t,1,T){
    int ret=0;
    int bad=0;
    m1s.clear(); m2s.clear();
    CLR(ev);
    cin>>N;
    N2=N;
    ac=0;
    REP(i, N) {
      cin>>da[2*i]>>da[2*i+1];
      dod1s(da[2*i],i);
      dod2s(da[2*i+1],i);
    }
    while(N2){
//      cout<<"gw "<<ac<<endl;
      int x=znajdz2();
      if(x<0){
        x=znajdz1();
//        cout<<"1: "<<(x+1)<<"  ac: "<<ac<<endl;
        if(x<0){bad=1; break;}
        ev[x]=1;
        ret++;
        ac++;
      } else {
//        cout<<"2: "<<(x+1)<<"  ac: "<<ac<<endl;
        ac+=2-ev[x];
        ev[x]=2;
        ret++;
        N2--;
      }
    }
    if(bad) cout<<"Case #"<<t<<": Too Bad"<<endl; else cout<<"Case #"<<t<<": "<<ret<<endl;
  }
  return 0;
}
