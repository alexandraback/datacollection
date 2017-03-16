#include <bits/stdc++.h>

using namespace std;

int H[3000];

void _main(int TEST)
{
    int N;
    scanf("%d", &N);
    memset(H, 0, sizeof H);
    for(int i=0; i<2*N-1; i++)
    {
        for(int j=0; j<N; j++)
        {
            int a;
            scanf("%d", &a);
            H[a]^=1;
        }
    }
    for(int i=0; i<3000; i++) if(H[i])
        printf("%d ", i);
    printf("\n");
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
