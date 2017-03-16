#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <sstream>
#include <cmath>
#include <map>
#include <stack>
#include <unordered_map>
#include <ctime>
#include <cstring>
#include <cassert>

typedef signed char int8;
typedef unsigned char uint8;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

#define mp(a, b) std::make_pair(a, b)
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int CASE = 1; CASE <= T; ++CASE)
    {
        vector<string> in;
        in.clear();

        for (int i = 0; i < 4; ++i)
        {
            string s;
            cin >> s;
            in.push_back(s);
        }
        scanf("\n");

        bool noncomp = false;
        char win = '.';

        for (int i = 0; i < 4; ++i)
        {
            int X = 0, O = 0;
            int X2 = 0, O2 = 0;

            for (int j = 0; j < 4; ++j)
            {
                if (in[i][j] == 'X')
                    ++X;
                else if (in[i][j] == 'O')
                    ++O;
                else if (in[i][j] == 'T')
                    ++O, ++X;
                else if (in[i][j] == '.')
                    noncomp = true;

                if (in[j][i] == 'X')
                    ++X2;
                else if (in[j][i] == 'O')
                    ++O2;
                else if (in[j][i] == 'T')
                    ++O2, ++X2;
                else if (in[j][i] == '.')
                    noncomp = true;
            }

            if (X == 4 || X2 == 4)
            {
                win = 'X';
                break;
            }
            else if (O == 4 || O2 == 4)
            {
                win = 'O';
                break;
            }
        }

        if (win == '.')
        {
            int X = 0, O = 0;
            int X2 = 0, O2 = 0;

            for (int i = 0; i < 4; ++i)
            {
                if (in[i][i] == 'X')
                    ++X;
                else if (in[i][i] == 'O')
                    ++O;
                else if (in[i][i] == 'T')
                    ++O, ++X;
                else if (in[i][i] == '.')
                    noncomp = true;


                if (in[i][3 - i] == 'X')
                    ++X2;
                else if (in[i][3 - i] == 'O')
                    ++O2;
                else if (in[i][3 - i] == 'T')
                    ++O2, ++X2;
                else if (in[i][3 - i] == '.')
                    noncomp = true;
            }

            if (X == 4 || X2 == 4)
                win = 'X';
            else if (O == 4 || O2 == 4)
                win = 'O';
        }

        if (win != '.')
            printf("Case #%d: %c won\n", CASE, win);
        else if (noncomp)
            printf("Case #%d: Game has not completed\n", CASE);
        else
            printf("Case #%d: Draw\n", CASE);
    }

    return 0;
}