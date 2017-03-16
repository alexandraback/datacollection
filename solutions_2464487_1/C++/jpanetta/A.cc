////////////////////////////////////////////////////////////////////////////////
// 1.cc
////////////////////////////////////////////////////////////////////////////////
/*! @file
//      Solves Google Code Jam QR Problem 1
*/ 
//  Author:  Julian Panetta (jpanetta), julian.panetta@gmail.com
//  Company:  New York University
//
//  Created:  04/13/2013 17:06:15
//  Revision History:
//      04/13/2013  Julian Panetta    Initial Revision
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cassert>

using namespace std;

inline size_t paintRequired(size_t r, size_t n)
{
    // Paint required for n rings: (2 * r + 1) * n + 2 * n * (n - 1)
    return (2 * r + 1) * n + 2 * n * (n - 1);
}

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
    char dummy;
    for (int test = 1; test <= numTests; ++test)  {
        size_t r, t;
        cin >> r >> t;
        // Find the largest n such that paint required <= t
        size_t lower = 1;
        size_t upper = 1;
        while (paintRequired(r, upper) < t) {
            lower = upper;
            upper *= 2;
        }


        // Binary search on [lower, upper]
        while (lower != upper) {
            size_t mid = (lower + upper) / 2;
            if (paintRequired(r, mid) > t) {
                upper = mid;
            }
            else {
                // Handle tricky end case
                if (upper == (lower + 1)) {
                    if (paintRequired(r, upper) > t)
                        upper = lower;
                    else
                        lower = upper;
                }
                else lower = mid;
            }
        }
        
        cout << "Case #" << test << ": " << lower << endl;
    }

    return 0;
}
