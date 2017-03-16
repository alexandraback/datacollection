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
int n,m,a,b,c,d;
const int MXN = 20;
char buf1[MXN];
char buf2[MXN];
bool pasuje(int x,char *buf)
  {
  FORD(i,n,1)
    {
    if(buf[i] != '?' && buf[i] - '0' != x%10)
      {
//      cerr<<x<<" "<<buf+1<<" "<<i<<endl;
      return 0;
      }
    x/=10;
    }
//  cerr<<x<<" "<<buf+1<<endl;
  return 1;
  }
void solve()
  {
  map<string,int> M[2];
  
  scanf("%d",&n);
  vector<pair<string, string> > V, res;
  REP(i, n)
    {
    pair<string,string> s;
    cin>>s.f>>s.s;
    M[0][s.f]++;
    M[1][s.s]++;
    V.PB(s);
    }
  int ress = 0;
  REP(ii, 10000)
    {
    REP(i, V.size())
      {
      auto it = V[i];
      if(M[0][it.f] > 1 && M[1][it.s] > 1)
        {
        M[0][it.f]--;
        M[1][it.s]--;
        res.PB(it);
        V.erase(V.begin() + i);
        i--;
        }      
      }
    maxi(ress, (int)res.size());
    REP(i, res.size())
      {
      V.PB(res[i]);
      M[0][res[i].f]++;
      M[1][res[i].s]++;
      }
    res.clear();
    random_shuffle(ALL(V));
    }
  printf("%d\n",(int)ress);
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
