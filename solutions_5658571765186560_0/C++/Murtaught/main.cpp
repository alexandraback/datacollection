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
        int x, r, c;
        cin >> x >> r >> c;

        // ---

        bool ans = false; // can cover?

        switch (x)
        {
        case 1:
            ans = true;
            break;

        case 2:
            ans = (r % 2 == 0) || (c % 2 == 0);
            break;

        case 3:
            // {2, 3}, {3, 3}, {3, 4}
            if (r != 3)
                swap(r, c);

            ans = (r == 3) && (2 <= c && c <= 4);
            break;

        case 4:
        default:
            if (r > c)
                swap(r, c);

            ans = (c == 4) && (r >= 3);
            break;
        }

        cout << "Case #" << test_case << ": " << (ans ? "GABRIEL" : "RICHARD") << "\n";
    }

    return 0;
}
