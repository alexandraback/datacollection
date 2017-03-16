#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define VVI vector<VI>
using namespace std;
int n;
const int N = 4000;
vector<int> V[N*2];
char odw[N*2];
int X[N*2];
bool skojarz(int x)
  {
  odw[x]=1;
  REP(i,V[x].size())
    if(!X[V[x][i]]||(!odw[X[V[x][i]]]&&skojarz(X[V[x][i]])))
    {
    X[V[x][i]] = x;
    X[x] = V[x][i];
    return 1;
    }
  return 0;
  }
void addedge(int x,int y)
  {
  V[x].PB(y);
  V[y].PB(x);
  } 
int calc(VI kol)
  {
  int wyn=0;
  bool ok=0;
  while(1)
    {
    ok=0;
    REP(i,kol.size())odw[kol[i]]=0;
    REP(i,kol.size())
      {
      if(X[kol[i]]==0&&skojarz(kol[i]))
        {
        ok=1;
        wyn++;
        }
      }
    if(!ok)break;
    }
  return wyn;
  } 
void clear()
  {
  
  FOR(i,1,n*3)
    {
    V[i].clear();
    X[i] = 0;
    odw[i] = 0;
    }
  }
  
void solve()
  {
  map<string,int> M[2];
  scanf("%d",&n);
  vector<pair<string, string> > V, res;
  int ID = 1;
  VPII VV;
  VI kol;
  VI kol2;
  REP(i, n)
    {
    pair<string,string> s;
    int x, y;
    cin>>s.f>>s.s;
    if(M[0].count(s.f))x = M[0][s.f];
    else 
      {
      x = M[0][s.f] = ID++;
      kol.PB(x);
      }
    
    if(M[1].count(s.s))y = M[1][s.s];
    else 
      {
      y = M[1][s.s] = ID++;
      kol2.PB(y);
      }
    
    addedge(x, y);
    VV.PB(MP(x,y));
    }
  int x = calc(kol);
  REP(i, kol.size())
    {
    if(!X[kol[i]])x++;
    }
  REP(i, kol2.size())
    {
    if(!X[kol2[i]])x++;
    }
  printf("%d\n",n-x); 
  clear();
  }
main()
{
int z;
scanf("%d",&z);
FOR(iii,1,z)
  {
  printf("Case #%d: ",iii);
  solve();
  }
}
