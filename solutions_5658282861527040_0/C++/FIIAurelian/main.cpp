#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,A,B,K;
int main()
{
    freopen("file.in","r",stdin);
    freopen("file.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int hit = 0;
        scanf("%d%d%d",&A,&B,&K);
        for(int i=0;i<A;i++)
            for(int j=0;j<B;j++)
                if((i&j) < K)hit++;
        printf("Case #%d: %d\n",t,hit);
    }
    return 0;
}





