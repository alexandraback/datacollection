#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(int K, int C, int S)
{
    long long int site[101];
    long long int nowK;
    int i, j;
    for(i=1;i<=K;++i)
    {
        site[i] = i;
    }
    for(i=1, nowK=K;i<C;++i, nowK *= K)
    {
        for(j=1;j<=K;++j)
        {
            site[j] = site[j]+nowK*(j-1);
        }
    }
    for(i=1;i<=K;++i)
    {
        printf(" %lld", site[i]);
    }
    printf("\n");
}

int main()
{
    int t, T;
    int K, C, S;
    scanf("%d",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d %d %d",&K ,&C ,&S);

        printf("Case #%d:", t);
        solve(K, C, S);
    }

    return 0;
}
