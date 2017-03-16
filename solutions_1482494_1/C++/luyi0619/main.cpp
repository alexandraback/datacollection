#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;
int n;

struct Node
{
    int a, b;
} node[N];

bool cmp(const Node& x, const Node& y)
{
    if (x.b == y.b) return x.a > y.a;
    return x.b < y.b;
}
bool visited[N];

int solve()
{
    sort(node, node + n, cmp);
    int cur = 0, res = 0;
    memset(visited, 0, sizeof (visited));
    for (int i = 0; i < n; ++i)
    {
        while (cur < node[i].b)
        {
            bool has = false;
            for (int j = n - 1; j >= i; --j)
            {
                if (!visited[j] && cur >= node[j].a)
                {
                    cur += 1;
                    ++res;
                    has = true;
                    visited[j] = 1;
                    break;
                }
            }
            if (!has) break;
        }
        if (cur >= node[i].b)
        {
            cur += 1;
            if (!visited[i]) cur += 1;
        }
        else return -1;
    }
    return res + n;
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("ans.large", "w", stdout);
    int t, tcas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; ++i)
            scanf("%d %d", &node[i].a, &node[i].b);
        printf("Case #%d: ", tcas++);
        int ans = solve();
        if (ans == -1)
            printf("Too Bad\n");
        else
            printf("%d\n", ans);
    }
}
