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
int a[8];
int r, m, k, n;
int mas[126];
int ok;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  cin >> T;
  
  for (int t = 0; t < T; t++)
  {
    printf("Case #%d:\n", t + 1);
    
    cin >> r >> n >> m >> k;
    
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < k; j++)
      {
        scanf("%d", &a[j]);
      }
      
      for (int x = 2; x <= 5; x++)
        for (int y = 2; y <= 5; y++)
          for (int z = 2; z <= 5; z++)
          {
            
            
            for (int l = 1; l <= 125; l++)
              mas[l] = 0;
              
            mas[1] = 1;
            
            for (int mask = 1; mask < 8; mask++)
            {
              int u = 1;
              if (mask & 1)
                u *= z;
              if (mask & 2)
                u *= y;
              if (mask & 4)
                u *= x;
              mas[u] = 1;
            }
            
            ok = 1;
            
            for (int j = 0; j < k; j++)
              if (!mas[a[j]])
                ok = 0;
                
            if (ok)
            {
              printf("%d%d%d\n", x, y, z);
              goto lab;
            }
          }
      lab:;
    }
  }
}
