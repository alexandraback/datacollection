#include <bits/stdc++.h>

using namespace std;

int n;
int v[2505];
int main()
{
    int t;
    cin >> t;

    for (int ti = 0; ti < t; ti++)
    {
        memset(v, 0, sizeof(v));
        cout << "Case #" << ti + 1 << ": ";

        cin >> n;

        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int in;
                cin >> in;
                v[in]++;
            }

        }

        for (int i = 0; i <= 2500; i++)
        {
            if (v[i] % 2) cout << i << " ";
        }
        cout << endl;
    }
}


