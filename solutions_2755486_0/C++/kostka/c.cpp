#include<cstdio>
#include<algorithm>
#include<vector>
 
using namespace std;

typedef struct{
  int d, s, w, e, n;
}atak;

const int UJE = 10000;
const long long MAXN = 10000000007;
static long long tab[20007];
static vector <atak> X;

void zmien(int p, int k, long long ile)
{
  for(int i=p; i<k; i++)
    tab[i] = max(tab[i], ile);
}

bool cmp(atak a, atak b)
{
  if(a.d==b.d)
    return a.n<b.n;
  return a.d<b.d;
}

int wynik(int p, int k)
{
  long long wyn = MAXN;
  for(int i=p; i<k; i++)
    wyn = min(wyn, tab[i]);
  return wyn;
}

int solve()
{
  int n;
  scanf("%d", &n);
  while(n--)
  {
    int piedzi, ataki, we, ea, si, ddzi, dpor, dsil, li=0;
    scanf("%d%d%d%d%d%d%d%d", &piedzi, &ataki, &we, &ea, &si, &ddzi, &dpor, &dsil);
    we += UJE;
    ea += UJE;
    for(int i=0; i<ataki; i++)
    {
      atak tmp;
      tmp.d = piedzi;
      tmp.s = si;
      tmp.w = we;
      tmp.e = ea;
      tmp.n = li++;
      X.push_back(tmp);
      piedzi += ddzi;
      si += dsil;
      we += dpor;
      ea += dpor;
    }
  }
  sort(X.begin(), X.end(), cmp);
  int res = 0;
  for(int i=0; i<X.size(); i++)
  {
    int wsk = i;
    while(i+1<X.size() && X[i].d == X[i+1].d)
    {
      if(wynik(X[i].w, X[i].e) < X[i].s)
	res++;
      i++;
    }
    if(wynik(X[i].w, X[i].e) < X[i].s)
	res++;
    i = wsk;
    while(i+1<X.size() && X[i].d == X[i+1].d)
    {
      zmien(X[i].w, X[i].e, X[i].s);
      i++;
    }
    zmien(X[i].w, X[i].e, X[i].s);
  }
  X.clear();
  for(int i=0; i<20007; i++)
    tab[i] = 0;
  return res;
}

int main()
{
  int t;
  scanf("%d", &t);
  for(int ti=1; ti<=t; ti++)
    printf("Case #%d: %d\n", ti, solve());
  return 0;
}
