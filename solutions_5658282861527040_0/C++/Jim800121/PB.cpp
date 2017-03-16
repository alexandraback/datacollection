#include <cstdio>
#include <cstdlib>

int main()
{
    int T, caseNum=1;
    freopen ("B-small-attempt0.in","r",stdin);
    freopen ("B-small-attempt0.out","w",stdout);
    scanf("%d", &T);
    while(caseNum<=T)
    {
        int A, B, K;
        scanf("%d%d%d", &A, &B, &K);
        int cnt=0;
        for(unsigned int i=0; i<A; i++)
        {
            for(unsigned int j=0; j<B; j++)
            {
                if((i&j)<K)
                {
                    cnt++;
                }
            }
        }
        printf("Case #%d: %d\n", caseNum, cnt);
        caseNum++;
    }

    return 0;
}
