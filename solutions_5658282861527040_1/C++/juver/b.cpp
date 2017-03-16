#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

i64 dp[50][2][2][2];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;

    FOR (testId, tests) {
        int a, b, k;
        cin >> a >> b >> k;

        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;
        FOR (i, 32) {
            int const p = 31 - i;
            FOR (lessA, 2) FOR (lessB, 2) FOR (lessK, 2) {
                int const bitA = (a >> p) & 1;
                int const bitB = (b >> p) & 1;
                int const bitK = (k >> p) & 1;

                FOR (newBitA, 2) FOR (newBitB, 2) {
                    int const newBitK = newBitA & newBitB;
                    if (!lessA && newBitA > bitA) continue;
                    if (!lessB && newBitB > bitB) continue;
                    if (!lessK && newBitK > bitK) continue;

                    bool const newLessA = lessA || newBitA < bitA;
                    bool const newLessB = lessB || newBitB < bitB;
                    bool const newLessK = lessK || newBitK < bitK;
                    dp[i + 1][newLessA][newLessB][newLessK] += dp[i][lessA][lessB][lessK];
                }
            }
        }

        i64 cnt = dp[32][1][1][1];
        cout << "Case #" << testId + 1 << ": " << cnt << endl;
    }

    return 0;
}
