

#include <cstdlib>
#include <cstdio>
#include <cassert>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;


int main(int argc, char ** argv)
{
    // read the tests count
    int T = 0;
    cin >> T;
    // run the test cases
    int t = 0;
    while (t < T)
    {
        ++t;
        // load the values
        double C, F, X;
        cin >> C;
        cin >> F;
        cin >> X;
        // solve
        // first, compute the minimum off the starting rate (cannot be worse)
        double timeMin = X / 2.0;
        // time to get N factories
        double timeN = 0.0;
        for (int N = 1; /* empty */; ++N)
        {
            // time to get N-the factory from 0 is C/((N -1) * F + 2.0)
            // plus the time to get (N-1)th factory
            timeN += C / (( N - 1) * F + 2.0);
            // time to get X with current N factories
            // - add the time to get the N factories
            const double timeX = X / (N * F + 2.0) + timeN;
            if (timeX < timeMin)
            {
                // found a new minimum
                timeMin = timeX;
            }
            else
            {
                // found the optimum - the time to get X with current N is greater than
                // or equat to the previous minimum
                break;
            }
        }
        // write out the result
        printf("Case #%d: %9.7f\n", t, timeMin);
    }
    return EXIT_SUCCESS;
}
