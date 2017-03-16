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
int jest=0;
//graphs
template<class V, class E> struct Graph {
  struct Ed:E{int v;Ed(E p,int w):E(p),v(w){}};
  struct Ve:V,vector<Ed>{};
  vector<Ve> g;
  Graph(int n=0):g(n){}
  void write(){REP(x,SZ(g)){cout<<x<<":";FOREACH(I,g[x])cout<<" "<<I->v;cout<<endl;}}
  void EdgeD(int b,int e,E d=E()){g[b].PB(Ed(d,e));}
  void EdgeU(int b,int e,E d=E()){Ed eg(d,e);eg.rev=SZ(g[e])+(b==e);g[b].PB(eg);eg.rev=SZ(g[eg.v=b])-1;g[e].PB(eg);}
  void Bfs(int s){FOREACH(I,g)I->t=I->s=-1;g[s].t=0;int qu[SZ(g)],b,e;qu[b=e=0]=s;while(b<=e){s=qu[b++];FOREACH(I,g[s])if(g[I->v].t==-1){g[qu[++e]=I->v].t=g[s].t+1;g[I->v].s=s;}else{jest=1;}}}
  int MaxFlow(int s,int f){int res=0,n=SZ(g);vis.resize(n);itL.resize(n);out=f;REP(x,n)FOREACH(I,g[x])I->f=0;int q[n],b,e;while(1){REP(x,n)vis[x]=-1,itL[x]=g[x].begin();for(q[vis[s]=b=e=0]=s;b<=e;++b)FOREACH(I,g[q[b]])if(vis[I->v]==-1&&I->c>I->f)vis[q[++e]=I->v]=vis[q[b]]+1;if(vis[f]==-1)break;res+=FlowDfs(s,INF);}return res;}int FlowDfs(int x,int fl){int r=0,f;if(x==out||!fl)return fl;for(typename vector<Ed>::iterator &I=itL[x];I!=g[x].end();++I){if(vis[x]+1==vis[I->v]&&I->c-I->f){I->f+=f=FlowDfs(I->v,MIN(fl,I->c-I->f));g[I->v][I->rev].f-=f;r+=f;fl-=f;if(!fl)break;}}return r;}int out;vector<typename vector<Ed>::iterator> itL;VI vis;
};
/* wierzcholek dla: BFS */
struct Vs{int t,s;};
/* krawedz dla: nieskierowanych */
//struct Ve{int rev;};
/* krawedz dla: maxflow(nieskierowane) */
struct Ve {int rev, c, f;};
/* krawedz i wierzcholek gdy nie potrzeba wzbogacania */
struct Empty{};


int main(){
  int T;
  cin>>T;
  FOR(t,1,T){
    jest=0;
    int N, M;
    cin>>N;
    Graph<Vs,Ve> g(N);
    
    REP(i,N){
      cin>>M;
      REP(j,M){
        int K;
        cin>>K;
        g.EdgeD(i,K-1);
      }
    }
    REP(i,N) {g.Bfs(i); if(jest) break;}
    if(jest) cout<<"Case #"<<t<<": Yes\n"; else cout<<"Case #"<<t<<": No\n";
//    cout<<"Case #"<<t<<":\nImpossible\n";
    //printf(" %.7lf",(double)(100*p[i]));
//nast:;
  }
  return 0;
}

