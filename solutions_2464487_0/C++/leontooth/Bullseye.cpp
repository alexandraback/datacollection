// =========================================================
//
//       Filename:  Bullseye
//
//    Description:
//
//        Version:  1.0
//        Created:  04/26/2013
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  Tao Lin, tlin005@gmail.com
//        Company:  U of California Riverside
//      Copyright:  Copyright (c) 04/26/2013
//
// =========================================================

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

long long int solve(long long int r, long long int t)
{
    long long int low = 1;
    long long int high = 2E9;
    long long int mid = (low+high)/2;

    while (high > low)
    {
        mid = (low+high)/2;
        if ((2ll*mid+2ll*r-1-t/mid <= 0) && (2ll*(mid+1)+2ll*r-1-t/(mid+1) > 0))
            return mid;

        if (2ll*mid+2ll*r-1-t/mid > 0)
        {
            high = mid-1;
            mid = (low+high)/2;
        }
        else
        {
            low = mid+1;
            mid = (low+high)/2;
        }
    }

    return high;
}

int main()
{
    unsigned int case_no;

    // load input
    cin >> case_no;

    for (unsigned int case_count = 0; case_count < case_no; ++case_count)
    {
        long long int r;
        long long int t;

        // load input
        cin >> r >> t;

        // sove problem
        long long int result = 0;
        result = solve(r, t);
        cout << "Case #" << case_count+1 << ": ";
        cout << result << endl;
    }

    return 0;

}
