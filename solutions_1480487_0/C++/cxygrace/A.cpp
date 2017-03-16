#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 210;
const double eps = 1e-10;
int dat[maxn], n, s;
bool check(int x, double y)
{
     double sum = y, p = dat[x] + s*y;
     int c = 0;
     for (int i=0; i<n; i++)
     {
         if (i==x) continue;
         if (p>dat[i]) sum += (p-dat[i])/s;
         else c++;
     }
     return (c+1<n) && sum>=1;
}
void init()
{
     scanf("%d", &n);
     for (int i=0; i<n; i++) scanf("%d", dat+i);
}
void work()
{
     s = 0;
     for (int i=0; i<n; i++) s += dat[i];
     double left, right, mid;
     for (int i=0; i<n; i++)
     {
         left = 0; right = 1;
         while (left+eps<right)
         {
               mid = (left+right)/2;
               if (check(i, mid)) right = mid; else left = mid;
         }
         printf(" %.7lf", right*100);
     }
     printf("\n");
}
int main()
{
    int test;
    scanf("%d", &test);
    for (int i=1; i<=test; i++)
    {
        init();
        printf("Case #%d:", i);
        work();
    }
    return 0;
}
