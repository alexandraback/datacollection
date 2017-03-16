//
//  A.cpp
//  codejam2015
//
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

#if defined(CJ_INDIRECT_COMPILE)
#  define ENTRY_POINT A
#else
#  define ENTRY_POINT main
#endif

#define CASE_LABEL(i) "Case #" << to_string(i) << ": "

int ENTRY_POINT(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int test_num = 1; test_num <= T; ++test_num)
    {
        int smax;
        cin >> smax;
        vector<int> svec;
        for (int m=0; m<=smax; ++m)
        {
            char c;
            cin >> c;
            svec.push_back(c - '0');
        }
        int total_needed = 0;
        int people_standing = 0;
        for (int s = 0; s <= smax; ++s)
        {
            int num_needed = s - people_standing;
            if ( num_needed > 0 )
            {
                total_needed += num_needed;
                people_standing += num_needed;
            }
            people_standing += svec[s];
        }
        cout << CASE_LABEL(test_num) << total_needed << "\n";
    }
    return 0;
}
