#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int A,B,K;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int tit,tot;
    for(scanf("%d",&tot),tit=1;tit<=tot;tit++)
    {
        scanf("%d%d%d",&A,&B,&K);
        int ans=0;
        for(int i=0;i<A;i++)
            for(int j=0;j<B;j++)
                if((i&j)<K)ans++;
        printf("Case #%d: %d\n",tit,ans);
    }
	return 0;
}
