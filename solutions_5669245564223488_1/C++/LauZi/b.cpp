#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

LL M = 1000000007;
LL MOD = M;

LL pows[111];

LL jizz() {
    static char arr[101][101];

    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s", arr[i]);

    bool E[26][26] = {{0}};

    int len[101];
    bool used[26] = {0};
    int hd[26] = {0}, tl[26] = {0}, hat[26] = {0};
    for (int i = 0; i < n; ++i) {
        len[i] = strlen(arr[i]);

        E[arr[i][0]-'a'][arr[i][len[i]-1]-'a'] = true;

        int h = 1, t = len[i]-1;

        while (arr[i][h] == arr[i][h-1]) h += 1;

        if (h == len[i]) {
            hat[arr[i][0]-'a'] += 1;
            continue;
        } else {
            hd[arr[i][0]-'a'] += 1;
            tl[arr[i][len[i]-1]] += 1;
        }

        while (arr[i][t] == arr[i][t-1]) t -= 1;

        bool used_local[26] = {0};

        for (int j = 0; j < len[i]; ++j) {
            if (arr[i][j+1] == arr[i][j]) continue;

            int idx = arr[i][j] - 'a';
            if (h <= j && j < t && used[idx]) return 0;
            if (used_local[idx]) return 0;

            used[idx] = true;
            used_local[idx] = true;
        }
    }

    LL ans = 1;

    for (int i = 0; i < 26; ++i) {
        if (hd[i] > 1 || tl[i] > 1) return 0;
        ans = ans * pows[hat[i]] % MOD;
    }

/*

    int idx[101];
    for (int i = 0; i < n; ++i) idx[i] = i;

    LL cnt = 0;
    int cnt_ts[26] = {0};
    int T = 0;
    do {
        ++T;
        char lst = arr[idx[0]][0];
        bool gg = false;
        for (int i = 0; !gg && i < n; ++i) {
            if (arr[idx[i]][0] != lst) {
                if (cnt_ts[lst-'a'] == T) gg = true;
                cnt_ts[lst-'a'] = T;
            }
            lst = arr[idx[i]][0];

            int l = len[idx[i]];
            if (arr[idx[i]][l-1] != lst) {
                if (cnt_ts[lst-'a'] == T) gg = true;
                cnt_ts[lst-'a'] = T;
            }
            lst = arr[idx[i]][l-1];
        }
        if (cnt_ts[lst-'a'] == T) gg = true;
        if (!gg) cnt += 1;
    } while (std::next_permutation(idx, idx+n));

    return cnt;
*/
    int cnt = 0;

    for (int i = 0; i < 26; ++i) {
        int in_cnt = 0, out_cnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (i != j && E[i][j]) in_cnt += 1;
            if (i != j && E[j][i]) out_cnt += 1;
        }

        if (in_cnt == 0 && (out_cnt != 0 || E[i][i])) cnt += 1;
    }

    return ans * pows[cnt] % MOD;
}

int main() {
    pows[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        pows[i] = pows[i-1] * i % MOD;
    }

    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %I64d\n", t, jizz());
    }

    return 0;
}
