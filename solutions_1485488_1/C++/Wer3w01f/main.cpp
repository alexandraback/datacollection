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

#define PROBLEM_NAME "B"
#define LARGE_INPUT 1

#if LARGE_INPUT
    #define INPUT_FILE PROBLEM_NAME "-large.in"
    #define OUTPUT_FILE PROBLEM_NAME "-large.out"
#else
    #define INPUT_FILE PROBLEM_NAME "-small-attempt0.in"
    #define OUTPUT_FILE PROBLEM_NAME "-small.out"
#endif

int F[100][100];
int C[100][100];
double tt[100][100];
int H, N, M;
stack<pair<int, int> > stk;

double get_water_time(double h)
{
    if (H <= h)
        return 0;

    return (H - h) / 10.;
}

double get_water_height(double time)
{
    return H - time * 10.;
}

void update_time(int i1, int j1, int i2, int j2)
{
    if (i2 < 0 || j2 < 0 || i2 >= N || j2 >= M)
        return;

    if (tt[i1][j1] == -1)
        return;

    if (C[i2][j2] - F[i2][j2] < 50 ||
        C[i2][j2] - F[i1][j1] < 50 ||
        C[i1][j1] - F[i2][j2] < 50)
        return;

    double StartTime = std::max(get_water_time(C[i2][j2] - 50), tt[i1][j1]);

    if (StartTime != 0)
    {
        if (get_water_height(StartTime) >= F[i1][j1] + 20)
            StartTime += 1;
        else
            StartTime += 10;
    }

    if (StartTime < tt[i2][j2] || tt[i2][j2] == -1)
    {
        stk.push(make_pair(i2, j2));
        tt[i2][j2] = StartTime;
    }
}

int main()
{
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);

    int T;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        
        cin >> H >> N >> M;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                cin >> C[i][j];
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> F[i][j];
                tt[i][j] = -1;
            }
        }

        stk = stack<pair<int, int> >();
        tt[0][0] = 0;
        stk.push(make_pair(0, 0));

        do
        {
            pair<int, int> top = stk.top();
            stk.pop();
            update_time(top.first, top.second, top.first + 1, top.second);
            update_time(top.first, top.second, top.first - 1, top.second);
            update_time(top.first, top.second, top.first, top.second + 1);
            update_time(top.first, top.second, top.first, top.second - 1);
        }
        while (!stk.empty());
       
        cout << "Case #" << t + 1 << ": " << setprecision(10) << tt[N-1][M-1] << endl;
    }

    return 0;
}