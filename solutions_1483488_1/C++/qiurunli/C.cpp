#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 2000010;

int fact[20];
char digit[20];
int vis[MAXN];

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("c-large.out", "w", stdout);

    fact[0] = 1;
    for(int i = 1; i <= 10; ++i)  fact[i] = fact[i - 1] * 10;
    int test, cas(1);
    scanf("%d", &test);
    while(test--)
    {

        int A, B;
        scanf("%d%d", &A, &B);
        for(int i = A; i <= B; ++i)  vis[i] = -1;
        int ans(0);
        for(int i = A; i <= B; ++i)
        {
            sprintf(digit, "%d", i);
            int len(strlen(digit));

            int pre(0);
            for(int j = len - 1, k = 0; j > 0; --j, ++k)
            {
                pre += (digit[j] - '0') * fact[k];
                int tmp = pre * fact[len - 1 - k] + i / fact[k + 1];

                if(tmp <= B && tmp > i && vis[tmp] != i)
                {
//                    if(vis[tmp] != -1)  printf("%d  %d\n", tmp, vis[tmp], i);
                    vis[tmp] = i;
                    ++ans;
                }
            }
        }
//        if(ans == 0)  printf("%d %d", A, B);
        printf("Case #%d: %d\n", cas++, ans);
    }

    return 0;
}
