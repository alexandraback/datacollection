#include<bits/stdc++.h>
using namespace std;

double speed[1005][1005],T,d[1005],h[1005];
long long int m[1005];
int i,n,j,t,X,cnt;

double min(double a,double b)
{
    if(a-b<0.0)
        return a;
    return b;
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        X++;
        T=1000000000000000.00;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%f %f %f",&d[i],&h[i],&m[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<h[i];j++)
                speed[i][j]=((double)(360.0)/(j+m[i]));
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<h[i];j++)
            {
                T=min(T,j+m[i]+(((double)(360.0-d[i]))/speed[i][j]));
            }
        }
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<h[i];j++)
            {
                if(speed[i][j]*T+d[i]<360)
                    cnt++;
            }
        }

        printf("Case #%d: %d\n",X,cnt);
    }
return 0;
}
