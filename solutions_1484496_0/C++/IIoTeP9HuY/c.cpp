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

int n;
vector<int> S;
void readInput()
{
  scanf("%d", &n);
  S.resize(n);
  REP(i, n)
  {
    scanf("%d", &S[i]);
  }
}

int maskSum(int mask)
{
  int pow2 = 1;
  int res = 0;
  REP(i, n)
  {
    if (mask & pow2)
      res += S[i];
    pow2 <<= 1;
  }
  return res;
}

vector<int> getMaskNums(int mask)
{
  vector<int> res;
  int pow2 = 1;
  REP(i, n)
  {
    if (mask & pow2)
      res.push_back(S[i]);
    pow2 <<= 1;
  }
  return res;
}

int can[6000000];

vector<int> ans1;
vector<int> ans2;

int solve()
{
  memset(can, 0, sizeof(can));
  int pow2 = 1 << n;
  for(int mask = 0; mask < pow2; mask++)
  {
    int sum = maskSum(mask);
    if (can[sum])
    {
      ans1 = getMaskNums(can[sum]);
      ans2 = getMaskNums(mask);
      return 1;
    }
    can[sum] = mask;
  }
  return 0;
}

void writeOutput(int t, int res)
{
  printf("Case #%d:", t);
  if (res == 0)
  {
    printf(" Impossible\n");
    return;
  }
  printf("\n");
  REP(i, ans1.size())
  {
    if (i)
      printf(" ");
    printf("%d", ans1[i]);
  }
  printf("\n");
  REP(i, ans2.size())
  {
    if (i)
      printf(" ");
    printf("%d", ans2[i]);
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
    int res = solve();
    writeOutput(t, res);
  }

  size_t t2 = clock();
  //fprintf(stderr, "Execution time: ", double(t2 - t1) / CLOCKS_PER_SEC);
	return 0;
}
