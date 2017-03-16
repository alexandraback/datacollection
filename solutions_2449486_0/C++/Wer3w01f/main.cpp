///////////////////////////////////////////////////////////////////////
/////    The code is written for Google Code Jam 2013 contest.    /////
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

#define PROBLEM_NAME "B"
#define LARGE_INPUT 0

#if LARGE_INPUT
    #define INPUT_FILE PROBLEM_NAME "-large.in"
    #define OUTPUT_FILE PROBLEM_NAME "-large.out"
#else
    #define INPUT_FILE PROBLEM_NAME "-small-attempt0.in"
    #define OUTPUT_FILE PROBLEM_NAME "-small0.out"
#endif

int main()
{
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);

    int T;
    cin >> T;

    for (int i = 0; i != T; ++i)
    {
        char map[100][100];
        char maxs[2][100] = {};

        int N, M;
        cin >> N >> M;

        for (int j = 0; j != N; ++j)
        {
            for (int k = 0; k != M; ++k)
            {
                cin >> map[j][k];
                maxs[0][j] = max(maxs[0][j], map[j][k]);
                maxs[1][k] = max(maxs[1][k], map[j][k]);
            }
        }

        bool yes = true;

        for (int j = 0; j != N; ++j)
            for (int k = 0; k != M; ++k)
                if (map[j][k] < maxs[0][j] &&
                    map[j][k] < maxs[1][k])
                {
                    yes = false;
                    break;
                }

        cout << "Case #" << i + 1 << ": " << (yes ? "YES" : "NO") << endl;
    }

    return 0;
}