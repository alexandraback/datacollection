#include <cstdio>
#include <cstring>
using namespace std;

const int N = 10500;

char nxt[256];

char buf[N];

struct quat
{
    bool neg;
    char c;
    friend quat operator *(quat a, quat b)
    {
        quat res;
        res.neg = a.neg ^ b.neg;
        if (a.c == 0)
            res.c = b.c;
        else if (b.c == 0)
            res.c = a.c;
        else if (a.c == b.c)
            res.c = 0, res.neg ^= 1;
        else if (b.c == nxt[a.c])
            res.c = nxt[b.c];
        else
            res.c = nxt[a.c], res.neg ^= 1;
        return res;
    }
    quat()
    {
        c = neg = 0;
    }
    quat(bool _neg, char _c)
    {
        neg = _neg, c = _c;
    }
    friend bool operator ==(quat a, quat b)
    {
        return a.neg == b.neg && a.c == b.c;
    }
};

void solve(int cs)
{
    int n, x;
    scanf("%d %d", &n, &x);
    scanf(" %s", buf);
    quat prod;
    for (int i = 0; i < n; i++)
        prod = prod * quat(false, buf[i]);
    quat res;
    for (int i = 0; i < x % 4; i++)
        res = res * prod;
    if (!(res == quat(true, 0)))
    {
        printf("Case #%d: NO\n", cs);
        return;
    }
    for (int i = 1; i < x; i++)
        for (int j = 0; j < n; j++)
            buf[i * n + j] = buf[j];
    n *= x;
    int l = n + 1;
    int r = -1;
    quat cur;
    for (int i = 1; i <= n; i++)
    {
        cur = cur * quat(false, buf[i - 1]);
        if (cur == quat(false, 'i'))
        {
            l = i;
            break;
        }
    }
    cur = quat();
    for (int i = n - 1; i >= 0; i--)
    {
        cur = quat(false, buf[i]) * cur;
        if (cur == quat(false, 'k'))
        {
            r = i;
            break;
        }
    }
    if (l <= r)
        printf("Case #%d: YES\n", cs);
    else
        printf("Case #%d: NO\n", cs);
}

int main()
{
    nxt['i'] = 'j';
    nxt['j'] = 'k';
    nxt['k'] = 'i';
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
