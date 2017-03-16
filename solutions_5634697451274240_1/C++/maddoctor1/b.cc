#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[111];
int dp[111][2];
int main() {
    int T, cas = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s); 
        dp[0][0] = dp[0][1] = 0;
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(s[i] == '-') {
                dp[i + 1][0] = min(dp[i][0], dp[i][1] + 1);
                dp[i + 1][1] = dp[i + 1][0] + 1;
            } else {
                dp[i + 1][1] = min(dp[i][1], dp[i][0] + 1);
                dp[i + 1][0] = dp[i + 1][1] + 1;
            }
        }
        printf("Case #%d: %d\n", ++cas, dp[len][1]);
    }
    return 0;
}
