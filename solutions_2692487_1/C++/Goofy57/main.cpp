#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define mp make_pair
using namespace std;

long long n;
long long a[10000];

int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    long long t;
    cin >> t;
    for (long long tc = 0; tc < t; tc++)
    {
        long long sz;
        cin >> sz >> n;
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        long long ans = 1e9;
        for (long long del = 0; del <= n; del++)
        {
            long long s = sz;
            long long cur = del;
            for (long long i = 0; i < n - del; i++)
            {
                if (a[i] < s) s += a[i];
                else
                {
                    if (s == 1) i = n - del - 1, cur = 1e9;
                    else
                    {
                        while (s <= a[i])
                        {
                            cur++;
                            s += s - 1;
                        }
                        s += a[i];
                    }
                }
            }
            ans = min(ans, cur);
        }

        cout << "Case #" << tc + 1 << ": " << ans << endl;
    }


    return 0;
}
