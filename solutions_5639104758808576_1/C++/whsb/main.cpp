#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

char lev[1024];
int sum[1024],N;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d",&N);
        scanf("%s",lev);
        int ans = 0;
        sum[0]=lev[0]-'0';
        for(int i=1;i<=N;i++)
        {
            sum[i]=sum[i-1];
            if(lev[i]=='0') continue;
            sum[i]+=lev[i]-'0';
            if(sum[i-1]+ans<i) ans += i-ans-sum[i-1];
        }
        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;
}
