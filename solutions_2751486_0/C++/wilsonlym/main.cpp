#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<string>

using namespace std;

char str[1000025];
int f[1000025];
int g[1000025];

int main()
{
    freopen("x.in","r",stdin);
    freopen("x.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {
        scanf(" %s%d",str,&n);
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        int last=-1,len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u')
            {
                if(i==0)f[i]=1;
                else    f[i]=f[i-1]+1;
            }
            else
            {
                f[i]=0;
            }
            if(f[i]>=n)last=i-n+1;
            g[i]=last+1;
        }
        int ans=0;
        for(int i=0;i<len;i++)
          ans+=g[i];
        printf("Case #%d: %d\n",K,ans);
    }






    return 0;
}
