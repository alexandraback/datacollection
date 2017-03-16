#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 1000005
#define LL long long

bool tag[200];

void init() {
    char ss[10] = "aeiou";
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i < 5; ++i)
        tag[ ss[i] ] = true;
}

int n, m;
char s[N];
int sum[N], nxt[N];
bool ok[N];

LL solve() {
    scanf("%s", s + 1);
    scanf("%d", &m);
    n = strlen(s + 1);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + (!tag[ s[i] ]);
    memset(ok, 0, sizeof(ok));
    for (int i = n - m + 1; i >= 1; --i)
        ok[i] = (sum[i + m - 1] - sum[i - 1]) == m;
    int pre = n + 1;
    for (int i = n; i >= 0; --i) {
        nxt[i] = pre;
        if (ok[i])
            pre = i;
    }

    LL ret = 0;
    int left = 0;
    for (int i = 1; i <= n; ++i) {
        while (left + m <= i && nxt[left] + m - 1 <= i) ++left;
        if (i - left + 1 >= m)
            ret += left;
    }
    return ret;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    init();
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
        printf("Case #%d: %lld\n", ++cas, solve());
    return 0;
}
