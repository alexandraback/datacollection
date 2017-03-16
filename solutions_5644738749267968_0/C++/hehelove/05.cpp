#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
double f1[1010],f2[1010];
int has[1010];
int main()
{
    int T,i,j,cas=0,n;
    //freopen("D-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf",&f1[i]);
        for(i=0;i<n;i++)
        scanf("%lf",&f2[i]);
        sort(f1,f1+n);
        sort(f2,f2+n);
        int su=0;
        for(i=0;i<n;i++)
        {
            int bia=1;
            for(j=0;j<n;j++)
            if(f1[i]>f2[j])
            {
                bia=0;break;
            }
            if(bia)
            {
                su++;
            }
            else break;
        }
        memset(has,0,sizeof has);
        int sum=0;
        for(i=su;i<n;i++)
        {
            for(j=n-su-1;j>=0;j--)
            if(has[j]==0&&f1[i]>f2[j])
            {
                has[j]=1;
                sum++;
                break;
            }
        }
        int suu=0;
        memset(has,0,sizeof has);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(has[j]==0&&f1[i]<f2[j])
                {
                    has[j]=1;
                    suu++;
                    break;
                }
            }
        }
        printf("Case #%d: %d %d\n",++cas,sum,n-suu);
    }
    return 0;
}
