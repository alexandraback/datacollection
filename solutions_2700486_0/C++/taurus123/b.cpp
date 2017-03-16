#include<iostream>
#include<cstdio>
using namespace std;
double f[2005][2005];
int main()
{
    int T;
    int n,x,y;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&n,&x,&y);
        int i=1;
        int tmp=1;
        while(tmp+i+1+i+2<=n)
        {
            tmp+=i+1+i+2;
            i+=2;
        }
        n-=tmp;
        bool flag=false;
        for(int j=i,k=-2*(i/2);j>=1;j--,k++)
        {
            for(int v=k,u=0;u<j;v+=2,u++)
            {
                if(x==v&&y==i-j)
                    flag=true;
            }
        }
        if(flag)
        {
            printf("Case #%d: %.8lf\n",cas,1.0);
        }
        else{
                int pos=100000000;
                for(int j=i+2,k=-2*((i+2)/2),v=2*((i+2)/2);j>=1;j--,k++,v--)
                {

                        if(x==k&&y==i+2-j)
                            pos=(y+1);
                        if(x==v&&y==i+2-j)
                            pos=y+1;
                }
                if(pos==100000000)
                {
                    printf("Case #%d: 0.0\n",cas);
                    continue;
                }

            int k=i+1;
            f[0][0]=1.0;
            for(int j=0;j<=k;j++)
                for(int v=0;v<=k;v++)
            {
                if(j+v>n)continue;
                if(j==0&&v==0)continue;
                if(j==0)
                    f[j][v]=f[j][v-1]*0.5;
                else if(v==0)
                    f[j][v]=f[j-1][v]*0.5;
                else if(j==k&&v==k)
                    f[j][v]=f[j-1][v]+f[j][v-1];
                else if(j==k)
                    f[j][v]=f[j-1][v]*0.5+f[j][v-1];
                else if(v==k)
                    f[j][v]=f[j-1][v]+f[j][v-1]*0.5;
                else
                f[j][v]=f[j-1][v]*0.5+f[j][v-1]*0.5;
            }
            double ans=0;
            for(int j=pos;j<=k;j++)
            {
                for(int v=0;v<=k;v++)
                    if(j+v==n)
                    ans+=f[j][v];
            }
            printf("Case #%d: %.8lf\n",cas,ans);
        }

    }
    return 0;
}
