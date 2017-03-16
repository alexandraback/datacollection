#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int arr[500];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        long long a;
        cin >> a >> n;
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        sort(arr, arr + n);

        if (a == 1)
        {
            cout << "Case #" << i + 1 << ": " << n << endl;
            continue;
        }

        int minval = 1000 * 1000 * 1000;
        for (int j = 0; j <= n; j++)
        {
            long long newa = a;
            int val = j;
            for (int l = 0; l < n - j; l++)
            {
                if (newa > arr[l])
                    newa += arr[l];
                else
                {
                    while(newa <= arr[l])
                    {
                        newa = 2 * newa - 1;
                        val++;
                    }
                    newa += arr[l];
                }
            }
            minval = min(minval, val);
        }

        cout << "Case #" << i + 1 << ": " << minval << endl;
    }
    return 0;
}
