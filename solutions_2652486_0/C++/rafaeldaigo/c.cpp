#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    int r, n, m, k;
    int i, j, d;
    int a, b, c;
    int value[10];
    int prod[8];
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d %d %d\n", &r, &n, &m, &k);
        m++;
        printf("Case #%d:\n", t+1);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < k; j++)
            {
                scanf("%d", &value[j]);
            }
            for (a = 2; a < m; a++)
            {
                for (b = a; b < m; b++)
                {
                    for (c = b; c < m; c++)
                    {
                        prod[0] = 1;
                        prod[1] = a;
                        prod[2] = b;
                        prod[3] = c;
                        prod[4] = a * b;
                        prod[5] = b * c;
                        prod[6] = c * a;
                        prod[7] = a * b * c;
                        for (j = 0; j < k; j++)
                        {
                            for (d = 0; d < 8; d++)
                            {
                                if (prod[d] == value[j])
                                    break;
                            }
                            if (d == 8)
                                break;
                        }
                        if (j == k)
                            break;
                    }
                    if (c < m)
                        break;
                }
                if (b < m)
                    break;
            }
            printf("%d%d%d\n", a, b, c);
        }
    }
    return 0;
}
