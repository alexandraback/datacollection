#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream inf("Input.txt");
ofstream outf("Output.txt");

int main() {
    int T; inf >> T;
    for (int tc = 1; tc <= T; tc++) {
        outf << "Case #" << tc << ": ";
        long long A;
        int N;
        inf >> A >> N;
        int m[110];
        for (int i = 0; i < N; i++)
            inf >> m[i];
        if (A == 1) {
            outf << N << "\n";
            continue;
        }
        sort(m, m+N);
        pair<long long,int> dp[110][2];
        dp[0][0] = dp[0][1] = make_pair(A,0);
        for (int i = 0; i < N; i++) {
            long long a = dp[i][0].first;
            int  t = 0;
            while (a <= m[i]) a += a-1, t++;
            int a1 = dp[i][1].first, t1 = 0;
            while (a1 <= m[i]) a1 += a1-1, t1++;
            if (dp[i][0].second+t < dp[i][1].second+t1)
                dp[i+1][0] = make_pair(a+m[i], dp[i][0].second+t);
            else dp[i+1][0] = make_pair(a1+m[i], dp[i][1].second+t1);
            if (dp[i][0].second < dp[i][1].second)
                dp[i+1][1] = make_pair(dp[i][0].first, dp[i][0].second+1);
            else dp[i+1][1] = make_pair(dp[i][1].first, dp[i][1].second+1);
        }
        outf << min(dp[N][0].second, dp[N][1].second) << "\n";
        /*int ans = 0;
        int cm = 1000000000;
        for (int i = 0; i < N; i++) {
            if (m[i] < A) A += m[i];
            else {
                int t = 0;
                if (A == 1) t = 1000000000;
                else while (A <= m[i]) A += A-1, t++;
                cm = min(cm, ans+N-i);
                ans += t;
            }
            ans = min(ans, cm);
        }
        */
        //outf << ans << "\n";
    }
}
