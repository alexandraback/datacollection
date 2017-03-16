#include <bits/stdc++.h>
using namespace std;
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wmissing-declarations"

#define FINAL_OUT(x) {cout << x << '\n'; exit(0);}

void solve(int numtest)
{
    cout << "Case #" << numtest << ": ";

    int k,c, s;
    cin >> k >> c >> s;

    if (s < (k + c - 1) / c)
        return void(cout << "IMPOSSIBLE\n");

    vector<long long> ans;


    for(int i = 0; i < k;)
    {
        long long cur = 0;
        for(int j = 0; j < c; ++i, ++j)
        {
            int y = min(i, k - 1);
            cur  = cur * k + y;
        }
        ans.push_back(cur + 1);
    }
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " \n"[i == ans.size() - 1];
}

int main()
{
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    for(int i = 1; i <= T; ++i)
        solve(i);

}

