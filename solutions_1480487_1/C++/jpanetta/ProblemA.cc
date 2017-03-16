////////////////////////////////////////////////////////////////////////////////
// ProblemA.cc
////////////////////////////////////////////////////////////////////////////////
/*! @file
//        Solves Google Code Jam 2012 Round 1B Problem A
*/ 
//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University
//  Created:  05/05/2012 11:58:29
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
/*! Program entry point
//  @param[in]  argc    Number of arguments
//  @param[in]  argv    Argument strings
//  @return     status  (0 on sucess)
*///////////////////////////////////////////////////////////////////////////////
int main(int argc, const char *argv[])
{
    int numTests;
    cin >> numTests;
    for (int t = 1; t <= numTests; ++t)  {
        int N;
        cin >> N;
        vector<int> S(N);
        int X = 0;
        for (unsigned int i = 0; i < N; ++i) {
            cin >> S[i];
            X += S[i];
        }

        // Find the maximum score M to which all contestants could possibly be
        // raised with X. Then find the y_i that puts contestant i above it:
        //  s_i + y_i X = M  ==> y_i = max((M - s_i) / X, 0)
        vector<int> SortedS(S);
        sort(SortedS.begin(), SortedS.end());

        double M = 0;
        int A = 0; // integral of S over 0..i
        for (unsigned int i = 0; i < N; ++i) {
            A += SortedS[i];
            M = (X + A) / ((double) (i + 1));
            if ((i < N - 1) && (M < SortedS[i + 1]))
                break;
        }

        cout << setprecision (9);
        cout << "Case #" << t << ": ";
        for (unsigned int i = 0; i < N; ++i) {
            cout << 100 * max((M - S[i]) / X, 0.0);
            if (i != N - 1)
                cout << " ";
        }

        // SOLUTION OUTPUT
        cout << endl;
    }

    return 0;
}
