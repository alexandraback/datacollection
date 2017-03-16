#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    double C, F, X, CI = 2;
    cin >> C >> F >> X;

    double minTime = X / CI, prevTime = 0;

    for (;;)
    {
        prevTime += C / CI;
        CI += F;
        double newTime = prevTime + X / CI;
        if (newTime < minTime)
        {
            minTime = newTime;
        }
        else
        {
            break;
        }
    }
    cout << minTime << endl;
}

int main()
{
    int T;
    cin >> T;
    cout.setf(ios::floatfield, ios::fixed);
    cout.precision(7);

    for (int test = 1; test <= T; ++test)
    {
        cout << "Case #" << test << ": ";
        solve();
    }

    return 0;
}
