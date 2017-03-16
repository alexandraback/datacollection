#include <cstdio>

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int D;
        int P[1005];
        scanf("%d", &D);
        for(int i=0; i<D; i++)
            scanf("%d", P+i);
        int ans=1e9;
        for(int M=1000; M>0; M--)
        {
            int S=M;
            for(int i=0; i<D; i++)
            {
                S+=(P[i]-1)/M;
            }
            if (S<ans) ans=S;
        }
        printf("Case #%d: %d\n", t, ans);
    }
}
