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

int n;
vector< vector<int> > G;

void readInput()
{
  scanf("%d", &n);
  G.resize(n);
  REP(i, n)
  {
    int m;
    scanf("%d", &m);
    G[i].resize(m);
    REP(j, m)
    {
      scanf("%d", &G[i][j]);
      G[i][j]--;
    }
  }
}

vector<int> used;

bool dfs(int v)
{
  if (used[v])
    return true;
  used[v] = 1;
  REP(i, G[v].size())
  {
    int to = G[v][i];
    if (dfs(to))
      return true;
  }
  return false;
}

bool solve()
{
  REP(i, n)
  {
    used.assign(n, 0);
    if (dfs(i))
      return true;
  }
  return false;
}

void writeOutput(int t, bool ans)
{
  printf("Case #%d: ", t);
  if (ans)
    printf("Yes");
  else
    printf("No");
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
    bool res = solve();
    writeOutput(t, res);
  }

  size_t t2 = clock();
  //fprintf(stderr, "Execution time: %.3lf", double(t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
