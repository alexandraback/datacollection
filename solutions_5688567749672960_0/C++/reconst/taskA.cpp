#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

const int INF = 1000 * 1000 * 1000;

int n, ans = 0;

int get_minimal(int x)
{
    int res = 0;
    bool is_null = true;
    //cerr << x << " ";
    while (x) {
        if (is_null && x % 10 == 0) {
            return INF;
        }
        if (x % 10 != 0) {
            is_null = false;
        }
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

int dp[1000001];

int get_dp(int x)
{
    cerr << x << endl;
    if (dp[x] == -1) {
        if (x <= get_minimal(x)) {
            dp[x] = get_dp(x-1) + 1;
        }
        else {
            dp[x] = min(get_dp(x-1) + 1, get_dp(get_minimal(x)) + 1); }
    }
    //cerr << x << " " << dp[x] << endl;
    return dp[x];
}

int solve()
{
    int oldn = n;
    ans = 0;
    /*while (n > 1) {
        int next = get_minimal(n);
        //cerr << next << " " << n << endl;
        if (next > n - 1) {
            n = n - 1;
        } else {
            n = next;
        }
        ans++;
    }*/
    
    //cerr << get_minimal(2300);
    //cerr << dp[9998] << endl;
    //cerr << oldn << endl;
    //cerr << "!" << get_minimal(1001) << endl;
    //get_dp(oldn);
    //cerr << dp[oldn] << endl;
    ans = dp[oldn];
    //cerr << "==";
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    // freopen("???", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test_number;
    scanf("%d", &test_number);
    
    for (int i = 1; i <= 1000001; i++) {
        dp[i] = -1;
    }
    dp[1] = 1;
    
    for (int x = 2; x <= 1000001; x++) {
        if (dp[x] == -1) {
            if (x <= get_minimal(x)) {
                dp[x] = dp[x-1] + 1;
            }
            else {
                dp[x] = min(dp[x-1] + 1, dp[get_minimal(x)] + 1); }
        }
        //if (x < 35) {
        //    cerr << x << " " << dp[x] << endl;
        //}
    }


    for (int test_case = 0; test_case < test_number; test_case++) {
        cin >> n;
        solve();
        printf("Case #%d: %d\n", test_case + 1, ans);
    }
}