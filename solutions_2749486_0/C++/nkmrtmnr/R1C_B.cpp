#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <string.h>
#include <math.h>
#include <sstream>

using namespace std;

int main(int argc, const char **argv)
{
    ifstream fin(argv[1]);
    ofstream fout("out.txt");
    int T;
    fin >> T;

    //vector<int> mem(1001, 0);
    
    for (int tc = 0; tc < T; tc++)
    {
        int X, Y;
        fin >> X >> Y;
        string ret;

        int min = X;
        int max = Y;
        if (X > Y)
        {
            min = Y;
            max = X;
        }

        int c = 1;
        int x = 0;
        for (; x != X; c++)
        {
            if (x < X)
            {
                if (x + c <= X)
                {
                    x += c;
                    ret += 'E';
                }
                else
                {
                    x -= c;
                    ret += 'W';
                }
            }
            else
            {
                if (x - c >= X)
                {
                    x -= c;
                    ret += 'W';
                }
                else
                {
                    x += c;
                    ret += 'E';
                }
            }
        }

        int y = 0;
        for (; y != Y; c++)
        {
            if (y < Y)
            {
                if (y + c <= Y)
                {
                    y += c;
                    ret += 'N';
                }
                else
                {
                    y -= c;
                    ret += 'S';
                }
            }
            else
            {
                if (y - c >= Y)
                {
                    y -= c;
                    ret += 'S';
                }
                else
                {
                    y += c;
                    ret += 'N';
                }
            }
        }

        fout << "Case #" << tc+1 << ": " << ret << endl;
    }

    return (0);
}
