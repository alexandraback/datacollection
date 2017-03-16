#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#define mod 1000000007
using namespace std;

int num[10],a[10],ans[10];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=0,r,n,m,k,i,j,flag2,flag3,flag5;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
        printf("Case #%d:\n",++cas);
        while(r--)
        {
            int flag=0;
            for(i=1;i<=k;i++)
                scanf("%d",&a[i]);
            flag2=0;
            flag3=0;
            flag5=0;
            memset(num,0,sizeof(num));
            for(i=1;i<=k;i++)
            {
                if(a[i]==125)
                {
                    num[5]=3;
                    break;
                }
                if(a[i]==100)
                {
                    num[4]=1;
                    num[5]=2;
                    break;
                }
                if(a[i]==75)
                {
                    num[5]=2;
                    num[3]=1;
                    break;
                }
                if(a[i]==50)
                {
                    num[5]=2;
                    num[2]=1;
                    break;
                }
                if(a[i]==64)
                {
                    num[4]=3;
                    break;
                }
                if(a[i]==27)
                {
                    num[3]=3;
                    break;
                }
                if(a[i]==8)
                {
                    num[2]=3;
                    break;
                }
                if(a[i]==80)
                {
                    num[5]=1;
                    num[4]=2;
                    break;
                }
                if(a[i]==60)
                {
                    num[5]=1;
                    num[4]=1;
                    num[3]=1;
                    break;
                }
                if(a[i]==40)
                {
                    num[5]=1;
                    num[3]=1;
                    num[2]=1;
                    break;
                }
                if(a[i]==20)
                {
                    num[5]=1;
                    num[2]=2;
                    break;
                }
                if(a[i]==12)
                {
                    num[3]=1;
                    num[2]=2;
                    break;
                }
                if(a[i]==18)
                {
                    num[3]=2;
                    num[2]=1;
                    break;
                }
                if(a[i]==45)
                {
                    num[5]=1;
                    num[3]=2;
                    break;
                }
                if(a[i]==30)
                {
                    num[5]=1;
                    num[3]=1;
                    num[2]=1;
                    break;
                }
                if(a[i]==48)
                {
                    num[4]=3;
                    num[3]=1;
                    break;
                }
                if(a[i]==32)
                {
                    num[4]=2;
                    num[2]=1;
                    break;
                }
                if(a[i]==36)
                {
                    num[4]=1;
                    num[3]=2;
                    break;
                }
                if(a[i]==24)
                {
                    num[4]=1;
                    num[3]=1;
                    num[2]=1;
                    break;
                }
                if(a[i]==16)
                {
                    num[4]=1;
                    num[2]=2;
                    break;
                }
                if(a[i]%25==0)
                {
                    num[5]=max(num[5],2);
                    a[i]/=25;
                }
                if(a[i]%5==0)
                {
                    num[5]=max(num[5],1);
                    a[i]/=5;
                }
                if(a[i%9]==0)
                {
                    num[3]=max(num[3],2);
                    a[i]/=9;
                }
                if(a[i]%3==0)
                {
                    num[3]=max(num[3],1);
                    a[i]/=3;
                }
                if(a[i]%4!=0&&a[i]%2==0)
                    num[2]=max(num[2],1);
            }
            int t=0;
            for(i=2;i<=5;i++)
                for(j=1;j<=num[i];j++)
                    ans[++t]=i;
            for(t++;t<=3;t++)
                ans[t]=2;
            for(i=1;i<=3;i++)
                printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
