#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

int dp[21][21] = {0};

int min(int a, int b) {
    return a<b?a:b;
}
int max(int a, int b) {
    return a>b?a:b;
}

void populate() {
    //dp[w,c]
    for (int i = 0; i < 21; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
        dp[i][i] = i;
    }
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            int small = 999;
            for (int k = 0; k < j; k++) {
                int best = 0;
                best = max(best, 1 + dp[i][k] + dp[i][j-k-1]); 
                if (k == 0 or k == j - 1)
                    best = max(best, i);
                else 
                    best = max(best, i+1);
                small = min(best, small); 
            }
            if (i > j) small = 0;
            dp[i][j] = small;
        }
    }

}

void testcase(int n) {
    int answer;
    int r,c,w;
    cin >> r >> c >> w;
    cout << "Case #" << n << ": " << dp[w][c] + (r-1)*(c/w) << endl;
}

int main() {
    int t;
    cin >> t;
    populate();
    for (int i = 0; i < t; i++) {
        testcase(i+1);
    }
}
