#include <iostream>

using namespace std;

void solve(void)
{
    double c, f, x;
    cin >> c >> f >> x;

    double ans = 0;
    double v = 2;
    while ((x - c) * (v + f) > x * v)
    {
        ans += c / v;
        v += f;
    }
    ans += x / v;
    cout << ans << endl;
}

int main(void)
{
    cout << fixed;
    cout.precision(7);
    int numTest;
    cin >> numTest;
    for (int testCase = 1; testCase <= numTest; ++testCase)
    {
        cout << "Case #" << testCase << ": ";
        solve();
    }
    return 0;
}
