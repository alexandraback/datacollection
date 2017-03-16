#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define INF 1 << 30;
#define MAX 10100100


int N;
unsigned int dp[MAX];


inline int swap(int i) {
    int o = 0;
    for (;i > 0; i /= 10) {
        o *= 10;
        o += (i%10);
    }
    return o;
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        /* cout << tc << ' ' << swap(tc) << endl; */
        /* continue; */
        cin >> N;
        memset(dp, -1, sizeof(dp));

        dp[1] = 1;
        for (int i = 1; i < N; i++) {
            int swapped = swap(i);
            dp[swapped] = min(dp[i]+1, dp[swapped]);
            dp[i+1] = min(dp[i]+1, dp[i+1]);
        }

        int res = dp[N];
        cout << "Case #" << tc << ": " << res << endl;
    }
    return 0;
}
