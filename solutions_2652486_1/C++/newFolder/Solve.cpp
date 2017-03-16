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

const int maxn = 12;
const double eps = 1e-6;

int R, N, M, K;
int a[maxn], cnt[maxn];
int need[maxn][maxn];
int temp[maxn], ans[maxn], anstot;
bool flag;

void gao()
{
    for (int i = 0; i < K; i++)
        if (need[i][2] != 0 || need[i][3] != 0)
            return ;
    flag = true;
    memcpy(ans, temp, sizeof(ans));
}

void dfs(int depth, int pos)
{
    if (flag)
        return ;
    if (depth >= N)
    {
        gao();
        return ;
    }
    int tn[maxn][maxn];
    memcpy(tn, need, sizeof(tn));
    for (int i = pos; i <= M; i++)
    {
        if (i == 5 || i == 7)
            continue;
        temp[depth] = i;
        if (i == 2)
        {
            for (int i = 0; i < K; i++)
                if (need[i][2])
                    need[i][2]--;
            dfs(depth + 1, i);
        }
        if (i == 3)
        {
            for (int i = 0; i < K; i++)
                if (need[i][3])
                    need[i][3]--;
            dfs(depth + 1, i);
        }
        if (i == 4)
        {
            for (int i = 0; i < K; i++)
                if (need[i][2] >= 2)
                    need[i][2] -= 2;
            dfs(depth + 1, i);
        }
        if (i == 6)
        {
            for (int i = 0; i < K; i++)
                if (need[i][2] && need[i][3])
                    need[i][2] --, need[i][3]--;;
            dfs(depth + 1, i);
        }
        if (i == 8)
        {
            for (int i = 0; i < K; i++)
                if (need[i][2] >= 3)
                    need[i][2] -= 3;
            dfs(depth + 1, i);
        }
        memcpy(need, tn, sizeof(need));
    }
}

void solved(int cas)
{
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < K; i++)
        scanf ("%d", &a[i]);
    memset(need, 0, sizeof(need));
    for (int i = 0; i < K; i++)
    {
        int temp = a[i], cot = 0;
        while (temp % 2 == 0)
        {
            temp /= 2, cot++;
            need[i][2]++;
        }
        cnt[2] = max(cnt[2], cot);
        cot = 0;
        while (temp % 3 == 0)
        {
            temp /= 3, cot++;
            need[i][3]++;
        }
        cnt[3] = max(cnt[3], cot);
        cot = 0;
        while (temp % 5 == 0)
            temp /= 5, cot++;
        cnt[5] = max(cnt[5], cot);
        cot = 0;
        while (temp % 7 == 0)
            temp /= 7, cot++;
        cnt[7] = max(cnt[7], cot);
    }
    for (int i = 0; i < cnt[7]; i++)
        temp[i] = 7;
    for (int i = 0; i < cnt[5]; i++)
        temp[i+cnt[7]] = 5;
    int len = cnt[5] + cnt[7];
    memset(cnt, 0, sizeof(cnt));
    anstot = 0;
    flag = false;
    dfs(len, 2);
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