#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("inp.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int t, i, j, n, m, k;
    int cases, count, ans;
    
    cases = 0;
    
    scanf("%d", &t);
    
    while(t--)
    {
        cases++;
        ans = count = 0;
        
        scanf("%d%d%d", &n, &m, &k);
        
        j = (int)sqrt(k);
        
        if ((j*j > k/2) && (j <= n) && (j <= m)) {
            ans = k - (j*j - (j*2 + 2*(j-2)));
            ans = ans - (k - (j*j));
        } else {
           int l, b;
 
           l = j;
           b = j;
           int flag = 1;
           
           do {
              if (flag) { 
                 l++;
                 flag = 0;
              } else {
                 b++;
                 flag = 1;
              } 
           } while (l*b <= k);
           
           if (flag) {
              b--;
           } else {
              l--;
           }
        
           ans = k - (l*b - (b*2 + 2*(l-2)));
           ans = ans - (k - (l*b));
        }
        printf("Case #%d: %d\n", cases, ans);
    }
    return 0;
}
