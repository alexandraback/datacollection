#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define BARSUK_ALEXEY_PSKOV

int tests;
int k, l, s;
string K, L;
double mx_banana;
double ans;
double cnt;

int countBanana(string & a, string & b)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        bool ok = (i + b.size()) <= a.size();
        for (int j = 0; j < b.size() && ok; j++)
        {
            if (a[i + j] != b[j])
                ok &= false;
        }
        if (ok) res++;
    }

    return res;
}

void rec(string a)
{
    if (a.size() == s)
    {
        double r = countBanana(a, L);
        mx_banana = max(mx_banana, r);
        ans += r;
        cnt += 1.0;
        return;
    }

    for (int i = 0; i < K.size(); i++)
    {
        rec(a + K[i]);
    }
}

int main()
{
#ifdef BARSUK_ALEXEY_PSKOV
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> tests;
    cout << setprecision(7);
    for (int t = 1; t <= tests; t++)
    {
        cin >> k >> l >> s;
        cin >> K >> L;

        ans = 0.0;
        mx_banana = 0.0;
        cnt = 0.0;

        string a = "";
        rec(a);

        if (cnt > 1e-8)
        {
            ans = ans / cnt;
        }

        ans += 1e-8;
        cout << "Case #" << t << ": " << fixed << fabs(mx_banana - ans) << endl;
    }

    return 0;
}

