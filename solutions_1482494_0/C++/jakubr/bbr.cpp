//#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<numeric>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define SIZE(x) ((int)(x).size())

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

VS parse(string s)
{
  string a;
  VS wyn;
  REP(i,(int)s.size())
    if (s[i]!=' ') a+=s[i];
    else if (!a.empty()) { wyn.PB(a); a=""; }
  if (!a.empty()) wyn.PB(a);
  return wyn;
}

int toi(char ch) { return int(ch)-int('0'); }

int chg(char ch) { return int(ch)-int('a'); }

int los(int m)
{
  return (int)((double)m*(rand()/(RAND_MAX+1.0)));
}

void wypisz(PII p)
{
  printf("(%d %d)\n",p.FI,p.SE);
}
void wypisz(VI t)
{
  REP(i,SIZE(t)) printf("%d ",t[i]); puts("");
}
void wypisz(vector<PII> t)
{
  REP(i,SIZE(t)) printf("(%d %d) ",t[i].FI,t[i].SE); puts("");
}
void wypisz(VS t)
{
  REP(i,SIZE(t)) printf("%s\n",t[i].c_str());
}
void wypisz(vector<VI> t)
{
  REP(i,SIZE(t)) wypisz(t[i]);
}


int ILE;
int n;
PII t[1010];
int bylo[1000];

void doit()
{
  int wyn=INFTY;
  REP(mask,(1<<n))
  {
    int akt=0,ruchy=0;
    REP(i,n) bylo[i]=0;
    while (1)
    {
      bool ok=0;
      REP(i,n)
      {
        if (!bylo[i] && (mask & (1<<i)) && t[i].FI<=akt)
        {
          bylo[i]=1;
          akt++; ruchy++;
          ok=1;
        } else if (bylo[i]==1 && (mask & (1<<i)) && t[i].SE<=akt)
        {
          bylo[i]=2;
          akt++; ruchy++;
          ok=1;
        } else if (!bylo[i] && !(mask & (1<<i)) && t[i].SE<=akt)
        {
          bylo[i]=2;
          akt+=2; ruchy++;
          ok=1;
        }
      }
      if (!ok) break;
    }
    bool ok=1;
    REP(i,n) if (bylo[i]!=2) { ok=0; break; }
    if (ok) wyn=min(wyn,ruchy);
  }
  if (wyn==INFTY) puts("Too Bad"); else printf("%d\n",wyn);
}

int main()
{
  scanf("%d",&ILE);
  FOR(iii,1,ILE)
  {
    printf("Case #%d: ",iii);
    fprintf(stderr,"Case #%d: \n",iii);
    scanf("%d",&n);
    REP(i,n) scanf("%d%d",&(t[i].FI),&(t[i].SE));
    sort(t,t+n);
    doit();
  }
  return 0;
}
