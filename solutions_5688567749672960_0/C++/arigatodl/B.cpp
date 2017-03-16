#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define mx 1000000

int dp[mx + 10];

int inverse(int a) {
    queue <int> V;
    while (a > 0) {
        V.push(a % 10);
        a /= 10;
    }
    
    int ret = 0;
    while (!V.empty()) {
        ret = ret * 10 + V.front();
        V.pop();
    }
    return ret;
}

bool check(int a, int b) {
    if (a >= b) return 0;
    while (a > 0) {
        a /= 10;
        b /= 10;
    }
    
    if (b == 0) return 1;
    return 0;
}

int main() {
    cin.sync_with_stdio(false);
    
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int t;
    cin >> t;
    long long n, m;
    
    int i;
    for (i = 0; i <= 20; i++) {
        dp[i] = i;
    }
    
    for (i = 21; i <= mx; i++) {
        if (check(inverse(i), i)) {
            if (dp[inverse(i)] < dp[i-1]) dp[i] = dp[inverse(i)] + 1;
            else dp[i] = dp[i-1] + 1;
        }
        else dp[i] = dp[i-1] + 1;
        //cout << i << "|" << inverse(i) << ":" << dp[i] << endl;
    }
    int test_case = 0;
    while(t--) {
        cin >> n;
        
        test_case++;
        cout << "Case #" << test_case << ": " << dp[n] << endl;
    }
    
    return 0;
}
