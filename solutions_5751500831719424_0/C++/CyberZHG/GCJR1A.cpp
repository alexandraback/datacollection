#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 5;
const int MAXL = 100 + 5;

char s[MAXN][MAXL];
int n1, n2;
int ch1[MAXL], ch2[MAXL];
int num1[MAXL], num2[MAXL];

void divide(int &n, int ch[MAXL], int num[MAXL], char *str)
{
    n = 0;
    ch[n] = str[0];
    num[n++] = 1;
    for (int i = 1; str[i]; ++i)
    {
        if (str[i] == str[i - 1])
        {
            ++num[n - 1];
        }
        else
        {
            ch[n] = str[i];
            num[n++] = 1;
        }
    }
}

int getDist(int p1, int p2)
{
    divide(n1, ch1, num1, s[p1]);
    divide(n2, ch2, num2, s[p2]);
    if (n1 != n2)
    {
        return -1;
    }
    int d = 0;
    for (int i = 0; i < n1; ++i)
    {
        if (ch1[i] != ch2[i])
        {
            return -1;
        }
        d += abs(num1[i] - num2[i]);
    }
    return d;
}

struct Edge
{
    int u, v, w;
} edge[MAXN * MAXN];
int edgeNum;

void clearEdge()
{
    edgeNum = 0;
}

void addEdge(int u, int v, int w)
{
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    ++edgeNum;
}

int father[MAXN];

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if (x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    //freopen("A-small.in", "r", stdin);
    //freopen("A-small.out", "w", stdout);
    int T, N;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i)
        {
            scanf("%s", s[i]);
        }
        printf("Case #%d: ", cas);
        int d = getDist(1, 2);
        if (d == -1)
        {
            puts("Fegla Won");
        }
        else
        {
            printf("%d\n", d);
        }
    }
    return 0;
}
