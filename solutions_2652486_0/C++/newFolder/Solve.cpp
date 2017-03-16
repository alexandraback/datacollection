#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

const int maxn = 20;
const double eps = 1e-6;

int R, N, M, K;
int a[maxn], cnt[maxn];
int temp[maxn], ans[maxn], anstot;

void gao()
{
    int len = 1 << N;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < len; i++)
    {
        int num = 1;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                num = num * temp[j];
        for (int j = 0; j < K; j++)
            if (num == a[j])
                cnt[j]++;
    }
    int tot = 0;
    for (int i = 0; i < K; i++)
    {
        if (cnt[i] == 0)
            return ;
        tot += cnt[i];
    }
    if (tot > anstot)
    {
        anstot = tot;
        memcpy(ans, temp, sizeof(ans));
    }
}

void dfs(int depth, int pos)
{
    if (depth == N)
    {
        gao();
        return ;
    }
    for (int i = pos; i <= M; i++)
    {
        temp[depth] = i;
        dfs(depth + 1, i);
    }
}

void solved(int cas)
{
    for (int i = 0; i < K; i++)
        scanf ("%d", &a[i]);
    anstot = 0;
    dfs(0, 2);
    for (int i = 0; i < N; i++)
        printf ("%d", ans[i]);
    printf ("\n");
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf ("%d", &T);
    printf ("Case #1:\n");
    scanf ("%d %d %d %d", &R, &N, &M, &K);
    for (int i = 1; i <= R; i++)
        solved(i);
    return 0;
}