#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("osmos.out", "w", stdout);
    int test = 0;
    cin >> test;
    for (int t = 1; t <= test; ++t)
    {
        int n, a, b[110];
        cin >> a >> n;
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(b, b + n);

        int res = n;
        if (a != 1)
        {
            for (int i = 0; i <= n; ++i)
            {
                int dem = i;
                long long nsize = a;
                for (int j = 0; j <= n - i - 1; ++j)
                {
                    while (nsize <= b[j])
                    {
                        dem++;
                        nsize += nsize - 1;
                    }
                    nsize += b[j];
                }
                if (dem < res)
                    res = dem;
            }
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
