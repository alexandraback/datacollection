#include <iostream>

using namespace std;

typedef long long ll;

int n;
string a, b, sol0, sol1;

ll stoin(string x)
{
    ll a = 0;
    for (int i = 0; i < x.length(); i++) a = a * 10 + (x[i] - '0');
    return a;
}

void check(string x, string y)
{
    if (sol0 == "") sol0 = x, sol1 = y; else
    if (abs(stoin(x) - stoin(y)) < abs(stoin(sol0) - stoin(sol1))) sol0 = x, sol1 = y; else
    if (abs(stoin(x) - stoin(y)) == abs(stoin(sol0) - stoin(sol1)))
    {
        if (x < sol0) sol0 = x, sol1 = y; else
        if (x == sol0 && y < sol1) sol0 = x, sol1 = y;
    }
}

void nas(string x, string y, int p, bool f)
{
    if (p < n)
    {
        if (x[p] == '?')
        {
            if (y[p] == '?') x[p] = '1', y[p] = '0'; else
            {
                if (y[p] == '9') return;
                x[p] = y[p] + 1;
            }
        } else
        if (y[p] == '?')
        {
            if (x[p] == '0') return;
            y[p] = x[p] - 1;
        } else
        if (x[p] <= y[p]) return;
    }
    for (int i = p + 1; i < n; i++)
    {
        if (x[i] == '?') x[i] = '0';
        if (y[i] == '?') y[i] = '9';
    }
    if (!f) check(x, y); else
    check(y, x);
}

void solve(int test)
{
    cin >> a >> b;
    n = a.length();
    for (int i = 0; i <= n; i++)
    {
        string x = a, y = b;
        for (int j = 0; j < i; j++) if (x[j] == '?')
        {
            if (y[j] == '?') x[j] = y[j] = '0'; else
            x[j] = y[j];
        } else
        if (y[j] == '?') y[j] = x[j]; else
        if (y[j] != x[j]) goto bre;
        nas(x, y, i, 0);
        nas(y, x, i, 1);
        bre:;
    }
    cout << "Case #" << test << ": " << sol0 << " " << sol1 << endl;
    sol0 = sol1 = "";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
