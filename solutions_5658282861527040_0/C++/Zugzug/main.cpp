#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    freopen("2B1.in", "r", stdin);
    freopen("2B1.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < m; l++)
            {
                if ((j & l) < k)
                    ans++;
            }
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

}
