//GCJ 2016 round1A B
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAXN 1005
using namespace std;
int N;
int H[2505];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int Case,a;
    scanf("%d",&Case);
    for(int t=1;t<=Case;++t)
    {
        scanf("%d",&N);
        memset(H,0,sizeof(H));
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N*2-1;++j)
            {
                scanf("%d",&a);
                H[a]++;
            }
        }
        printf("Case #%d: ",t);
        int x=0;
        for(int i=1;i<=2500;++i)
        {
            if(H[i]%2==1)
            {
                printf(" %d",i);
                x++;
                if(x==N) printf("\n");
            }
        }
    }
    return 0;
}
