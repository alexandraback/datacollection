#include <stdio.h>
#include <algorithm>
using namespace std;

int p[1000];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        int ans = 0;
        int n, m = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &p[i]);
            m = max(m, p[i]);
        }

        ans = m;
        for (int i = 1; i <= m; i++)
        {
            int temp = 0;
            for (int j = 0; j < n; j++)
            if (p[j] > i)
            {
                temp += p[j] / i - 1;
                if (p[j] % i > 0) { temp++; }
            }
            ans = min(ans, temp + i);
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

/*
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int> plates;

int min(int o, int p)
{
    return (o < p ? o : p);
}

int max(int o, int p)
{
    return (o > p ? o : p);
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("b1.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        int ans = 0;
        while (!plates.empty()) { plates.pop(); }
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            ans = max(ans, temp);
            plates.push(temp);
        }
        int m = ans;
        for (int i = 1; i <= m; i++)
        {
            int temp = plates.top();
            plates.pop();
            plates.push(temp / 2);
            temp = temp / 2 + temp % 2;
            plates.push(temp);
            temp = plates.top();
            ans = min(ans, temp + i);
        }

        //printf("Case #%d: %d\n", t, ans);
        printf("%d\n", ans);
    }
    return 0;
}*/

