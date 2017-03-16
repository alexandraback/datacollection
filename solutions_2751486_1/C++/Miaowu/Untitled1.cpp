#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[1000005];
int dp[1000005];

bool Check(char ch)
{
    if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return false;
    return true;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,n,ccc=1,ok,tmp,p,T,k,tt;
    long long cnt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        scanf("%d",&p);
        n=strlen(str);
        cnt=0;
        tmp=0;
        for (i=0;i<p;i++)
        {
            if (Check(str[i])==false) tmp=0;
            else tmp++;
        }
        if (tmp<p) tt=0;
        else
        {
            tt=1;
            cnt=1;
        }
        for (i=p;i<n;i++)
        {
            if (Check(str[i])==false)
            {
                cnt=cnt+tt;
                tmp=0;
            }
            else
            {
                tmp++;
                if (tmp>=p) tt=i-p+2;
                cnt=cnt+tt;
            }
         //   printf("%d:%d %lld\n",i,tt,cnt);
        }
        printf("Case #%d: %lld\n",ccc++,cnt);
    }
    return 0;
}
