#include <stdio.h>
#include <stdlib.h>

const int MAXN = 210;

int n;
double s[MAXN];

void init()
{
     scanf("%d", &n);
     for (int i = 0; i < n; ++i)
         scanf("%lf", &s[i]);
}

void work()
{
     double max[MAXN];
     for (int i = 0; i < n; ++i) max[i] = -1;
     double ss = 0;
     for (int i = 0; i < n; ++i)
         ss += s[i];
     double pp = ss * 2 / n;           
     bool flag = false;
     for (int i = 0; i < n; ++i)
         if (pp < s[i]) {
                max[i] = s[i];
                flag = true;
         }
     while (flag){
           int n1 = 0;
           double ss1 = ss * 2;
           for (int i = 0; i < n; ++i)
               if (max[i] >= -(1e-8)){
                  n1++;
                  ss1 -= max[i];
               }
           if (n == n1) break;
           pp = ss1 / (n - n1);
           flag = false;
           for (int i = 0; i < n; ++i)
               if (max[i] < 0 && pp < s[i]){
                      max[i] = s[i];
                      flag = true;
               }
     }
     for (int i = 0; i < n; ++i)
         if (max[i] < 0) max[i] = pp;
     for (int i = 0; i < n; ++i)
         printf("%.6lf ", (max[i] - s[i]) / ss * 100.0);
     printf("\n");
           
}
     
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int cases, i;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; ++i){
        printf("Case #%d: ", i);
        init();
        work();
    }
        
    return 0;
}
