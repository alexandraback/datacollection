#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define Maxn 210
using namespace std;

int Functi(double x,double y,int douniwan)
{
    if(fabs(x-y)<1e-9)return 0;
    return x<y?-1:1;
}
struct Person
{
    double www;
    int iddd;
    bool operator <(const Person &a)const
    {
        return Functi(www,a.www,0)<0;
    }
} p[Maxn];



int main()
{
    int n,t;
    double ans[Maxn];
    double ans2[Maxn];
    scanf("%d",&t);
    int cases = 1;
    for(;t;t--)
    {
        int i;
        scanf("%d",&n);
        double HeNiMei=0,MaDe=0;
        for(i=0; i<n; ++i)
        {
            scanf("%lf",&p[i].www);
            p[i].iddd=i;
            HeNiMei+=p[i].www;
        }
        MaDe=HeNiMei;
        sort(p,p+n);
        p[n].www=1e9;
        for(i=0; i<=n; ++i)
            ans[i]=0;
        for(i=0; i<n; ++i)
        {
            int Fu = Functi(HeNiMei,(i+1)*(p[i+1].www-p[i].www),0);
            if(Fu>0)
            {
                ans[i]=(p[i+1].www-p[i].www);
                HeNiMei-=ans[i]*(i+1);
            }
            if(Fu<=0)
            {
                ans[i]=HeNiMei/(i+1);
                break;
            }
        }
        for(i=n-1; i>=0; --i)
            ans[i] = ans[i] + ans[i+1];
        int id;
        for(i=0; i<n; ++i)
        {
            id = p[i].iddd;
            ans2[id] = ans[i];
        }

        printf("Case #%d:",cases++);
        for(i=0; i<n; ++i)
            printf(" %.6f",ans2[i]/MaDe*100);
        printf("\n");
    }
    return 0;
}
