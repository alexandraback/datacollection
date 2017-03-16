#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define INF 1000000000
using namespace std;

int num[1000005];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int cas,t=1,n,pos,A;
    long long cur,cnt,ans;

    scanf("%d",&cas);
    while (cas--)
    {
        cur=0;
        scanf("%d%d",&A,&n);
        ans=n;
        for (int i=0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n);
        cur=A;
        pos=0;
        cnt=0;
        if(cur==1)
        {
            printf("Case #%d: %d\n",t++,n);
            continue;
        }
        for (int i=0;i<n;i++)
        {
            if (cnt+n-i<ans)
                ans=cnt+n-i;
            while(cur<=num[i])
            {
                cur=cur+cur-1;
                cnt++;
            }
            cur+=(long long)num[i];
        }
        if(cnt<ans)
           ans=cnt;
        printf("Case #%d: %I64d\n",t++,ans);
    }
    return 0;
}
