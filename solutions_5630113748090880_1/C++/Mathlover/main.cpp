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
int cnt[2501];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("2.out","w",stdout);
    int t;
    int ca=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        int n;
        scanf("%d",&n);
        for(int i=0;i<2*n-1;++i)
            for(int j=0;j<n;++j)
            {
                int x;
                scanf("%d",&x);
                cnt[x]++;
            }
        printf("Case #%d:",++ca);
        for(int i=1;i<=2500;++i)
            if(cnt[i]%2)
                printf(" %d",i);
        puts("");
    }
}
