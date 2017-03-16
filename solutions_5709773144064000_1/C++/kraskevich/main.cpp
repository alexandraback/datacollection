#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = (int)1e7;

double dp[N];

void solve(int test)
{
    cerr << test << endl;
    cout << "Case #" << test << ": ";
    double c, f, x;
    cin >> c >> f >> x;
    for (int i = 0; i < N; i++) {
        dp[i] = c / (2.0 + i * f);
        if (i)
            dp[i] += dp[i - 1];
    }
    double res = x / 2.0;
    for (int i = 0; i < N; i++) {
        double cur = dp[i];
        cur += x / (2.0 + (i + 1) * f);
        res = min(res, cur);
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cout.setf(ios::fixed);
    cout.precision(7);

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    return 0;
}
