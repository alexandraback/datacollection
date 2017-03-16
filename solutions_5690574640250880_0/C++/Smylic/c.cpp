#include <iostream>

using namespace std;

char a[64][64];

bool solve(int n, int m, int k)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            a[i][j] = '*';
        a[i][m] = 0;
    }

    a[0][0] = 'c';

    k = n * m - k;

    if (k == 1)
        return true;

    if (n == 1)
    {
        for (int j=1; j<k; j++)
            a[0][j] = '.';
        return true;
    }

    if (m == 1)
    {
        for (int i=1; i<k; i++)
            a[i][0] = '.';
        return true;
    }

    if (k <= 7 && k != 6 && k != 4)
        return false;

    if ((n == 2 || m == 2) && k & 1)
        return false;

    int i, j;

    for (i=0; i<n && k > 3; i++, k-=2)
    {
        a[i][!i] = '.';
        a[i][1] = '.';
    }

    if (k == 2 && i < n)
    {
        a[i][0] = '.';
        a[i][1] = '.';
        return true;
    }

    if (k == 3)
    {
        a[0][2] = '.';
        a[1][2] = '.';
        a[2][2] = '.';
        return true;
    }

    for (j=2; j<m && k > 2; j++)
        for (i=0; i<n && k > 2; i++, k--)
            a[i][j] = '.';

    if (i > n - 2)
    {
        a[0][j] = '.';
        a[1][j] = '.';
    }
    else
    {
        a[i][j-1] = '.';
        a[i+1][j-1] = '.';
    }

    return true;
}

int main()
{
    int t;
    cin >> t;

    for (int tt=1; tt<=t; tt++)
    {
        int n, m, k;
        cin >> n >> m >> k;

        bool ok = solve(n, m, k);

        cout << "Case #" << tt << ":" << endl;
        if (ok)
            for (int i=0; i<n; i++)
                cout << a[i] << endl;
        else
            cout << "Impossible" << endl;

    }
    return 0;
}
