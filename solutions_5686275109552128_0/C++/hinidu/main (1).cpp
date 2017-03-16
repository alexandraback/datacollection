#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test)
    {
        int d;
        cin >> d;
        vector<int> v(d);
        int ans = 0;
        for (int i = 0; i < d; ++i)
        {
            scanf("%d", &v[i]);
            ans = max(ans, v[i]);
        }
        for (int i = 1; i < ans; ++i)
        {
            int cnt = i;
            for (int j = 0; j < d; ++j)
                cnt += (v[j] + i - 1) / i - 1;
            ans = min(ans, cnt);
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}