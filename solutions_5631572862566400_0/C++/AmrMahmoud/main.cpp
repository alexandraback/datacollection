#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

int nxt[1005], in[1005];
vector<int> g[1005];
bool v[1005];

int dfs(int node, int target, bool f)
{
  v[node] = true;
  if(node == target && !f) return 0;
  return 1 + dfs(nxt[node], target, 0);
}

int solve(int node, int parent)
{
  int ans = 0;
  for(int x : g[node])
  {
    if(x == parent) continue;
    ans = max(ans, solve(x, node));
  }
  return ans + 1;
}

int main()
{
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  for(int tt=1;tt<=t;tt++)
  {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
      in[i] = 0;
      g[i].clear();
      v[i] = false;
    }
    for(int i=0;i<n;i++)
    {
      scanf("%d", &nxt[i]);
      nxt[i]--;
      in[nxt[i]]++;
      g[nxt[i]].pb(i);
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
      if(in[i]) continue;
      q.push(i);
    }
    printf("Case #%d: ", tt);
    int ans = 0;
    while(!q.empty())
    {
      int x = q.front();
      q.pop();
      v[x] = true;
      in[nxt[x]]--;
      if(in[nxt[x]] == 0)
        q.push(nxt[x]);
    }
    int tmp = 0;
    for(int i=0;i<n;i++)
      if(!v[i])
      {
        int x = dfs(i, i, 1);
        if(x == 2)
          tmp += solve(i, nxt[i]) + solve(nxt[i], i);
        else ans = max(ans, x);
      }
    ans = max(ans, tmp);
    printf("%d\n", ans);
  }
  return 0;
}
