#include <bits/stdc++.h>
using namespace std;

int K, L, S;
char sk[110], sl[110], ss[110];

int num, heap;

void dfs(int index) {
    if (index == S) {
        ss[S] = 0;
        char *cur = ss;
        int cnt = 0;
        while ((cur = strstr(cur, sl)) != nullptr) {
            ++cur;
            ++num;
            ++cnt;
        }
        heap = max(heap, cnt);
        return;
    }
    for (int i = 0; i < K; ++i) {
        ss[index] = sk[i];
        dfs(index + 1);
    }
}

int main() {
    int T;
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s%s", sk, sl);
        num = heap = 0;
        dfs(0);
        int total = 1;
        for (int i = 0; i < S; ++i) {
            total *= K;
        }
        printf("Case #%d: %.8f\n", t, heap - 1.0 * num / total);
    }
    return 0;
}
