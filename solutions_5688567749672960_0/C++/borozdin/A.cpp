#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

const int N = (int) 1e8;
const int INF = (int) 1e9;

int dist[N];
int q[N];
int ql, qr;

int reversed(int x)
{
    int y = 0;
    while (x > 0)
    {
        int d = x % 10;
        y = 10 * y + d;
        x /= 10;
    }
    return y;
}

void solve()
{
    fill(dist, dist + N, INF);
    dist[1] = 1;
    q[qr++] = 1;

    while (ql < qr)
    {
        int v = q[ql++];

        int to = v + 1;
        if (to < N && dist[to] == INF)
        {
            dist[to] = dist[v] + 1;
            q[qr++] = to;
        }

        to = reversed(v);
        if (to < N && dist[to] == INF)
        {
            dist[to] = dist[v] + 1;
            q[qr++] = to;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int x;
        scanf("%d", &x);
        printf("Case #%d: %d\n", i + 1, dist[x]);
    }

    eprintf("time = %.3lf\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}
