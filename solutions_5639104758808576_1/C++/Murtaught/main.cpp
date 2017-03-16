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
        int s_max;
        string shyness;
        cin >> s_max >> shyness;

        int ans = 0;
        int standing = shyness[0] - '0';
        for (int i = 1; i <= s_max; ++i)
        {
            if (i > standing)
            {
                ans += (i - standing);
                standing = i;
            }

            standing += (shyness[i] - '0');
        }

        cout << "Case #" << test_case << ": " << ans << "\n";
    }

    return 0;
}
