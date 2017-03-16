#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

void display(int row)
{
    cout << ' ' << row;
}

double result(double cost, double f, double target)
{
    double time=0.0;
    double rate=2.0;
    while(true)
    {
        double time_current = (target/rate);
        // Need to calculate cost of upgrade
        double time_upgrade = (cost/rate) + (target/(rate+f));
        if (time_current <= time_upgrade)
        {
            return time + time_current;
        }
        time += cost/rate;
        rate += f;
    }
}

int main(int argc, char* argv[])
{
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
    {
        cout << "Case #" << test << ": ";
        double c, f, x;
        cin >> c >> f >> x;
        cout << fixed << setprecision(7) << result(c, f, x) << endl;
    }
    return 0;
}
