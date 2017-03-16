#include <iostream>
#include <iomanip>

using namespace std;

double solve(int t)
{
    double C, F, X;
    cin >> C >> F >> X;

    double totalTime = 0.0;
    double rate = 2.0;

    if (X < C)
    {
        return X / rate;
    }

    for (;;)
    {
        double timeUntilFarm = C / rate;
        double timeUntilWinWithoutFarm = X / rate;
        double timeUntilWinWithFarm = timeUntilFarm + X / (rate + F);
        if (timeUntilWinWithoutFarm < timeUntilWinWithFarm)
        {
            totalTime += timeUntilWinWithoutFarm;
            return totalTime;
        }
        totalTime += timeUntilFarm;
        rate += F;
    }
}

int main()
{
    int T;
    cin >> T;

    cout << setprecision(16);
    for (int t = 1; t <= T; t++)
    {
        double result = solve(t);
        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}

