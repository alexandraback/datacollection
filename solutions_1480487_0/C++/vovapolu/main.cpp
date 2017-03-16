#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int t;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        int n, sum = 0;
        vector <int> a;
        cin >> n;
        a.resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            sum += a[j];
        }

        double val = double(2 * sum) / double(n);
        int cnt = 0;
        int newsum = 0;
        for (int j = 0; j < n; j++)
            if (a[j] <= val)
            {
                cnt++;
                newsum += a[j];
            }

        for (int j = 0; j < n; j++)
        {
            double k;
            if (a[j] > val)
                k = 0;
            else
                k = double(sum  + newsum - a[j] * cnt) / double(cnt * sum);

            printf("%0.10lf ", k * 100);
        }
        cout << endl;
    }
    return 0;
}
