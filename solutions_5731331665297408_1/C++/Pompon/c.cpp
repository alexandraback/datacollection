#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,p,k) for(int i=(p); i<=(k); ++i)

enum { n_max = 60 };

typedef long long LL;
typedef bool Graph[n_max][n_max];

int P[n_max]={};
int Z[n_max]={};
bool cmp(int i, int j){ return Z[i]<Z[j]; }

struct Go
{
  int n;
  std::vector<int> R,S,V; 
  Graph G={};

  void go(int _n)
  {
    n = _n;
    V.resize(n);
    S.push_back(P[0]); V[S.back()] = 1; R.push_back(S.back());
    while(1)
    {
      REP(i,n) if(!V[P[i]])
      {
        std::vector<int> S2 = S;
        int v = P[i];
        while(S.size()>1 && !G[S.back()][v] && reachable()) S.pop_back();
        if(G[S.back()][v]){ S.push_back(v); R.push_back(v); V[v] = 1; break; }
        else S = S2;
      }
      int c = 0; REP(i,n) c += V[i];
      if(c==n) break;
    }
  }

  bool reachable()
  {
    std::vector<int> Q=S; Q.pop_back();
    std::vector<int> W=V;
    while(Q.size())
    {
      int v = Q.back(); Q.pop_back();
      REP(i,n) if(G[v][i] && !W[i])
      { Q.push_back(i); W[i] = 1; }
    }
    REP(i,n) if(!W[i]) return 0;
    return 1;
  }
};

int main()
{
  int t; scanf("%d",&t);
  FOR(_,1,t)
  {
    
    int n,m; scanf("%d%d",&n,&m);
    
    REP(i,n) scanf("%d",&Z[i]);
    REP(i,n) P[i] = i;
    std::sort(P,P+n,cmp);
    
    Go go;
    REP(i,m)
    {
      int a,b; scanf("%d%d",&a,&b); a--; b--;
      go.G[a][b] = go.G[b][a] = 1;
    }
    go.go(n);
    
    printf("Case #%d: ",_);
    REP(i,n) printf("%d",Z[go.R[i]]);
    puts("");
  }
  return 0;
}

