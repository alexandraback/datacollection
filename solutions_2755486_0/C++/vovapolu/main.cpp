#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int t;

int s[600];
int news[600];

struct el
{
    int d;
    int l, r;
    int s;
};

vector <el> elems;

bool operator < (const el &a, const el &b)
{
    return a.d < b.d;
}

bool handle(int l, int r, int val)
{
    l += 300;
    r += 300;
    bool ok = true;
    for (int i = l; i < r; i++)
    {
        if (s[i] < val)
            ok = false;
        news[i] = max(news[i], val);
    }
    return ok;
}

void update()
{
    for (int i = 0; i < 600; i++)
        s[i] = news[i];
}

void clear()
{
    for (int i = 0; i < 600; i++)
    {
        s[i] = 0;
        news[i] = 0;
    }
    elems.clear();
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        clear();
        int N;
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            int d, n, w, e, s, dd, dp, ds;
            scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
            for (int k = 0; k < n; k++)
            {
                elems.push_back((el){d, w, e, s});
                d += dd;
                w += dp;
                e += dp;
                s += ds;
            }
        }

        sort(elems.begin(), elems.end());
        int ans = 0;
        for (int j = 0; j < elems.size(); j++)
        {
            if (j > 0 && elems[j - 1].d != elems[j].d)
                update();
            if (!handle(elems[j].l, elems[j].r, elems[j].s))
                ans++;
        }
        printf("Case #%d: %d\n", i + 1, ans);
    }
    return 0;
}
