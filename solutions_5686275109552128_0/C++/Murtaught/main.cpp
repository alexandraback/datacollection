#include <bits/stdc++.h>
using namespace std;
#define print_out(x) cout << "print_out: " << #x << " == " << x << endl;
#define sz(x) int((x).size())
#define pb(x) push_back(x)
#define F first
#define S second
#define whole(a) a.begin(), a.end()
#define FOR(i, N) for (int i = 0; i < N; ++i)
typedef long long int int64;
typedef unsigned int uint;


int splits(int M, int n)
{
    if (M <= n)
        return 0;

    int mult = M / n + (M % n > 0);
    int ans = min(mult - 1, 1 + 2 * splits((M >> 1) + (M&1), n));

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    int cases_amount;
    cin >> cases_amount;

    for (int test_case = 1; test_case <= cases_amount; ++test_case)
    {
        int n; cin >> n;
        vector<int> p(n);
        FOR(i, n)
            cin >> p[i];

        // ---

        sort(whole(p));

        int max_p = p.back();
        int ans   = max_p;

        for (int wp = 1; wp < max_p; ++wp)
        {
            int s = 0;

            FOR(i, n)
            {
                s += splits(p[i], wp);
            }

            ans = min(ans, wp + s);
        }

        cout << "Case #" << test_case << ": " << ans << "\n";
    }

    return 0;
}
