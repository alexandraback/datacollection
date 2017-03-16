#include <cstdio>
#include <cassert>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int memo[1<<20];
int cnt[20][40];
int types[20];
int orig[40];
int n;

bool can_take(int mask, int i) {
    int key_type = types[i], num_keys = orig[key_type];

    for(int j = 0; j < n; j++)
        if(mask & (1<<j)) {
            num_keys += cnt[j][key_type];
            if(types[j] == key_type) num_keys--;
        }

    assert(num_keys >= 0);
    return num_keys > 0;
}

int doit(int mask) {
    int& ret = memo[mask];
    if(ret != -1) return ret;
    ret = false;

    for(int i = 0; i < n; i++) {
        if(mask & (1<<i)) continue;
        if(can_take(mask, i) && doit(mask | (1<<i)))
            return ret = true;
    }

    return ret = false;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int k;
        scanf("%d %d", &k, &n);

        memset(orig, 0, sizeof orig);
        memset(cnt, 0, sizeof cnt);
        memset(memo, -1, sizeof memo);
        memo[(1<<n)-1] = true;

        for(int i = 0; i < k; i++) {
            int tmp;
            scanf("%d", &tmp);
            orig[tmp-1]++;
        }

        for(int i = 0; i < n; i++) {
            scanf("%d", &types[i]);
            types[i]--;

            int tmp;
            scanf("%d", &tmp);

            for(int j = 0; j < tmp; j++) {
                int tmp2;
                scanf("%d", &tmp2);
                cnt[i][tmp2-1]++;
            }
        }

        int mask = 0;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            bool ok = false;

            for(int j = 0; j < n; j++) {
                if(mask & (1<<j)) continue;

                if(can_take(mask, j) && doit(mask | (1<<j))) {
                    mask |= 1<<j;
                    ans.push_back(j);
                    ok = true;
                    break;
                }
            }

            if(!ok)
                break;
        }

        printf("Case #%d:", z);
        if(mask != (1<<n)-1)
            printf(" IMPOSSIBLE\n");
        else {
            for(int i = 0; i < n; i++)
                printf(" %d", ans[i]+1);
            printf("\n");
        }
    }
}
