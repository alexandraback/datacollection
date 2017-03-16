#include <stdio.h>
#include <algorithm>

using namespace std;

int a[110], b[110];
int A, n;

 int main()
 {
//   freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("aout.txt", "w", stdout);
     int cas, T;
     int i, s, ans, cur;
     scanf("%d", &T);
     for (int cas=1; cas<=T; cas++)
     {
         scanf("%d%d", &A, &n);
         for (i=0; i<n; i++)
         {
             scanf("%d", &a[i]);
         }
         sort(a, a+n);
         if (A == 1)
         {
             printf("Case #%d: %d\n", cas, n);
             continue;
         }
         s = A;
         ans = 0;
         for (i=0; i<n; i++)
         {
             b[i] = 0;
             while (s<=a[i])
             {
                 s += s - 1;
                 b[i]++;
                 ans++;
             }
             s += a[i];
         }
         cur = ans;
         for (i=n-1; i>=0; i--)
         {
             cur = cur - b[i] + 1;
             if (cur < ans) ans = cur;
         }
         printf("Case #%d: %d\n", cas, ans);
     }
     return 0;
 }
