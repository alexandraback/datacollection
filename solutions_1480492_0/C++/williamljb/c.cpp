#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eps (1e-8)
using namespace std;

const int   maxn = 100;
int         n, m, speed[maxn], lane[maxn];
double      pos[maxn], used_time;

double abs_double(double x)
{
    return x > 0 ? x : -x;
}

bool block(int x, int y)
{
    if (pos[x] > pos[y] + 5 + eps || pos[x] < pos[y] - 5 - eps)
        return false;
    if (abs_double(pos[x] - pos[y] - 5) < eps)
        return speed[x] < speed[y];
    if (abs_double(pos[y] - pos[x] - 5) < eps)
        return speed[x] > speed[y];
    return true;
}

double find()
{
    double mini = 1e10;
    int p = -1, q = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (lane[i] == lane[j] && speed[i] > speed[j] && pos[i] < pos[j])
            {
                double tmp = (pos[j] - pos[i] - 5) / (speed[i] - speed[j]);
                if (mini > tmp)
                {
                    mini = tmp;
                    p = i;
                    q = j;
                }
            }
    if (mini > 1e9)
        return 1e10;
    for (int i = 1; i <= n; ++i)
        pos[i] += mini * speed[i];
    bool bp = true, bq = true;
    for (int i = 1; i <= n; ++i)
        if (lane[i] != lane[p])
        {
            if (block(i, q))
                bq = false;
            if (block(i, p))
                bp = false;
        }
    if (bp)
        if (bq)
        {
            lane[p] = 1 - lane[p];
            double tmp = find();
            swap(lane[p], lane[q]);
            tmp = max(tmp, find());
            lane[q] = 1 - lane[q];
            for (int i = 1; i <= n; ++i)
                pos[i] -= mini * speed[i];
            return mini + tmp;
        }
        else
        {
            lane[p] = 1 - lane[p];
            double tmp = find();
            lane[p] = 1 - lane[p];
            for (int i = 1; i <= n; ++i)
                pos[i] -= mini * speed[i];
            return mini + tmp;
        }
    else
        if (bq)
        {
            lane[q] = 1 - lane[q];
            double tmp = find();
            lane[q] = 1 - lane[q];
            for (int i = 1; i <= n; ++i)
                pos[i] -= mini * speed[i];
            return mini + tmp;
        }
        else
        {
            for (int i = 1; i <= n; ++i)
                pos[i] -= mini * speed[i];
            return mini;
        }
    return 1e10;
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        lane[i] = (getchar(), getchar()) == 'R';
        scanf("%d%lf", speed + i, pos + i);
    }
    double ans = find();
    if (ans > 1e9)
        printf("Possible\n");
    else
        printf("%.7lf\n", ans);
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int times;
    scanf("%d", &times);
    for (int i = 1; i <= times; ++i)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
