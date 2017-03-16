#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

double x[1010],y[1010];

bool cmp(double a,double b)
{
    return a<b;
}

int main()
{
    freopen("4.txt","r",stdin);
    freopen("44.out","w",stdout);
    int T,n,s1,c1,c2,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);

        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));

        for(int i=0;i<n;i++)
            scanf("%lf",&x[i]);
        for(int j=0;j<n;j++)
            scanf("%lf",&y[j]);
        if(n==1)
        {
            if(y[0]>x[0])
                printf("Case #%d: 0 0\n",cas++);
            else printf("Case #%d: 1 1\n",cas++);
            continue;
        }
        sort(x,x+n,cmp);
        sort(y,y+n,cmp);

        c1 = 0,c2=0,s1=0;
        int v = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=v;j<n;j++)
            {
                if(y[j]>x[i])
                {
                    c1++;
                    v = j+1;
                    break;
                }
            }
        }
        s1 = n-c1;

        int t=0;
        for(int i=0;i<n;i++)
        {
            for(int j=t;j<n;j++)
            {
                if(x[j]>y[i])
                {
                    c2++;
                    t = j+1;
                    break;
                }
            }
        }
        printf("Case #%d: %d %d\n",cas++,c2,s1);
    }
    return 0;
}
