#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

#define ll long long 

int T;
int a[11];
int e, r, n;

int rec(int cur, int k, int n)
{
  int ans = 0;
  if (k == n)
    return 0;
    
  for (int i = 0; i <= cur; i++)
  {
    ans = max(ans, a[k] * i + rec(min(cur - i + r, e), k + 1, n));
  }
  
  return ans;
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  cin >> T;
  
  for (int t = 0; t < T; t++)
  {
    printf("Case #%d: ", t + 1);
    
    cin >> e >> r >> n;
    
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
      
    printf("%d\n", rec(e, 0, n));
  }
}
