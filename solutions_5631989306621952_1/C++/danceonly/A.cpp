#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
const int N = 1005;

string dp[N];
char str[N];

void work(int cas) {
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    dp[0] = "";
    for (int i = 1; i <= n; i++) {
        if (string(dp[i-1] + str[i]) < string(str[i] + dp[i-1])) {
            dp[i] = str[i] + dp[i-1];
        }else {
            dp[i] = dp[i-1] + str[i];
        }
    }
    printf("Case #%d: ", cas);
    cout << dp[n] << endl;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        work(cas);
    }
    return 0;
}
