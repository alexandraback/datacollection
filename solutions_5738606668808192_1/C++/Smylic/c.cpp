#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++)
    {
        int n, k;
        cin >> n >> k;

        cout << "Case #" << tt << ":" << endl;

        int d[32] = {};
        d[0] = 1;
        d[n/2 - 1] = 1;

        for (int i = 0; i < k; i++)
        {
            for (int z = 0; z < 2; z++)
                for (int j = 0; j < n / 2; j++)
                    cout << d[j];

            for (int b = 2; b <= 10; b++)
            {
                long long x = 0;

                for (int j = 0; j < n / 2; j++)
                    x = x * b + d[j];

                cout << " " << x;
            }

            cout << endl;

            d[n / 2 - 2]++;
            for (int j = n / 2 - 2; d[j] > 1; j--)
            {
                d[j] -= 2;
                d[j - 1]++;
            }
        }
    }

    return 0;
}
