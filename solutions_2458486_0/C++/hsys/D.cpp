#include <cstdio>
#include <cstring>

int state_key[1 << 20][200];
int path[1 << 20];
int state_key_cnt[1 << 20];
int ti[30], ki[30];
int key_list[30][50];
int n;

void gao(int s) {
    if (s == (1 << n) - 1) {
        return;
    }

    //printf("gao %x\n", s);

    int keys[201];
    memset(keys, 0, sizeof(keys));
    for (int i = 0; i < state_key_cnt[s]; i++)
        keys[state_key[s][i]]++;
    for (int i = 0; i < n; i++) {
        if (s & (1 << i) || keys[ti[i]] <= 0)
            continue;
        //printf("  -> %d\n", i);
        int ns = s | (1 << i);
        if (state_key_cnt[ns] != -1)
            continue;
        path[ns] = i;
        state_key_cnt[ns] = state_key_cnt[s] - 1 + ki[i];
        int idx = 0;
        for (int j = 0; j < state_key_cnt[s]; j++) {
            state_key[ns][j] = state_key[s][j];
            if (state_key[s][j] == ti[i])
                idx = j;
        }
        state_key[ns][idx] = state_key[ns][state_key_cnt[s] - 1];
        for (int j = 0, j1 = state_key_cnt[s] - 1; j < ki[i]; j++, j1++) {
            state_key[ns][j1] = key_list[i][j];
        }
        gao(ns);
    }
}

void print_path(int s) {
    if (s == 0)
        return;
    int i = path[s];
    print_path(s & ~(1 << i));
    printf(" %d", i + 1);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        memset(state_key_cnt, -1, sizeof(state_key_cnt));
        scanf("%d%d", &state_key_cnt[0], &n);
        for (int i = 0; i < state_key_cnt[0]; i++)
            scanf("%d", &state_key[0][i]);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &ti[i], &ki[i]);
            for (int j = 0; j < ki[i]; j++)
                scanf("%d", &key_list[i][j]);
        }
        gao(0);
        printf("Case #%d:", t);
        if (state_key_cnt[(1 << n) - 1] < 0) {
            printf(" IMPOSSIBLE\n");
        } else {
            print_path((1 << n) - 1);
            putchar('\n');
        }
    }
}
