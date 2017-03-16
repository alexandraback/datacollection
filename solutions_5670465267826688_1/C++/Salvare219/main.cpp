#include<bits/stdc++.h>
using namespace std;


char s[15000];
int r[4][4]={
{0,1,2,3},
{1,4,3,6},
{2,7,4,1},
{3,2,5,4}
};
int mul(int x,int y)
{
    int f=0;
    if(x>=4)f^=1,x-=4;
    if(y>=4)f^=1,y-=4;
    return (r[x][y]+f*4)%8;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int ti=1,t;scanf("%d",&t);
    while(t--)
    {
        int l;
        long long x;
        scanf("%d%lld%s",&l,&x,s+1);
        for(int i=1;i<=l;i++)
            if(s[i]=='i')s[i]=1;
            else if(s[i]=='j')s[i]=2;
            else s[i]=3;
        int sum=0;
        for(int i=1;i<=l;i++)
            sum=mul(sum,s[i]);
        int now=sum,cnt=1;
        while(now!=0)
        {
            cnt++;
            now=mul(now,sum);
        }
        now=0;
        int how=x%cnt;
        for(int i=0;i<how;i++)
            now=mul(now,sum);
        int f=0;
        if(now==4)
        {
            int len=l*cnt,z1=-1,z2=-1;
            now=0;
            for(int i=1;i<=len;i++)
            {
                now=mul(now,s[(i-1)%l+1]);
                if(now==1)
                {
                    z1=i;
                    break;
                }
            }
            now=0;
            for(int i=len;i>0;i--)
            {
                now=mul(s[(i-1)%l+1],now);
                if(now==3)
                {
                    z2=len-i+1;
                    break;
                }
            }
            if(z1!=-1&&z2!=-1)
            {
                if(z1+z2<x*l)
                    f=1;
            }
        }
        printf("Case #%d: %s\n",ti++,f?"YES":"NO");
    }
    return 0;
}
