#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn = 256;

int index[maxn], listKeys[maxn];
bool useful[maxn];
int alreadyHave[maxn];
int memo[1 << 20];
int canOpen[1 << 20];
int inChest[maxn][maxn];
int needed[maxn];
int leftCount[maxn];
int K, N;

bool dfs(int exp) {
    if (memo[exp] != -1) {
        return memo[exp];
    }
    for (int i = 0; i < N; ++i) {
        if (!(exp >> i & 1) && dfs(exp | (1 << i)) && (canOpen[exp] >> needed[i] & 1)) {
            return memo[exp] = 1;
        }
    }
    return memo[exp] = 0;
}

void solve() {
    memset(alreadyHave, 0, sizeof alreadyHave);
    memset(inChest, 0, sizeof inChest);
    memset(index, -1, sizeof index);
    memset(useful, false, sizeof useful);

    int keys;
    scanf("%d%d", &K, &N);
    for (int i = 0; i < K; ++i) {
        scanf("%d", &keys);
        alreadyHave[keys] += 1;
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &needed[i]);
        useful[needed[i]] = true;
        
        int cnt;
        for (scanf("%d", &cnt); cnt > 0; --cnt) {
            scanf("%d", &keys);
            inChest[i][keys] += 1;
        }
    }


    int cntKeys = 0;
    for (int i = 1; i < maxn; ++i) {
        if (useful[i]) {
            index[i] = cntKeys;
            listKeys[cntKeys++] = i;
        }
    }
    //fprintf(stderr, "%d\n", cntKeys);
    for (int i = 0; i < N; ++i) {
        needed[i] = index[needed[i]];
    }

    int initials[maxn];
    memset(initials, 0, sizeof initials);
    for (int i = 1; i < maxn; ++i) {
        if (alreadyHave[i] && index[i] != -1) {
            initials[ index[i] ] += alreadyHave[i];
        }
    }

    for (int i = 0; i < 1 << N; ++i) {
        memo[i] = -1;

        for (int s = 0; s < cntKeys; ++s) {
            leftCount[s] = initials[s];
        }
        for (int j = 0; j < N; ++j) {
            if (i >> j & 1) {
                for (int s = 0; s < cntKeys; ++s) {
                    leftCount[s] += inChest[j][ listKeys[s] ];
                }
                leftCount[ needed[j] ] -= 1;
            }
        }
        canOpen[i] = 0;
        for (int s = 0; s < cntKeys; ++s) {
            if (leftCount[s] > 0) {
                canOpen[i] |= 1 << s;
            }
        }
    }
    memo[(1 << N) - 1] = 1;


    if (!dfs(0)) {
        puts(" IMPOSSIBLE");
    } else {
        for (int i = 0; i != (1 << N) - 1; ) {
            for (int j = 0; j < N; ++j) {
                if (!(i >> j & 1) && dfs(i | (1 << j)) && (canOpen[i] >> needed[j] & 1)) {
                    printf(" %d", j + 1);
                    i |= 1 << j;
                    break;
                }
            }
        } 
        puts("");
    }
}

int main() {
    freopen("D-small-attempt0.in", "r", stdin);
    //freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);

    int testCount;
    scanf("%d", &testCount);
    for (int testID = 1; testID <= testCount; ++testID) {
        printf("Case #%d:", testID);
        solve();
    }
}
