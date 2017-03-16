#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500;
const int MAXM = MAXN / 2;

struct TreeNode
{
    int l, r, min;
    int lazy;
} tree[MAXN * 4];

inline int lc(const int &x)
{
    return x << 1;
}

inline int rc(const int &x)
{
    return lc(x) + 1;
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].min = 0;
    tree[x].lazy = -1;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void relax(int x)
{
    if (tree[x].lazy != -1)
    {
        tree[lc(x)].min = max(tree[lc(x)].min, tree[x].lazy);
        tree[rc(x)].min = max(tree[rc(x)].min, tree[x].lazy);
        tree[lc(x)].lazy = tree[x].lazy;
        tree[rc(x)].lazy = tree[x].lazy;
        tree[x].lazy = - 1;
    }
}

void update(int x, int l, int r, int value)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].min = max(tree[x].min, value);
        tree[x].lazy = value;
        return;
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        update(lc(x), l, r, value);
    }
    else if (l > mid)
    {
        update(rc(x), l, r, value);
    }
    else
    {
        update(lc(x), l, mid, value);
        update(rc(x), mid + 1, r, value);
    }
}

int query(int x, int l, int r)
{
    if (tree[x].l == tree[x].r)
    {
        return tree[x].min;
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        return query(lc(x), l, r);
    }
    else if (l > mid)
    {
        return query(rc(x), l, r);
    }
    else
    {
        return min(query(lc(x), l, mid), query(rc(x), mid + 1, r));
    }
}

int N;
struct Nomadic
{
    int d, n, w, e, s;
    int delta_d, delta_p, delta_s;
    void input()
    {
        scanf("%d%d%d%d%d", &d, &n, &w, &e, &s);
        scanf("%d%d%d", &delta_d, &delta_p, &delta_s);
        w += MAXM;
        e += MAXM;
    }
    bool isAttack(int day)
    {
        for (int i = 0; i < n; ++i)
        {
            if (d + i * delta_d == day)
            {
                return true;
            }
        }
        return false;
    }
    int getIndex(int day)
    {
        for (int i = 0; i < n; ++i)
        {
            if (d + i * delta_d == day)
            {
                return i;
            }
        }
        return -1;
    }
    int nextAttack(int day)
    {
        for (int i = 0; i < n; ++i)
        {
            if (d + i * delta_d > day)
            {
                return d + i * delta_d;
            }
        }
        return -1;
    }
    int getLeft(int day)
    {
        return w + getIndex(day) * delta_p;
    }
    int getRight(int day)
    {
        return e + getIndex(day) * delta_p - 1;
    }
    int getStrenth(int day)
    {
        return s + getIndex(day) * delta_s;
    }
} nomadic[15];

int wall[MAXN];

int main()
{
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        memset(wall, 0, sizeof(wall));
        int ans = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
        {
            nomadic[i].input();
        }
        //build(1, 1, MAXN);
        int day = -1;
        bool finish = false;
        while (!finish)
        {
            finish = true;
            int nextAttack = 676060;
            for (int i = 0; i < N; ++i)
            {
                int next = nomadic[i].nextAttack(day);
                if (next != -1)
                {
                    finish = false;
                    nextAttack = min(nextAttack, next);
                }
            }
            day = nextAttack;
            for (int i = 0; i < N; ++i)
            {
                if (nomadic[i].isAttack(day))
                {
                    int l = nomadic[i].getLeft(day);
                    int r = nomadic[i].getRight(day);
                    int s = nomadic[i].getStrenth(day);
                    for (int j = l; j <= r; ++j)
                    {
                        if (wall[j] < s)
                        {
                            ++ans;
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < N; ++i)
            {
                if (nomadic[i].isAttack(day))
                {
                    int l = nomadic[i].getLeft(day);
                    int r = nomadic[i].getRight(day);
                    int s = nomadic[i].getStrenth(day);
                    for (int j = l; j <= r; ++j)
                    {
                        if (wall[j] < s)
                        {
                            wall[j] = s;
                        }
                    }
                }
            }
            /*for (int i = 0; i <= 8; ++i)
            {
                printf("%d ", wall[i]);
            }
            printf("\n");*/
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
