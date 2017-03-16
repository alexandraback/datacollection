#include <iostream>
#include <iomanip>

using namespace std;

const double BASE_RATE = 2.0;
const double INF = 1.0 / 0.0;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios_base::scientific, ios_base::floatfield);
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        double C, F, X;
        cin >> C >> F >> X;
        double best = INF;
        double now = 0.0;
        double rate = BASE_RATE;
        while (now < best)
        {
            double time = now + X / rate;
            if (time < best)
                best = time;
            now += C / rate;
            rate += F;
        }
        cout << "Case #" << testcase << ": " << setprecision(16) << best << "\n";
    }
    return 0;
}
