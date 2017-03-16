#include <climits>
#include <algorithm>
#include <iostream>

#define rep(t, i, n) for (t i = 0; i < n; ++i)

using namespace std;

int const MAX = 1000;

int a[MAX], b[MAX];
bool ca[MAX], cb[MAX];

int nbs;

int dp[2000][2000];

int do_(int N, int stars)
{
    if (nbs == 0)
        return 0;

    int na = 0, nb = 0;
    for (int i = 0; i < N; ++i) {
        na = 2*na + ca[i];
        nb = 2*nb + cb[i];
    }
    if (dp[na][nb] != -1)
        return dp[na][nb];

    int result = INT_MAX - 100000;
    for (int i = 0; i < N; ++i) {
        if (!ca[i] && a[i] <= stars) {
            ca[i] = true;
            result = min(result, do_(N, stars+1) + 1);
            ca[i] = false;
        }
        if (!cb[i] && b[i] <= stars) {
            cb[i] = true;
            --nbs;
            result = min(result, do_(N, stars+2-ca[i]) + 1);
            ++nbs;
            cb[i] = false;
        }
    }
    return dp[na][nb] = result;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0, N; i < T && cin >> N; ++i) {
        rep (int, j, N)
            cin >> a[j] >> b[j];
        fill(ca, ca+MAX, false);
        fill(cb, cb+MAX, false);
        nbs = N;
        fill(&dp[0][0], &dp[0][0] + 2000*2000, -1);
        int result = do_(N, 0);
        if (result > 2000)
            std::cout << "Case #" << i+1 << ": " << "Too Bad" << '\n';
        else
            std::cout << "Case #" << i+1 << ": " << result << '\n';
    }
}
