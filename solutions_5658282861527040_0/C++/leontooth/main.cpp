// =========================================================
//
//       Filename:  New Lottery Game
//
//    Description:
//
//        Version:  1.0
//        Created:  05/03/2014
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  Tao Lin, tlin005@gmail.com
//        Company:  CGG
//      Copyright:  Copyright (c) 05/03/2014
//
// =========================================================

#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

long long int solve(long long int A, long long int B, long long int K)
{
    long long int result = 0;

    long long int a, b;

    for (a = 0; a < A; ++a)
        for (b = 0; b < B; ++b)
        {
            if ((a&b) < K)
                result ++;
        }

    return result;
}

int main()
{
    // load input
    unsigned int case_no;
    cin >> case_no;

    for (unsigned int t = 0; t < case_no; ++t)
    {
        long long int A, B, K;
        cin >> A >> B >> K;

        // sove problem
        long long int result;
        result = solve(A, B, K);

        cout << "Case #" << t+1 << ": ";
        cout << result << endl;
    }

    return 0;

}
