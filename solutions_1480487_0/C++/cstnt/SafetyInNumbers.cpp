#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 210;
int n;
int s[MAXN];
double result[MAXN];
bool above[MAXN];

void run()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i];
		above[i] = false;
    }
    double average = (sum ) * 2.0 / n;
    
    for (int i = 0; i < n; i++)
    {
        if (average - 1e-6 < s[i])
        {
            result[i] = 0;
            above[i] = true;
        }
    }

    int cnt = 0;
    int sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (!above[i])
        {
            sum2 += s[i];
            cnt++;
        }
    }

    if (cnt > 0)
    {
        average = (sum2 + sum) * 1.0 / cnt;

        for (int i = 0; i < n; i++)
        {
            if (!above[i])
            {
                result[i] = (average - s[i]) / sum;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &s[j]);
        }
        run();

        printf("Case #%d:", i + 1);

        for (int j = 0; j < n; j++)
        {
            printf(" %.6lf", result[j] * 100);
        }
        printf("\n");
    }
}
