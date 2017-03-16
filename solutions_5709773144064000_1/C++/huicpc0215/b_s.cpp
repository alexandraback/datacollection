#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double ans,c,f,x,tm,rt;
#define eps 1e-8

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("b_l.out","w",stdout);
    int t;scanf("%d",&t);
    int casecnt=1;
    while(t--)
    {
        printf("Case #%d: ",casecnt++);
        scanf("%lf%lf%lf",&c,&f,&x);
        ans = x * 0.5; rt = 2.0;
        tm = c / rt ; rt += f;
        while( tm + x/rt < ans )
        {
            ans = tm + x/rt ;
            tm += c/rt ; rt +=f;
        }
        printf("%0.7lf\n",ans);
    }
    return 0;
}
