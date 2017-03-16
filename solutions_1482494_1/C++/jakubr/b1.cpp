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
bool bylo[1010];

VI A,B;

void doit()
{
  REP(i,n) bylo[i]=0;

  A.clear(); B.clear();

  int akt=0,poz=0,ruchy=0;
  while (poz<n || !A.empty() || !B.empty())
  {
    while (poz<n && t[poz].FI<=akt)
    {
      A.PB(poz);
      poz++;
    }
    REP(i,SIZE(A)) if (t[A[i]].SE<=akt) { swap(A[i],A.back()); B.PB(A.back()); A.pop_back(); i--; }

    bool ok=0;
    REP(i,SIZE(B)) if (t[B[i]].SE<=akt)
    {
      if (bylo[B[i]]) akt++; else akt+=2;
      ++ruchy;
      swap(B[i],B.back());
      B.pop_back();
      i--;
      ok=1;
    }

    if (!ok)
    {
      int mi=-1,mii=-1;
      REP(i,SIZE(A)) if (t[A[i]].SE>mi) { mi=t[A[i]].SE; mii=i; }
      if (mii!=-1)
      {
        akt++;
        ++ruchy;
        bylo[A[mii]]=1;
        B.PB(A[mii]);
        A.erase(A.begin()+mii);
      } else { puts("Too Bad"); return; }
    }
  }
  printf("%d\n",ruchy);
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
