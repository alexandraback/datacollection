#include <iostream>
#include <cstring>

using namespace std;

char a[50][50];

void solve(void)
{
    int r, c, m;
    cin >> r >> c >> m;
    int n = r * c - m;
    memset(a, '*', sizeof(a));
    if (n == 1)
    {
        a[0][0] = 'c';
    }
    else if (r == 1)
    {
        a[0][0] = 'c';
        for (int i = 1; i < n; ++i)
        {
            a[0][i] = '.';
        }
    }
    else if (c == 1)
    {
        a[0][0] = 'c';
        for (int i = 1; i < n; ++i)
        {
            a[i][0] = '.';
        }
    }
    else if (r == 2)
    {
        if ((n > 2) && (n % 2 == 0))
        {
            n /= 2;
            for (int i = 0; i < n; ++i)
            {
                a[0][i] = a[1][i] = '.';
            }
            a[0][0] = 'c';
        }
        else
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    else if (c == 2)
    {
        if ((n > 2) && (n % 2 == 0))
        {
            n /= 2;
            for (int i = 0; i < n; ++i)
            {
                a[i][0] = a[i][1] = '.';
            }
            a[0][0] = 'c';
        }
        else
        {
            cout << "Impossible" << endl;
            return;
        }
    }
    else
    {
        if ((n == 4) || (n == 6) || (n >= 8))
        {
            if (n <= 3 * c)
            {
                int t = n / 3;
                for (int i = 0; i < t; ++i)
                {
                    a[0][i] = a[1][i] = a[2][i] = '.';
                }
                if (n % 3 == 2)
                {
                    a[0][t] = a[1][t] = '.';
                }
                if (n % 3 == 1)
                {
                    a[0][t] = a[1][t] = '.';
                    a[2][t - 1] = '*';
                }
                a[0][0] = 'c';
            }
            else
            {
                int t = n / c;
                for (int i = 0; i < t; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        a[i][j] = '.';
                    }
                }
                n %= c;
                for (int j = 0; j < n; ++j)
                {
                    a[t][j] = '.';
                }
                if (n == 1)
                {
                    a[t - 1][c - 1] = '*';
                    a[t][n] = '.';
                }
                a[0][0] = 'c';
            }
        }
        else
        {
            cout << "Impossible" << endl;
            return;
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main(void)
{
    cout << fixed;
    cout.precision(7);
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; ++testCase)
    {
        cout << "Case #" << testCase << ": " << endl;
        solve();
    }
    return 0;
}
