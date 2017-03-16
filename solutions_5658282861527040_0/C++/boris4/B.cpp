#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int A, B, K;

int dp[40][4];
int dp2[40][4];

int main() {
    int tests; cin >> tests;
    for (int test_id = 1; test_id <= tests; ++test_id) {
        cout << "Case #" << test_id << ": ";
        cin >> A >> B >> K; A--; B--; K--;
        memset(dp, 0, sizeof(dp)); 
        memset(dp2, 0, sizeof(dp2));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
        dp2[0][0] = dp2[0][1] = dp2[0][2] = dp2[0][3] = 1;
        for (int i = 1; i <= 32; ++i) {
            int bitA = (A >> (i - 1)) & 1;
            int bitB = (B >> (i - 1)) & 1;
            int bitK = (K >> (i - 1)) & 1;

                // 1, 1
                dp2[i][0] += (bitA == 1 && bitB == 1) * dp2[i - 1][0];
                dp2[i][1] += (bitB == 1) * dp2[i - 1][1];
                dp2[i][2] += (bitA == 1) * dp2[i - 1][2];
                dp2[i][3] += dp2[i - 1][3];

                // 1, 0
                dp2[i][0] += (bitA == 1) * dp2[i - 1][2 * bitB];
                dp2[i][1] += dp2[i - 1][2 * bitB + 1];
                dp2[i][2] += (bitA == 1) * dp2[i - 1][2];
                dp2[i][3] += dp2[i - 1][3];

                // 0, 1
                dp2[i][0] += (bitB == 1) * dp2[i - 1][bitA];
                dp2[i][1] += (bitB == 1) * dp2[i - 1][1];
                dp2[i][2] += dp2[i - 1][2 + bitA];
                dp2[i][3] += dp2[i - 1][3];

                // 0, 0
                dp2[i][0] += dp2[i - 1][2 * bitB + bitA];
                dp2[i][1] += dp2[i - 1][2 * bitB + 1];
                dp2[i][2] += dp2[i - 1][2 + bitA];
                dp2[i][3] += dp2[i - 1][3];

            if (bitK == 1) {
                // 1, 1
                dp[i][0] += (bitA == 1 && bitB == 1) * dp[i - 1][0];
                dp[i][1] += (bitB == 1) * dp[i - 1][1];
                dp[i][2] += (bitA == 1) * dp[i - 1][2];
                dp[i][3] += dp[i - 1][3];

                // 1, 0
                dp[i][0] += (bitA == 1) * dp2[i - 1][2 * bitB];
                dp[i][1] += dp2[i - 1][2 * bitB + 1];
                dp[i][2] += (bitA == 1) * dp2[i - 1][2];
                dp[i][3] += dp2[i - 1][3];

                // 0, 1
                dp[i][0] += (bitB == 1) * dp2[i - 1][bitA];
                dp[i][1] += (bitB == 1) * dp2[i - 1][1];
                dp[i][2] += dp2[i - 1][2 + bitA];
                dp[i][3] += dp2[i - 1][3];

                // 0, 0
                dp[i][0] += dp2[i - 1][2 * bitB + bitA];
                dp[i][1] += dp2[i - 1][2 * bitB + 1];
                dp[i][2] += dp2[i - 1][2 + bitA];
                dp[i][3] += dp2[i - 1][3];
            } else {
                // 1, 0
                dp[i][0] += (bitA == 1) * dp[i - 1][2 * bitB];
                dp[i][1] += dp[i - 1][2 * bitB + 1];
                dp[i][2] += (bitA == 1) * dp[i - 1][2];
                dp[i][3] += dp[i - 1][3];

                // 0, 1
                dp[i][0] += (bitB == 1) * dp[i - 1][bitA];
                dp[i][1] += (bitB == 1) * dp[i - 1][1];
                dp[i][2] += dp[i - 1][2 + bitA];
                dp[i][3] += dp[i - 1][3];

                // 0, 0
                dp[i][0] += dp[i - 1][2 * bitB + bitA];
                dp[i][1] += dp[i - 1][2 * bitB + 1];
                dp[i][2] += dp[i - 1][2 + bitA];
                dp[i][3] += dp[i - 1][3];
            }
        }
        cout << dp[32][0] << endl;
    }
    return 0;
}