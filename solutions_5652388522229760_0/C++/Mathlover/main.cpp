#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
int cnt[10];
int main()
{
    int t;
    int ca=0;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: ",++ca);
        memset(cnt,0,sizeof(cnt));
        int q=10;
        int ans=-1;
        for(int i=1;i<100;++i)
        {
            int m=n*i;
            while(m)
            {
                if(cnt[m%10]==0)
                    cnt[m%10]++,q--;
                m/=10;
            }
            if(!q)
            {
                ans=i*n;
                break;
            }
        }
        if(ans==-1)
            puts("INSOMNIA");
        else printf("%d\n",ans);
    }
}
