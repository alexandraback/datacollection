#include<cstdio>
#include<cstdlib>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;

int start[110];
long long lap[110];
int m;
int n; 

int main()
{
    int t, test;
    scanf("%d", &test);
    for (t = 0; t < test; t++)
    {
        m = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a;
            int g;
            long long alap;
            scanf("%d %d %lld", &a, &g, &alap);
            for (int j = 0; j < g; j++)
            {
                start[m] = a;
                lap[m] = alap;
                alap++;
                m++;
            }
        }

        long long best = m;
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                long long cand = j - 1;
                long long finish = (360 * j - start[i]) * lap[i];
                for (int k = 0; k < m; k++)
                {
                    if (k == i)
                        continue;
                    long long rest = finish - (360 - start[k]) * lap[k];
                    if (rest < 0)
                    {
                        cand++;
                    }
                    else
                    {
                        cand += rest / (360 * lap[k]);
                    }
                }
                best = min(best, cand);
            }
        }

        printf("Case #%d: %lld\n", t+1, best);
    }
    return 0;
}
