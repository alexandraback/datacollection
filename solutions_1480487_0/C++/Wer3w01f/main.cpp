///////////////////////////////////////////////////////////////////////
/////    The code is written for Google Code Jam 2011 contest.    /////
/////    You may use any part of this code without exception.     /////
/////    The author is not responsible for any consequences       /////
/////    of using this code.                                      /////
/////                                                             /////
/////    Author: Andrey Rubtsov                                   /////
///////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <hash_map>
#include <hash_set>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <strstream>
#include <utility>
#include <valarray>
#include <vector>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PROBLEM_NAME "A"
#define LARGE_INPUT 0

#if LARGE_INPUT
    #define INPUT_FILE PROBLEM_NAME "-large.in"
    #define OUTPUT_FILE PROBLEM_NAME "-large.out"
#else
    #define INPUT_FILE PROBLEM_NAME "-small-attempt3.in"
    #define OUTPUT_FILE PROBLEM_NAME "-small.out"
#endif

int main()
{
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N;
        int X = 0;
        cin >> N;
        int J[200];

        for (int i = 0; i < N; ++i)
        {
            cin >> J[i];
            X += J[i];
        }

        double max = (2. * X) / N;
        int out = 0;
        int outN = 0;
        int outX = 0;
            for (int i = 0; i < N; ++i)
            {
                if (J[i] > max)
                {
                    ++outN;
                    outX += J[i];
                }
            }

            max = (2. * (X - outX)) / (N-outN);

        cout << "Case #" << t + 1 << ":";

        for (int i = 0; i < N; ++i)
        {
            double res = J[i] > max ? 0. : (((2. * X - outX) / (N - outN) - J[i]) / X) * 100;
            cout << " " << std::setprecision(10) << res;
        }

        cout << std::endl;
    }

    return 0;
}