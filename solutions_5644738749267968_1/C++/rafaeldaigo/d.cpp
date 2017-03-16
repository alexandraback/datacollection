#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int main()
{
    int t, teste;
    double p1[2000];
    double p2[2000];
    int n;
    int i, j;
    int a, b;
    scanf("%d\n", &teste);
    for (int t = 0; t < teste; t++)
    {
        scanf("%d\n", &n);
        for (i = 0; i < n; i++)
            scanf("%lf", &p1[i]);
        for (i = 0; i < n; i++)
            scanf("%lf", &p2[i]);
        sort(&p1[0], &p1[n]);
        sort(&p2[0], &p2[n]);

        j = 0;
        a = 0;
        for (i = 0; i < n; i++)
        {
            for (; j < n; j++)
            {
                if (p2[i] < p1[j])
                {
                    j++;
                    a++;
                    break;
                }
            }
            if (j == n)
                break;
        }

        j = 0;
        b = n;
        for (i = 0; i < n; i++)
        {
            for (; j < n; j++)
            {
                if (p1[i] < p2[j])
                {
                    j++;
                    b--;
                    break;
                }
            }
            if (j == n)
                break;
        }

        printf("Case #%d: %d %d\n", t + 1, a, b);
    }
    return 0;
}
