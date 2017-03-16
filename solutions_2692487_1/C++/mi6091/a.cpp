#include <iostream>
using namespace std;

int p, n,a[105];

int solve ()
{
    
    scanf ("%d%d", &p, &n);
    
    int i;
    for (i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    if (p == 1)
       return n;
    
    sort (a, a+n);
    
    int res = n;
    int j, k;
    for (i = 0; a[i] < p && i < n; i ++)
        p += a[i];
    
    for(j = i; j <= n; j ++)
    {
          int temp = n - j;
          
          long long ta = p;
          for (k = i ; k < j ; k ++)
          {
              while (ta <= a[k])
                    ta += ta - 1, temp ++;
              ta += a[k];
              if (temp > res)
                 break; // simple optimization :)      
          }
          
          res = min (res, temp);
    }
    
    
    
    return res;
}
int main ()
{
 
    int t;
    scanf ("%d", &t);
    
    for (int i = 1; i <= t; i++)
    {
        printf ("Case #%d: %d\n", i, solve ());
    }   
    
    return 0;
    
}
