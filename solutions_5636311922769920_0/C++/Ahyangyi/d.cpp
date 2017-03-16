#include <iostream>

using namespace std;

void solve(int k, int c, int s)
{
    if (s * c < k)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int i = 0; i < k; i += c)
        {
            long long x = 0;
            for (int j = 0; j < c; j ++)
                x = x * k + (i + j) % k;
            cout << " " << x + 1;
        }
        cout << endl;
    }
}

int main()
{
    int ct, t;

    cin >> t;
    for (ct = 1; ct <= t; ct ++)
    {
        int k, c;
        int s;

        cin >> k >> c >> s;
        cout << "Case #" << ct << ": ";
        solve(k, c, s);
    }

    return 0;
}
