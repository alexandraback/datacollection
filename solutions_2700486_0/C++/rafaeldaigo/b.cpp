#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

double prob[2000][2000];

int main()
{
    int t, teste;
    int n, x, y;
    int i, j;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d %d %d\n", &n, &x, &y);

        if (x < 0) x = -x;
        int target = (x + y)/2;
        int current = 0;
        double resp = 0;

        while(true)
        {
            if (n < 4 * current + 1)
            {
                if (current < target || y == 2 * current)
                {
                    resp = 0;
                    break;
                }
                else
                {
                    y++;
                    if (y + 2 * target <= n)
                    {
                        resp = 1;
                        break;
                    }
                    for (j = 0; j <= n; j++)
                    {
                        for (i = 0; i <= y; i++)
                        {
                            prob[j][i] = 0;
                        }
                    }
                    prob[0][0] = 1;
                    for (j = 0; j < n; j++)
                    {
                        for (i = 0; i < y; i++)
                        {
                            if (j - i < 2 * target)
                            {
                                prob[j+1][i] += 0.5 * prob[j][i];
                                prob[j+1][i+1] += 0.5 * prob[j][i];
                            }
                            else
                            {
                                prob[j+1][i+1] += prob[j][i];
                            }
                        }
                        prob[j+1][y] += prob[j][y];
                    }
                    resp = prob[n][y];
                    break;
                }
            }
            else
            {
                n -= 4 * current + 1;
                current++;
                if (current > target)
                {
                    resp = 1;
                    break;
                }
            }
        }

        printf("Case #%d: %lf\n", t+1, resp);
    }
    return 0;
}
