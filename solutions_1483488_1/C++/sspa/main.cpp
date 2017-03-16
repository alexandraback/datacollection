#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#include <map>

using namespace std;

int a,b;

int work(int x,int k)
{
    int h[11]={0};
    int i=0;
    while(x)
    {
        h[i]=x%10;
        x/=10;
        i++;
    }
    int ret=0;
    for(int j=k;j>=0;j--) ret=ret*10+h[j];
    for(int j=i-1;j>k;j--) ret=ret*10+h[j];
    return ret;
}

int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int ca,t=0;
    for(scanf("%d",&ca);ca--;)
    {
        map<pair<int,int>,int> hash;
        printf("Case #%d: ",++t);
        int a,b;
        int ans=0;
        scanf("%d%d",&a,&b);
        for(int i=a;i<b;i++)
        {
            for(int j=0;j<=9;j++)
            {
                int tmp=work(i,j);
                if(i<tmp && tmp<=b)
                {
                    if(hash[make_pair(i,tmp)]==0) ans++;
                    hash[make_pair(i,tmp)]=1;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
