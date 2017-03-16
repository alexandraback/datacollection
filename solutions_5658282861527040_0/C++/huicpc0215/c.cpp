#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;

#define DEBUG

int main()
{
    #ifdef DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    int t,casecnt=1;
    int A,B,K;
    scanf("%d",&t);
    while( t-- )
    {
        printf("Case #%d: ",casecnt++);
        scanf("%d%d%d",&A,&B,&K);
        int ans = 0;
        for(int i=0;i<A;i++)
            for(int j=0;j<B;j++)
                    if((i&j)<K) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
