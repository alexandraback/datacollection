#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int scores[100];
int n, s, p;

int memo[101][101];
int doit(int cur, int rem) {
    if(cur == n) return 0;

    int& ret = memo[cur][rem];
    if(ret != -1) return ret;
    ret = doit(cur+1, rem);

    int judges[3];
    for(int i = 0; i < 3; i++)
        judges[i] = (scores[cur]+2-i)/3;

    if(judges[0] >= p)
        ret = doit(cur+1, rem) + 1;

    judges[0]++; judges[1]--;
    if(rem && judges[0]-judges[1] <= 2 && judges[1] >= 0 && judges[0] >= p)
        ret = max(ret, doit(cur+1, rem-1) + 1);

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        scanf("%d %d %d", &n, &s, &p);
        for(int i = 0; i < n; i++)
            scanf("%d", &scores[i]);

        memset(memo, -1, sizeof memo);
        printf("Case #%d: %d\n", z, doit(0, s));
    }
}
