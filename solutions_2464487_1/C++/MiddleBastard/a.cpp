#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

#define ll unsigned long long 

int T;
ll r, m;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  cin >> T;
  
  
  for (int t = 0; t < T; t++)
  {
    printf("Case #%d: ", t + 1);
    cin >> r >> m;
    
    ll x = 0;
    ll y = (1000000001LL);
    
    while (x + 1 < y)
    {
      ll z = (x + y) / 2;
      
      if (2 * r > (m + z - 1) / z || z * (2 * z - 1) > m || 2 * r * z + z * (2 * z - 1) > m)
        y = z;
      else
        x = z;
    }
    
    cout << x << endl;
  }
}
