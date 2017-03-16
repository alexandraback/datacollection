//#pragma comment (linker, "/STACK:263108864")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long li;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const li lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

int TESTS = -1, TEST_NOW = 1;

char desk[100][100];
int m, r, c;

void start ()
{
    freopen ("problem.in", "r", stdin);
    freopen ("problem.out", "w", stdout);
    cin >> TESTS;
}

int main ()
{
    if (TESTS < 0)
        start ();
    if (TEST_NOW > TESTS)
        return 0;
    cout << "Case #" << TEST_NOW << ":\n";

    cin >> r >> c >> m;
    if (m == 0)
    {
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
                if (i || j)
                    cout << '.';
                else cout << 'c';
            cout << "\n";
        }
        goto case_end;
    }
    for (int i = 0 ; i < r ; ++i)
        for (int j = 0 ; j < c ; ++j)
            desk[i][j] = '*';
    if (m + 1 == r * c)
    {
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                if (i || j)
                    cout << '*';
                else
                    cout << 'c';
            }
            cout << "\n";
        }
        goto case_end;
    }
    if (r == 1)
    {
        for (int i = 0 ; i < c ; ++i)
        {
            if (i < m)
                cout << '*';
            else if (i < c - 1)
                cout << '.';
            else
                cout << 'c';
        }
        cout << '\n';
        goto case_end;
    }
    if (c == 1)
    {
        for (int i = 0 ; i < r ; ++i)
        {
            if (i < m)
                cout << '*';
            else if (i < r - 1)
                cout << '.';
            else
                cout << 'c';
            cout << '\n';
        }
        goto case_end;
    }
    if (r == 2)
    {
        if (m + 2 == r * c || m % 2)
        {
            cout << "Impossible\n";
            goto case_end;
        }
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                if (j < m / 2)
                    cout << '*';
                else if (i == r - 1 && j == c - 1)
                    cout << 'c';
                else
                    cout << '.';
            }
            cout << "\n";
        }
        goto case_end;
    }
    if (c == 2)
    {
        if (m + 2 == r * c || m % 2)
        {
            cout << "Impossible\n";
            goto case_end;
        }
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                if (i < m / 2)
                    cout << '*';
                else if (i == r - 1 && j == c - 1)
                    cout << 'c';
                else
                    cout << '.';
            }
            cout << "\n";
        }
        goto case_end;
    }
    if (m + 2 == r * c || m + 3 == r * c || m + 5 == r * c || m + 7 == r * c)
    {
        cout << "Impossible\n";
        goto case_end;
    }
    if (c == 3)
    {
        for (int i = 0 ; i < r ; ++i)
        {
            for (int j = 0 ; j < c ; ++j)
            {
                if (i < m / 3)
                    cout << '*';
                else if (i == m / 3 && j == 0 && m % 3)
                    cout << '*';
                else if (i == m / 3 + 1 && j == 0 && m % 3 == 2)
                    cout << '*';
                else if (i == r - 1 && j == c - 1)
                    cout << 'c';
                else
                    cout << '.';
            }
            cout << '\n';
        }
        goto case_end;
    }
    m = r * c - m;
    if (m >= 3 * c)
    {
        if (m % c == 0 || m % c == c - 1)
        {
            for (int i = 0 ; i < r ; ++i)
            {
                for (int j = 0 ; j < c ; ++j)
                {
                    if (i == 0 && j == 0)
                        cout << 'c';
                    else if (i < m / c)
                        cout << '.';
                    else
                        if (i == m / c && m % c == c - 1 && j < c - 1)
                            cout << '.';
                        else
                            cout << '*';
                }
                cout << '\n';
            }
            goto case_end;
        }
        else
        {
            for (int i = 0 ; i < r ; ++i)
            {
                for (int j = 0 ; j < c ; ++j)
                {
                    if (i == 0 && j == 0)
                        cout << 'c';
                    else if (i < m / c)
                    {
                        if (i == m / c - 1 && j == c - 1)
                            cout << '*';
                        else
                            cout << '.';
                    }
                    else if (i == m / c)
                    {
                        if (j <= m % c)
                            cout << '.';
                        else
                            cout << '*';
                    }
                    else
                        cout << '*';
                }
                cout << "\n";
            }
            goto case_end;
        }
    }
    else
    {
        if (m % 3 == 0)
        {
            for (int i = 0 ; i < r ; ++i)
            {
                for (int j = 0 ; j < c ; ++j)
                {
                    if (i == 0 && j == 0)
                        cout << 'c';
                    else if (j < m / 3 && i < 3)
                        cout << '.';
                    else
                        cout << '*';
                }
                cout << "\n";
            }
            goto case_end;
        }
        else if (m % 3 == 1)
        {
            for (int i = 0 ; i < r ; ++i)
            {
                for (int j = 0 ; j < c ; ++j)
                {
                    if (i == 0 && j == 0)
                        cout << 'c';
                    else if (j < (m - 4) / 3 && i < 3)
                        cout << '.';
                    else if (j <= (m - 1) / 3 && i < 2)
                        cout << '.';
                    else
                        cout << '*';
                }
                cout << "\n";
            }
            goto case_end;
        }
        else
        {
            for (int i = 0 ; i < r ; ++i)
            {
                for (int j = 0 ; j < c ; ++j)
                {
                    if (i == 0 && j == 0)
                        cout << 'c';
                    else if (j < (m - 2) / 3 && i < 3)
                        cout << '.';
                    else if (j == (m - 2) / 3 && i < 2)
                        cout << '.';
                    else
                        cout << '*';
                }
                cout << "\n";
            }
        }
    }

case_end:
    ++TEST_NOW;
    main ();
}
