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

#define PROBLEM_NAME "A"
#define LARGE_INPUT 1

#if LARGE_INPUT
    #define INPUT_FILE PROBLEM_NAME "-large.in"
    #define OUTPUT_FILE PROBLEM_NAME "-large.out"
#else
    #define INPUT_FILE PROBLEM_NAME "-small-attempt0.in"
    #define OUTPUT_FILE PROBLEM_NAME "-small0.out"
#endif

#define SIZE 4

char CheckPlayer(char b[SIZE][SIZE], char p)
{
    char R = 'D';
    bool wind1 = true;
    bool wind2 = true;

    for (int i = 0; i != SIZE; ++i)
    {
        bool winh = true;
        bool winv = true;

        for (int j = 0; j != SIZE; ++j)
        {
            if (b[i][j] != p && 
                b[i][j] != 'T')
            {
                winh = false;
            }

            if (b[j][i] != p && 
                b[j][i] != 'T')
            {
                winv = false;
            }

            if (b[i][j] == '.')
                R = '.';
        }

        if (winh || winv)
            return p;

        if (b[i][i] != p && 
            b[i][i] != 'T')
        {
            wind1 = false;
        }

        if (b[SIZE - i - 1][i] != p && 
            b[SIZE - i - 1][i] != 'T')
        {
            wind2 = false;
        }
    }

    if (wind1 || wind2)
        return p;

    return R;
}

int main()
{
    freopen(INPUT_FILE,"r",stdin);
    freopen(OUTPUT_FILE,"w",stdout);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        char board[SIZE][SIZE];
        cin.ignore();

        for (int j = 0; j != SIZE; ++j)
        {
            char line[SIZE + 1];
            cin.getline(line, SIZE + 1);
            memcpy(board[j], line, SIZE);
        }

        char R = CheckPlayer(board, 'X');

        if (R != 'X')
            R = CheckPlayer(board, 'O');

        cout << "Case #" << i + 1 << ": ";

        switch (R)
        {
        case 'X':
        case 'O':
            cout << R << " won" << endl;
            break;

        case '.':
            cout << "Game has not completed" << endl;
            break;
            
        case 'D':
            cout << "Draw" << endl;
            break;
        }
    }

    return 0;
}