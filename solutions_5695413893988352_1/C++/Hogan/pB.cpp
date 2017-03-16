#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

char sa[20];
char sb[20];

long long ten[18];
int n;

long long ga;
long long gb;
long long gd;

void dfs(long long a, long long b, int t) {
    if (t == n) {
        if (abs(a-b) < gd) {
            gd = abs(a-b);
            ga = a;
            gb = b;
        } else if (abs(a-b) == gd) {
            if (a < ga) {
                ga = a;
                gb = b;
            } else if (a == ga) {
                gb = min(gb, b);
            }
        }
        return;
    }

    if (sa[t] == '?' and sb[t] == '?') {
        if (a < b) {
            dfs(a + ten[n-1-t] * 9, b, t+1);
        } else if (a > b) {
            dfs(a, b + ten[n-1-t] * 9, t+1);
        } else {
            dfs(a, b, t+1);
            dfs(a + ten[n-1-t] * 1, b, t+1);
            dfs(a, b + ten[n-1-t] * 1, t+1);
        }
    } else if (sa[t] == '?') {
        if (a < b) {
            dfs(a + ten[n-1-t] * 9, b + ten[n-1-t] * (sb[t] - '0'), t+1);
        } else if (a > b) {
            dfs(a + ten[n-1-t] * 0, b + ten[n-1-t] * (sb[t] - '0'), t+1);
        } else if (a == b) {
            dfs(a + ten[n-1-t] * (sb[t] - '0'), b + ten[n-1-t] * (sb[t] - '0'), t+1);
            dfs(a + ten[n-1-t] * min(sb[t] - '0' + 1, 9), b + ten[n-1-t] * (sb[t] - '0'), t+1);
            dfs(a + ten[n-1-t] * max(sb[t] - '0' - 1, 0), b + ten[n-1-t] * (sb[t] - '0'), t+1);
        }
    } else if (sb[t] == '?') {
        if (a < b) {
            dfs(a + ten[n-1-t] * (sa[t] - '0'), b + ten[n-1-t] * 0, t+1);
        } else if (a > b) {
            dfs(a + ten[n-1-t] * (sa[t] - '0'), b + ten[n-1-t] * 9, t+1);
        } else if (a == b) {
            dfs(a + ten[n-1-t] * (sa[t] - '0'), b + ten[n-1-t] * (sa[t] - '0'), t+1);
            dfs(a + ten[n-1-t] * (sa[t] - '0'), b + ten[n-1-t] * min(sa[t] - '0' + 1, 9), t+1);
            dfs(a + ten[n-1-t] * (sa[t] - '0'), b + ten[n-1-t] * max(sa[t] - '0' - 1, 0), t+1);
        }
    } else {
        dfs(a + ten[n-1-t] * (sa[t] - '0'), b + ten[n-1-t] * (sb[t] - '0'), t+1); 
    }
}

int main() {
    ten[0] = 1;
    for (int i = 1; i < 18; i++) {
        ten[i] = ten[i-1] * 10;
    }

    int t;
    scanf("%d", &t);

    for (int times = 0; times < t; times++) {
        scanf("%s%s", sa, sb); 
        n = strlen(sa);

        ga = LLONG_MAX;
        gb = LLONG_MAX;
        gd = LLONG_MAX;
        dfs(0, 0, 0);

        printf("Case #%d: ", times+1);

        char oa[20];
        sprintf(oa, "%lld", ga);
        for (int i = 0; i < n-strlen(oa); i++) {
            printf("0");
        }
        printf("%s ", oa);

        char ob[20];
        sprintf(ob, "%lld", gb);
        for (int i = 0; i < n-strlen(ob); i++) {
            printf("0");
        }
        printf("%s\n", ob);
    }
}
