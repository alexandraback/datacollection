#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int test = 0; test < t; test++)
    {
        int d;
        cin >> d;
        vector<int> p(d);
        for (int i = 0; i < d; i++)
            cin >> p[i];
        int pmax = 0;
        for (int i = 0; i < d; i++)
        {
            pmax = max(pmax, p[i]);
        }
        int res = 1791791791;
        for (int j = 1; j <= pmax; j++)
        {
            int ans = j;
            for (int i = 0; i < d; i++)
                ans += (p[i] - 1) / j;
            res = min(res, ans);
        }
        cout << "Case #" << test + 1 << ": " << res << endl;
    }
}
