#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int t = 1; t <= T; ++t)
    {
        int k, c, s;
        cin >> k >> c >> s;

        if(s * c < k)
        {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
            continue;
        }

        cout << "Case #" << t << ": ";
        int cnt = 0;
        for(int i = 0; i < s; ++i)
        {
            long long ans = cnt;
            ++cnt;
            cnt %= k;
            for(int j = 1; j < c; ++j)
            {
                ans *= k;
                ans += cnt;
                ++cnt;
                cnt %= k;
            }
            cout << ans + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}