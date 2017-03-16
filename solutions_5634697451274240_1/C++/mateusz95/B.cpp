#include <bits/stdc++.h>

using namespace std;

const int N = 100;

char pancake[N + 5];
int dp[N + 5][2];

void test() {
    scanf("%s", &pancake[1]);
    int n = strlen(pancake + 1);
    for (int i = 1; i <= n; i++) {
        dp[i][0] = pancake[i] == '+' ? dp[i - 1][0] : dp[i - 1][1] + 1;
        dp[i][1] = pancake[i] == '-' ? dp[i - 1][1] : dp[i - 1][0] + 1;
    }
    printf("%d\n", dp[n][0]);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tests = 1; tests <= t; tests++) {
        printf("Case #%d: ", tests);
        test();
    }
    return 0;
}