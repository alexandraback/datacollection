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
#include <unordered_map>
#include <map>
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

int n, m;
vector<int> A, B;
vector<long long> a, b;

void readInput()
{
  scanf("%d%d", &n, &m);
  a.resize(n);
  A.resize(n);
  REP(i, n)
  {
    cin >> a[i] >> A[i];
  }
  b.resize(m);
  B.resize(m);
  REP(i, m)
  {
    cin >> b[i] >> B[i];
  }
}

map< pair<pair<int, int> , pair<long long, char> >, long long> DP;

long long calcDP(int l, int r, long long left, char lane)
{
  if (l == n || r == m)
    return 0;
  if (left == 0)
  {
    if (lane == 0)
      return calcDP(l + 1, r, a[l + 1], lane);
    else
      return calcDP(l, r + 1, b[r + 1], lane);
  }
  if (DP.find(mp(mp(l, r), mp(left, lane))) != DP.end())
    return DP[mp(mp(l, r), mp(left, lane))];
  
  if (A[l] != B[r])
  {
    if (lane == 0)
    {
      long long res1 = calcDP(l + 1, r, a[l + 1], lane);
      long long res2 = calcDP(l, r + 1, left, lane);
      return max(res1, res2);
    }
    else
    {
      long long res1 = calcDP(l + 1, r, left, lane);
      long long res2 = calcDP(l, r + 1, b[r + 1], lane);
      return max(res1, res2);
    }
  }
  else
  {
    long long add = 0;
    if (lane == 0)
    {
      add = min(left, b[r]);
      if (left > b[r])
      {
        return calcDP(l, r + 1, left - b[r], lane) + add;
      }
      else
      {
        return calcDP(l + 1, r, b[r] - left, 1 - lane) + add;
      }
    }
    else
    {
      add = min(left, a[l]);
      if (left > a[l])
      {
        return calcDP(l + 1, r, left - a[l], lane) + add;
      }
      else
      {
        return calcDP(l, r + 1, a[l] - left, 1 - lane) + add;
      }
    }
  }
}

long long solve()
{
  long long res = 0;
  DP.clear();
  res = calcDP(0, 0, a[0], 0);
  return res;
}

void writeOutput(int t, long long res)
{
  printf("Case #%d: ", t);
  cout << res;
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
    long long res = solve();
    writeOutput(t, res);
  }

  size_t t2 = clock();
  //fprintf(stderr, "Execution time: ", double(t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
