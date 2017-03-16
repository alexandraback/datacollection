#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
const int maxn = 100000;
double dat[maxn];
int n, a;
void init()
{
     scanf("%d%d", &a, &n);
     for (int i=0; i<a; i++) scanf("%lf", dat+i);
}
double work()
{
     double res = n+2, now = 1;
     for (int i=0; i<a; i++)
     {
         res = min(res, a-i-i+n+1+(1-now)*(n+1));
         now *= dat[i];
     }
     res = min(res, n-a+1+(1-now)*(n+1));
     return res;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        init();
        printf("Case #%d: %.8lf\n", i, work());
    }
    return 0;
}
