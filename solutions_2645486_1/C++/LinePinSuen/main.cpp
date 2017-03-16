#include <stdio.h>

int main(void)
{
    int T = 0;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {
        int E = 0;
        int R = 0;
        int N = 0;
        int V[10000];

        scanf("%d %d %d", &E, &R, &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &V[i]);
        }

        int next[10000];
        for (int i = 0; i < N; i++)
        {
            next[i] = i;
            for (int j = i + 1; j < N; j++)
            {
                if (V[i] < V[j])
                {
                    next[i] = j;
                    break;
                }
            }
        }

        int gain = 0;
        int e = E;
        for (int i = 0; i < N; i++)
        {
            e += R;
            if (e > E)
            {
                e = E;
            }
            int leak_range = (E - e) / R;
            if (next[i] == i)
            {
                gain += e * V[i];
                e = 0;
            }
            else if (next[i] > i + leak_range)
            {
                int spend = R * (next[i] - i) + e - E;
                if (spend > e)
                {
                    spend = e;
                }
                gain += spend * V[i];
                e -= spend;
            }
        }

        printf("Case #%d: %d\n", t, gain);
    }

    return 0;
}
