#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 2507;

int T,n,h[MaxN];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&T);
    for (int i=1; i<=T; i++)
    {
        printf("Case #%d:",i);
        scanf("%d",&n);
        for (int j=1; j<MaxN; j++) h[j] = 0;
        for (int j=1; j<n+n; j++)
            for (int k=1; k<=n; k++)
            {
                int a; scanf("%d",&a);
                h[a]++;
            }
        for (int j=1; j<MaxN; j++)
            if(h[j]&1) printf(" %d",j);
        printf("\n");
    }
    return 0;
}
