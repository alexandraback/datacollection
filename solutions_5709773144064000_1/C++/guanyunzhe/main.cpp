#include<cstdio>
#include<iostream>
#include<cmath>
#define dsp 1e-8
using namespace std;

double c, f, x;

double times(int x)
{
    return c/(2 + (x-1)*f);
}

int main(void)
{
    #ifdef LOCAL
        freopen("B-large.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif // LOCAL
    int ncase;
    scanf("%d",&ncase);
    int v = 0;
    while(ncase--)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        double flag = (x-c)/c - 2/f;
        int n = (int)ceil(flag);
        double ans = 0;
        for(int i = 1; i <= n; ++i)
            ans += times(i);
        ans += ( x/(2+n*f));
        if(x <= c)
            ans = x/2;
        cout<<"Case #"<<++v<<": ";
        printf("%.7lf\n",ans);
    }
    return 0;
}
