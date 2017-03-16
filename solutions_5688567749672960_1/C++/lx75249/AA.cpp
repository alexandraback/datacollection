#include <cstdio>
#include <iostream>
using namespace std;

typedef unsigned long long ull;
ull reverse(ull n)
{
  ull ans = 0;
  for(; n; n/=10)
    ans = ans*10+(n%10);
  return ans;
}

int length(ull n)
{
  int ans = 0;
  for(;n;n/=10)
    ++ans;
  return ans;
}

ull dfs(ull n)
{
  if (n < 20) return n;
  int l = length(n);
  ull half = 1;
  for(int i=1; i<=l>>1; ++i)
    half *= 10;
  ull right = n % half;
  ull from = reverse(n-right+1);
  if (right && from != n)
    return dfs(from)+right-(from == reverse(from)?1:0);
  return dfs(n-1)+1;
}

int main()
{
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  int T;
  cin >> T;
  for(int i=1; i<=T; ++i)
  {
    ull N;
    cin >> N;
    printf("Case #%d: %llu\n", i, dfs(N));
  }
}
