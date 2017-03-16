#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, k, n;
int key[201];
int needkeys[201];
int allkey[201];
int stkey;
int type[200];
int nextKey[200][400];
int nextKeyNum[200];
int keynum;
int ans[200];
bool visit[200];

bool needThisType(int i) {
    int thisType = type[i];
    for (int j = 0; j < n; ++j) {
        if (i == j)
            continue;
        for (int k = 0; k < nextKeyNum[j]; ++k) {
            if (nextKey[j][k] == thisType)
                return false;
        }
    }
    return true;
}

int dfs(int level) {
    if (level == n)
        return 1;

    for (int i = 0; i < n; ++i) {
        if (visit[i])
            continue;
        int needkey = type[i];
        if (key[needkey] <= 0)
            continue;
        visit[i] = true;
        key[needkey] --;
        for (int j = 0; j < nextKeyNum[i]; ++j) {
            key[nextKey[i][j]]++;
        }
        ans[level] = i;
        if (needkeys[needkey] <= key[needkey] && dfs(level + 1))
            return 1;
        for (int j = 0; j < nextKeyNum[i]; ++j) {
            key[nextKey[i][j]]--;
        }
        key[needkey] ++;
        visit[i] = false;
    }
    return 0;
}

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    scanf("%d", &t);
    for (int ti = 1; ti <= t; ++ti) {
        memset(key, 0, sizeof(key));
        memset(needkeys, 0, sizeof(needkeys));
        memset(allkey, 0, sizeof(allkey));

        scanf("%d %d", &k, &n);
        while(k--) {
            scanf("%d", &stkey);
            key[stkey]++;
            allkey[stkey]++;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &type[i], &nextKeyNum[i]);
            allkey[type[i]]--;
            for (int j = 0; j < nextKeyNum[i]; ++j) {
                scanf("%d", &nextKey[i][j]);
                allkey[nextKey[i][j]]++;
            }
        }

        for(int i = 0; i < n; ++i) {
            if (needThisType(i)) {
                needkeys[type[i]]++;
            }
        }

        bool canLock = true;
        for (int i = 0; i <= 200 && canLock; ++i) {
            if (allkey[i] < 0 || needkeys[i] > key[i])
                canLock = false;
        }

        memset(visit, 0, sizeof(visit));

        printf("Case #%d:", ti);

        if(canLock && dfs(0)) {
            for (int i = 0; i < n; ++i) {
                printf(" %d", ans[i] + 1);
            }
            printf ("\n");
        } else {
            printf(" IMPOSSIBLE\n");
        }
    }

    return 0;
}

