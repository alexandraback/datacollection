#include <cstdio>
#include <algorithm>
using namespace std;

int p[120000];
int main(void)
{
    int T;
    scanf("%d", &T);

    for(int caseCnt = 1; caseCnt <= T; ++caseCnt)
    {
        int A, N;
        scanf("%d%d", &A, &N);

        for(int i = 0; i < N; ++i)
            scanf("%d", &p[i]);

        if(A == 1)
        {
            printf("Case #%d: %d\n", caseCnt, N);
            continue;
        }

        sort(p, p+N);

        int min = 120000;

        int cnt = 0;
        for(int i = 0; i < N; ++i)
        {
            if(A > p[i])
            {
                A += p[i];
            }
            else if(2*A-1 > p[i])
            {
                A = 2*A-1;
                ++ cnt;
                A += p[i];
            }
            else
            {
                if(cnt + N-i < min)
                    min = cnt + N-i;

                while(A <= p[i])
                {
                    A = 2*A-1;
                    ++ cnt;
                }
                A += p[i];
            }
        }
        if(cnt < min) min = cnt;

        printf("Case #%d: %d\n", caseCnt, min);
    }
}

