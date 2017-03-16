#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt[2505];
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("small.out","w",stdout);
    int T,n,nn;
    scanf("%d",&T);
    for(int cases=1;cases<=T;cases++)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        nn=2*n-1;
        int t;
        for(int i=0;i<nn;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&t);
                cnt[t]++;
            }
        }
        printf("Case #%d:",cases);
        for(int i=1;i<=2500;i++)
            if(cnt[i]&1) printf(" %d",i);
        puts("");
    }
    return 0;
}
