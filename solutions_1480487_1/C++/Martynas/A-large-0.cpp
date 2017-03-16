#include <cstdio>
#include <algorithm>

using namespace std;

void solve()
{
    int N;
    scanf("%d", &N);
    int s[N];
    double sum = 0;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", s + i);
        sum += s[i];
    }
    for (int i = 0; i < N; ++i)
    {
        double low = 0, high = 1;
        while (low < high - 1e-10)
        {
            double mid = (low + high) / 2;
            double score = s[i] + sum * mid;
            double need = 0;
            for (int j = 0; j < N; ++j)
            {
                if (j != i)
                {
                    need += max(0.0, (score - s[j]) / sum);
                }
            }
            if (need > 1 - mid)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        printf(" %.6f", low * 100);
    }
    putchar('\n');
}

int main() {
    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        printf("Case #%d:", t);
        solve();
    }
}
