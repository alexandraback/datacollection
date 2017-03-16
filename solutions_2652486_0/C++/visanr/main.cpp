#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool PassedProd[100];
int R, N, M, K, T, Prod[100];

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int i, j, k;
    scanf("%i", &T);
    for(int TestCase = 1; TestCase <= T; ++ TestCase)
    {
        printf("Case #%i:\n", TestCase);
        scanf("%i %i %i %i", &R, &N, &M, &K);
        for(i = 1; i <= R; ++ i)
        {
            for(j = 1; j <= K; ++ j)
                scanf("%i", &Prod[j]);
            bool Found = 0;
            for(j = 200; j <= 999; ++ j)
            {
                for(k = 1; k <= K; ++ k) PassedProd[k] = 0;
                int Temp = j, A, B, C;
                A = Temp % 10; Temp /= 10;
                B = Temp % 10; Temp /= 10;
                C = Temp % 10; Temp /= 10;
                if(A < 2 || B < 2 || C < 2 | A > M || B > M || C > M) continue;
                for(k = 1; k <= K; ++ k)
                    if(Prod[k] == 1 || Prod[k] == A || Prod[k] == B || Prod[k] == C || Prod[k] == A * B || Prod[k] == B * C || Prod[k] == A * C || Prod[k] == A * B * C)
                        PassedProd[k] = 1;
                bool OK = 1;
                for(k = 1; k <= K; ++ k)
                    if(!PassedProd[k])
                        OK = 0;
                if(OK)
                {
                    Found = 1;
                    printf("%i\n", j);
                    break;
                }
            }
            if(Found == 0)
            {
                for(j = 200; j <= 999; ++ j)
                {
                    int Temp = j, A, B, C;
                    A = Temp % 10; Temp /= 10;
                    B = Temp % 10; Temp /= 10;
                    C = Temp % 10; Temp /= 10;
                    if(A < 2 || B < 2 || C < 2) continue;
                    printf("%i\n", j);
                    break;
                }
            }
        }
    }
    return 0;
}
