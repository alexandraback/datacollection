#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int a, n, b[128], done, ans;

int main()
{
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        cin >> a >> n;
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(b, b + n);

        if (a == 1)
        {
            printf("Case #%d: %d\n", tc, n);
            continue;
        }

        done = 0;
        ans = n;
        for (int i = 0; i < n; ++i)
        {
            while (a <= b[i])
            {
                a += a - 1;
                ++done;
            }
            a += b[i];
            ans = min(ans, done + n - i - 1);
        }

        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}
