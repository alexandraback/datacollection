#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long llg;

const int N = 1000005;
char str[N];
int T, n, len, sum[N];
llg dp[N][2];
inline bool check(char c) {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')  return  false;
    else  return  true;
}
void run() {
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++) {
        scanf("%s %d", str, &n);
        sum[0] = 0;
        dp[0][0] = dp[0][1] = 0;
        len = strlen(str);
        for(int i = 1; i <= len; i++) {
            if(check(str[i-1]))  sum[i] = sum[i-1]+1;
            else  sum[i] = 0;
            dp[i][0] = dp[i][1] = 0;
        }
        for(int i = 1; i <= len; i++) {
            if(sum[i] >= n)  dp[i][1] = i-n+1;
            else  dp[i][0] = dp[i-1][0]+dp[i-1][1];
        }
        llg ans = 0;
        for(int i = 1; i <= len; i++)  ans += (dp[i][0]+dp[i][1]);
        printf("Case #%d: %lld\n", Case, ans);
    }
}

int main() {
    freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	run();
	return  0;
}















