////////////////////////////////////////////////////////////////////////////////
// ProblemC.cc
////////////////////////////////////////////////////////////////////////////////
/*! @file
//        Solves Google Code Jam 2012 Round 1C Problem B
*/ 
//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University
//  Created:  05/06/2012 5:00:00
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <cfloat>
#include <cmath>
#include <cassert>

using namespace std;
typedef unsigned int uint;
typedef unsigned long int uli;

////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on sucess)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[])
{
    int T; cin >> T;
    for (int test = 1; test <= T; ++test)  {
        double D;
        unsigned int N, A;
        cin >> D >> N >> A;
        vector<double> t(N), x(N), a(A);

        for (unsigned int i = 0; i < N; ++i) {
            cin >> t[i];
            cin >> x[i];
        }

        for (unsigned int i = 0; i < A; ++i) {
            cin >> a[i];
        }

        // Dumb small-case algorithm:
        // take min of time you take to get home
        // and car takes to get home

        // Your dist: 1/2a * t^2 -> t = sqrt(2D / a)
        // Other car dist: x_0 + v t -> t = (D - x_0) / v
        //          where v = (x_1 - x_0) / t_1
        cout << setprecision(9);

        cout << "Case #" << test << ":" << endl;
        for (unsigned int i = 0; i < A; ++i) {
            double t_noBreak = sqrt(2 * D / a[i]);
            if (N == 1) {
                assert(x[0] >= D);
                cout << t_noBreak << endl;
            }
            else {
                assert(N == 2);
                double v = (x[1] - x[0]) / t[1];
                double t_block = (D - x[0]) / v;
                cout << max(t_noBreak, t_block) << endl;
            }
        }
    }
    return 0;
}
