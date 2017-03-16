#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pb push_back
#define y1 troly
typedef long long ll;
typedef pair <int, int> pii;
typedef double db;
const int N = 1e3 + 5;
vector <int> g[N];
int add(int x, int y)
{
  if (x + y >= 2) return 2;
  if (x + y == 1) return 1;
  return 0;
}

int n, dp[N];
int calc(int v)
{
  if (dp[v] != -1) return dp[v];
  if (g[v].size() == 0) return dp[v] = 0;
  dp[v] = 0;
  for (int i = 0; i < g[v].size(); i++)
    dp[v] = add(dp[v], calc(g[v][i]));
  return dp[v];
}

bool solve()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    g[i].clear();
  for (int i = 0;  i < n; i++)
  {
    int mi, x;
    scanf("%d", &mi);
    for (int j = 0; j < mi; j++)
    {
      scanf("%d", &x);
      g[x - 1].pb(i);
    }
  }
  for (int i = 0; i < n; i++)
  {
    memset(dp, -1, sizeof(dp));
    dp[i] = 1;
    for (int j = 0; j < n; j++)
      if (calc(j) == 2) return true;
  }
  return false;
}
int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int ts;
  cin >> ts;
  for (int i = 1; i <= ts; i++)
  {
    cout << "Case #" << i << ": ";
    if (solve()) cout << "Yes\n";
    else cout << "No\n";
  }

/*
10
9
0
2 3 4
0
0
1 2
1 7
2 8 9
0
0


25
0
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
*/
  return 0;
}
