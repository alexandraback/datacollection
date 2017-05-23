// =========================================================
//
//       Filename:  Manage your Energy
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

long long int solve(int E, int R, vector< int > v)
{
    vector< long long int > act[2];

    for (int i = 0; i <= E; ++i)
    {
        act[0].push_back(0);
        act[1].push_back(0);
    }

    for (int i = v.size()-1; i >= 0; --i)
    {
        for (int j = 0; j <= E; ++j)
        {
            act[i%2][j] = act[(i+1)%2][min(j+R, E)];
            for (int k = max(0, j+R-E); k <= min(R+j, E); ++k)
            {
                long long foo = v[i]*k + act[(i+1)%2][j-k+R];
                if (foo > act[i%2][j])
                    act[i%2][j] = foo;
            }
        }
    }

    return act[0][max(E-R, 0)];
}

int main()
{
    unsigned int case_no;

    // load input
    cin >> case_no;

    for (unsigned int case_count = 0; case_count < case_no; ++case_count)
    {
        int E;
        int R;
        unsigned int N;
        vector< int > v;

        // load input
        cin >> E >> R >> N;
        v.clear();
        for (unsigned int i = 0; i < N; ++i)
        {
            int vi;
            cin >> vi;
            v.push_back(vi);
        }

        // sove problem
        long long int result = 0;
        result = solve(E, R, v);
        cout << "Case #" << case_count+1 << ": ";
        cout << result << endl;
    }

    return 0;

}
