#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define LL long long
#define MOD 1000000007
using namespace std;

int n;
LL frac[110];
int indeg[300], outdeg[300], nxt[300], same[300], hide[300];
bool vst[300];

void addEdge(int a, int b) {
    nxt[a] = b;
    ++outdeg[a];
    ++indeg[b];
}

void process(int id, char *s) {
    int l = strlen(s);
    int i = 0, j = l-1;
    char left = s[i], right = s[j];
    while (i+1 < l && s[i] == s[i+1]) ++i;
    while (j-1 >= 0 && s[j] == s[j-1]) --j;
    if (i >= j) {
        ++same[left];
        //printf("same %c ++\n", left);
    }
    else {
        for (++i; i < j; ) {
            //printf("hide %c ++\n", s[i]);
            hide[s[i]]++;
            int k = i;
            while (s[i] == s[k]) ++k;
            i = k;
        }
        //printf("add edge %c %c\n", left, right);
        addEdge(left, right);
    }
}

bool go(int u) {
    if (vst[u]) return false;
    vst[u] = true;
    if (nxt[u] != 0) return go(nxt[u]);
    return true;
}

int solve() {
    for (int i = 'a'; i <= 'z'; ++i) if (hide[i] > 1 || indeg[i] > 1 || outdeg[i] > 1 || (hide[i] == 1 && indeg[i] + outdeg[i] > 0)) return 0;
    memset(vst, 0, sizeof(vst));
    int groups = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (same[i] > 0 && indeg[i] + outdeg[i] == 0) ++groups;
        if (indeg[i] == 0 && outdeg[i] == 1 && !vst[i]) {
            ++groups;
            if (!go(i)) return 0;
        }
    }
    for (int i = 'a'; i <= 'z'; ++i) if (!vst[i] && indeg[i]+outdeg[i] > 0) return 0;
    //printf("%d\n", groups);
    LL ret = frac[groups];
    for (int i = 'a'; i <= 'z'; ++i) ret = (ret * frac[same[i]]) % MOD;
    return ret;
}

void preprocess() {
    frac[0] = 1;
    for (int i = 1; i <= 100; ++i) frac[i] = (frac[i-1]*i)%MOD;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    char s[110][110];
    preprocess();
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        memset(indeg, 0, sizeof(indeg));
        memset(outdeg, 0, sizeof(outdeg));
        memset(nxt, 0, sizeof(nxt));
        memset(hide, 0, sizeof(hide));
        memset(same, 0, sizeof(same));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            process(i, s[i]);
        }
        printf("Case #%d: %d\n", cas, solve());
    }
    return 0;
}
