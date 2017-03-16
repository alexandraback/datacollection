#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#define MAXN 110
using namespace std;
typedef long long int LL;
LL a[MAXN], b[MAXN];
int A[MAXN], B[MAXN];
int N, M;
typedef pair < int , pair < int , pair <LL, LL> > > state;
map<state, LL> memo;
LL solve(int i, int j, LL lefta, LL leftb) {
    state s = make_pair(i, make_pair(j, make_pair(lefta, leftb)));
    if (memo.find(s) != memo.end()) return memo[s];
    LL &ret = memo[s];
    if (i == N) return ret = 0;
    if (j == M) return ret = 0;
    ret = 0;
    if (A[i] == B[j] && lefta > 0 && leftb > 0) {
        LL consume = min(lefta, leftb);
        ret = max(ret, consume + solve(i, j, lefta - consume, leftb - consume));
    } else {
        ret = max(ret, solve(i, j+1, lefta, b[j+1]));
        ret = max(ret, solve(i+1, j, a[i+1], leftb));
    }
    return ret;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        memo.clear();
        scanf("%d %d", &N, &M);
        int x, y;
        for (int i=0; i<N; i++) {
            scanf("%lld %d", &a[i], &A[i]);
        }
        for (int i=0; i<M; i++) {
            scanf("%lld %d", &b[i], &B[i]);
        }
        printf("Case #%d: %lld\n", kase, solve(0, 0, a[0], b[0]));
    }
    return 0;
}
