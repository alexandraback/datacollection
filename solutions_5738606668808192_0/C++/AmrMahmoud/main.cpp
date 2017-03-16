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

int n, k;

vector<int> primes;

void get_primes(int MAX)
{
  bool visited[MAX + 10];
  setzero(visited);
  for(int x = 2; x <= MAX; x++)
    if(!visited[x])
    {
      primes.push_back(x);
      for(LL j = x * 1LL * x; j <= MAX; j += x)
        visited[j] = true;
    }
}

void solve(int ind, string s)
{
  if(!k) return;
  if(ind == n)
  {
    vector<int> d;
    for(int i=2;i<=10;i++)
    {
      for(int prime : primes)
      {
        int v = 0;
        for(int j=0;j<n;j++)
        {
          v = v * i + s[j] - '0';
          v %= prime;
        }
        if(v == 0)
        {
          d.pb(prime);
          break;
        }
      }
      if(d.size() != i - 1) return;
    }
    k--;
    printf("%s", s.c_str());
    for(int i=0;i<9;i++)
      printf(" %d", d[i]);
    printf("\n");
    return;
  }
  if(ind == 0 || ind == n - 1)
  {
    solve(ind + 1, s + "1");
    return;
  }
  solve(ind + 1, s + "0");
  solve(ind + 1, s + "1");
}

int main()
{
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t;
  cin >> t;
  get_primes(1000);
  for(int tt=1;tt<=t;tt++)
  {
    cin >> n >> k;
    printf("Case #%d:\n", tt);
    solve(0, "");
  }
  return 0;
}
