#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int reverse(int n) {
    int m = 0;
    while (n) {
        m += n%10;
        m *= 10;
        n /= 10;
    }
    return m/10;
}

const int big = pow(10,7);
vector<int> dp(big);

int min(int a, int b) {
    return a < b ? a : b;
}

void pre() {
    for (int i = 0; i < dp.size(); i++) {
        dp[i] = big;
    }
    for (int i = 0; i < dp.size(); i++) {
        if (i <= 20) {
            dp[i] = i; 
        } else {
            dp[i] = min(dp[i], dp[i-1]+1);
        }
        if (reverse(i) < big) {
            dp[reverse(i)] = min(dp[reverse(i)], dp[i]+1);
        }
    }
}

int testcase(int i) {
    int n;
    cin >> n;
    cout << "Case #" << i+1 << ": " << dp[n] << endl;
}

int main() {
    int q;
    pre();
    cin >> q;
    for (int i = 0; i < q; i++) {
        testcase(i);
    }
    return 0;
}

