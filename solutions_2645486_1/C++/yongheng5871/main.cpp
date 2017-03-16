#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

typedef long long ll;
const int Maxn = 1e4 + 10;
struct Node
{
    int id;
    ll v;
    bool operator < (const Node &e) const
    {
        return v < e.v;
    }
}node[Maxn];
ll c[Maxn];
ll sum[Maxn];
ll E, R;
int n;
ll ans;
void add(int k, ll v)
{
    for (int i = k; i <= n; i += (-i & i))
        c[i] += v;
    sum[k] += v;
}
ll search(int k)
{
    ll ret = 0;
    for (int i = k; i > 0; i -= (-i & i))
        ret += c[i];
    return ret;
}

struct PQ : priority_queue<Node>
{
    void clear()
    {
        c.clear();
    }
}que;
ll resume(Node &e)
{
    return min(E + (e.id - 1) * R - search(e.id - 1), E - sum[e.id]);
}

void deal(ll r)
{
    while(r)
    {
        Node e = que.top();
        ll tmp = resume(e);
        if (tmp <= r)
        {
            add(e.id, tmp);
            que.pop();
            r -= tmp;
            ans += tmp;
        }
        else
        {
            add(e.id, r);
            ans += r;
            r = 0;
        }
    }

}
int main()
{
    freopen("in.txt", "r", stdin);
//    freopen("C:\\Users\\数字艺术实验室\\Downloads\\small.in", "r", stdin);
//    freopen("C:\\Users\\数字艺术实验室\\Downloads\\small.out", "w", stdout);

//    freopen("C:\\Users\\数字艺术实验室\\Downloads\\large.in", "r", stdin);
//    freopen("C:\\Users\\数字艺术实验室\\Downloads\\large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d: ", cas);
        memset(c, 0, sizeof(c));
        memset(sum, 0, sizeof(sum));
        ans = 0;
        que.clear();
        scanf ("%I64d%I64d%d", &E, &R, &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &node[i].v);
            node[i].id = i + 1;
        }
        que.push(node[0]);
        for (int i = 1; i < n; ++i)
        {
            deal(R);
            que.push(node[i]);
        }
        deal(E);
        printf("%I64d\n", ans);
    }

    return 0;
}
