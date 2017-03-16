#include <stdio.h>
#include <string.h>

const int maxn = 101;

char key[maxn];
char target[maxn];
char buf[maxn];

int mb, cse, cnt;
int T, K, L, S;

void proc(int depth) {
    if (depth == S) {
        int c = 0;
        for(int i = 0; i <= S - L; ++i)
            if (strncmp(buf + i, target, L) == 0)
                c++;
        mb = mb > c ? mb : c;
        cnt += c;
        cse++;
        return;
    }

    for(int i = 0; i < K; ++i) {
        buf[depth] = key[i];
        proc(depth + 1);
    }
}

void run() {
    mb = 0, cse = 0, cnt = 0;
    memset(buf, 0, sizeof(buf));
    proc(0);
}

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s%s", key, target);
        run();
        printf("Case #%d: %lf\n", t, mb - cnt / (double)cse);
    }
    return 0;
}
