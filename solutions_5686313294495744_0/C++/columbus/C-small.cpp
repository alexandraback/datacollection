#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)

using namespace std;

const int MAXN = 16;

string a[MAXN], b[MAXN];
int dp[1 << MAXN], n;

int f(int x) {
    if(dp[x] == -1) {
        dp[x] = 0;
        for(int i = 0; i < n; i++) {
            if(x & (1 << i)) {
                bool name1 = false, name2 = false;
                for(int j = 0; j < n; j++)
                    if(!(x & (1 << j))) name1 |= (a[i] == a[j]), name2 |= (b[i] == b[j]);
                if(name1 && name2) dp[x] = max(dp[x], f(x ^ (1 << i)) + 1);
                else dp[x] = max(dp[x], f(x ^ (1 << i)));
            }
        }
    }
    return dp[x];
}

void go() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < (1 << n); i++) dp[i] = -1;
    dp[0] = 0;
    printf("%d", f((1 << n) - 1));
}

int main() {
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++) {
        debug("Entering test %d\n", t);
        printf("Case #%d: ", t);
        go();
        printf("\n");
    }
    return 0;
}
