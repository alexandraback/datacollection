#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        long long k, c, s;

        cin >> k >> c >> s;
        cout << "Case #" << tt << ": ";

        if (k > s * c)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        long long x = 0;
        int j = 0;

        for (int p = 0; p < k; p++, j++)
        {
            if (j == c)
            {
                cout << x + 1 << " ";
                j = 0;
                x = 0;
            }

            x = x * k + p;
        }

        for (; j < c; j++)
            x *= k;

        cout << x + 1 << endl;
    }

    return 0;
}
