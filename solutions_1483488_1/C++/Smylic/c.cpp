#include <iostream>
#include <vector>

using namespace std;

vector<int> p[1<<21];

int main()
{
    for (int i=1; i <= 2000000; i++)
    {
        int y = 1;
        for (; y < i; y *= 10);

        for (int x = 10; x < i; x *= 10)
            if (i / (x / 10) % 10 != 0)
            {
                int j = i / x + i % x * (y / x);

                if (j < i)
                    p[i].push_back(j);
            }

        sort(p[i].begin(), p[i].end());
        p[i].resize(unique(p[i].begin(), p[i].end()) - p[i].begin());
        reverse(p[i].begin(), p[i].end());
    }

    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int ans = 0;

        int a, b;
        cin >> a >> b;

        for (int i=a; i<=b; i++)
            for (int j=0; j<p[i].size() && p[i][j] >= a; j++)
                ans++;

        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}
