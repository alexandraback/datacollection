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
int r, m;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  cin >> T;
  
  
  for (int t = 0; t < T; t++)
  {
    printf("Case #%d: ", t + 1);
    cin >> r >> m;
    int ans = 0;
    
    while (m >= 0)
    {
      m -= (r + 1) * (r + 1) - r * r;
      r += 2;
      ans++;
    }
    
    printf("%d\n", ans - 1);
  }
}
