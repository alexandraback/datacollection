#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

int T;
int n;
int num[1100];

std::vector<int> tree[1100];
std::vector<int> couple;

char used[1100];

int dfs(int x) 
{
    int ans = 0;
    for (int i = 0; i < tree[x].size(); i++) {
        if (tree[x][i] == num[x]) {
            continue;
        } else {
            int tmp = dfs(tree[x][i]);
            if (tmp > ans) {
                ans = tmp;
            }
        }
    }
    return ans + 1;
}

int calc_couple()
{
    int ans = 0;
    memset(used, 0, sizeof(used));
    couple.clear();
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        } else if (num[num[i]] == i) {
            used[i] = 1;
            used[num[i]] = 1;
            couple.push_back(i);
        }
    }
    for (int i = 0; i < couple.size(); i++) {
        ans += dfs(couple[i]) + dfs(num[couple[i]]);
    }
    return ans;
}

int max_circle()
{
    int ans = 0;
    for (int i = 0 ; i < n ; i++) {
        memset(used, 0, sizeof(used));
        int now = i;
        int tmp = 0;
        while(!used[now]) {
            used[now] = 1;
            tmp ++;
            now = num[now];
        }
        if (now == i) {
            if (tmp > ans) {
                ans = tmp;
            }
        }
    }
    return ans;
}

int calc()
{
    int ans = 0;
    int tmp;

    tmp = calc_couple();
    if (tmp > ans) {
        ans = tmp;
    }

    tmp = max_circle();
    if (tmp > ans) {
        ans = tmp;
    }

    return ans;
}

int main()
{
    scanf("%d", &T);
    for (int z = 1; z <= T; z++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            tree[i].clear();
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", num + i);
            num[i]--;
            tree[num[i]].push_back(i);
        }
        printf("Case #%d: %d\n", z, calc());
    }

	return 0;
}

