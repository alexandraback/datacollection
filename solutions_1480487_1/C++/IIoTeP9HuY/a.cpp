#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <cassert>
#include <math.h>
#include <vector>
#include <time.h>
#include <set>
#include <queue>
#define REP(i,n) for(int i=0, _n=(n); i<_n; i++)
#define REPD(i,n) for(int i=n-1; i>=0; i--)
#define FOR(i,a,b) for(int i=a,_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=a,_b=(b); i>=_b; i--)
#define FILL(x, v) memset(&x,v,sizeof(x))
#define DB(x) cout << #x << ": " << x << endl;
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long LL;

const int MAXN = 100;
const int MAXM = 100;
const int MAXK = 100;
const double eps = 1e-6;

vector<int> s;
int n, sum;

void readInput()
{
  scanf("%d", &n);
  s.resize(n);
  sum = 0;
  REP(i, n)
  {
    scanf("%d", &s[i]);
    sum += s[i];
  }
}

bool good(double m, int who)
{
  double score = s[who] + sum * m;
  double need = 0.0;
  REP(i, n)
  {
    if (i == who)
      continue;
    if (score > s[i])
      need += (score - s[i]) / sum;
  }
  return (need > 1 - m);
}


vector<double> ans;

void solve()
{
  ans.resize(n);
  REP(i, n)
  {
    double l = 0;
    double r = 1;
    for(int k = 0; k < 100; k++)
    {
      double m = (l + r) / 2;
      if (good(m, i))
        r = m;
      else
        l = m;
    }
    ans[i] = l * 100;
  }
}

void writeOutput(int t)
{
  printf("Case #%d:", t);
  REP(i, n)
  {
    printf(" %.9lf", ans[i]);
  }
  printf("\n");
}

int main()
{
	freopen("input.txt","r", stdin); 
  freopen("output.txt","w", stdout);
  size_t t1 = clock();

  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++)
  {
    readInput();
    solve();
    writeOutput(t);
  }

  size_t t2 = clock();
  //fprintf(stderr, "Execution time: %.3lf", double(t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
