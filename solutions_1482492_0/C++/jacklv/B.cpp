#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n,a;
double t[20],at[20],g[100];
double Dist,mv,Answer;

int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int i,j,k;
    int T;
    cin>>T;
    for (int tt=1; tt<=T; tt++)
    {
        printf("Case #%d: \n",tt);
        scanf("%lf%d%d",&Dist,&n,&a);
        for (i=1; i<=n; i++)
        scanf("%lf%lf",&t[i],&at[i]);
        for (i=1; i<=a; i++)
        scanf("%lf",&g[i]);

        if (n==1)
        {
            for (i=1; i<=a; i++)
            {
                Answer=sqrt(Dist*2/g[i]);
                printf("%.7lf\n",Answer);
            }
            continue;
        }
        mv=(at[2]-at[1])/(t[2]-t[1]);
        if (n==2&&at[n]>Dist)
        {
            t[n]=((Dist-at[1])/(at[n]-at[1]))*t[n];
            at[n]=Dist;
        }
        for (i=1; i<=a; i++)
        {
            Answer=((sqrt(mv*mv+at[1]*2*g[i])+mv)/g[i])<t[2]?t[2]:sqrt(Dist*2/g[i]);
            printf("%.7lf\n",Answer);
        }
    }
}
