#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

#include <boost/lexical_cast.hpp>
#include <boost/assign.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;


int main(int argc, char** argv)
{
    auto& in = cin;
    auto& out = cout;

    out << setprecision(7);

    string line;
    getline(in, line);
    int nLines = boost::lexical_cast<int>(line); 

    for (int caseNo=0; caseNo < nLines; ++caseNo)
    {
        int R, C, M;
        in >> R >> C >> M;

        char Field[50][50];

        for (int i=0; i < C; ++i)
            for (int j=0; j < R; ++j)
                Field[i][j] = '*';
        
        int open = R * C - M;

        bool isSuccess = true;
        if (open == 1) // Also the case R = C = 1 
        {
            Field[0][0] = 'c';
        }
        else if (C == 1)
        {
            if (open >= 2)
            {
                Field[0][0] = 'c';
                for (int i=1; i < open; ++i)
                    Field[0][i] = '.';
            }
            else
            {
                isSuccess = false;
            }
        }
        else if (R == 1)
        {
            if (open >= 2)
            {
                Field[0][0] = 'c';
                for (int i=1; i < open; ++i)
                    Field[i][0] = '.';
            }
            else
            {
                isSuccess = false;
            }
        }
        else if (C == 2)
        {
            if (open >= 4 && (open % 2 == 0))
            {
                Field[0][0] = 'c';
                Field[1][0] = '.';
                
                for (int i=1; i < open/2; ++i)
                {
                    Field[0][i] = '.';
                    Field[1][i] = '.';
                }
            }
            else
            {
                isSuccess = false;
            }
        }
        else if (R == 2)
        {
            if (open >= 4 && (open % 2 == 0))
            {
                Field[0][0] = 'c';
                Field[0][1] = '.';
                
                for (int i=1; i < open/2; ++i)
                {
                    Field[i][0] = '.';
                    Field[i][1] = '.';
                }
            }
            else
            {
                isSuccess = false;
            }
        }
        else // C >= 3 && R >= 3
        {
            if (open == 4 || open == 6 || open >= 8)
            {
                Field[0][0] = 'c';
                Field[0][1] = '.';
                Field[1][0] = '.';
                Field[1][1] = '.';

                if (open >= 6)
                {
                    Field[2][0] = '.';
                    Field[2][1] = '.';
                }

                if (open >= 8)
                {
                    Field[0][2] = '.';
                    Field[1][2] = '.';
                }

                int remainder = open - 8;
                for (int i=0; i < C - 3; ++i)
                {
                    if (remainder / 2 > 0)
                    {
                        Field[3+i][0] = '.';
                        Field[3+i][1] = '.';
                        remainder -= 2;
                    }
                }

                for (int i=0; i < R - 3; ++i)
                {
                    if (remainder / 2 > 0)
                    {
                        Field[0][3+i] = '.';
                        Field[1][3+i] = '.';
                        remainder -= 2;
                    }
                }
                for (int i=0; i < C-2;++i)
                    for (int j=0; j< R-2; ++j)
                    {
                        if (remainder > 0)
                        {
                            Field[2+i][2+j] = '.';
                            remainder--;
                        }
                    }
            }
            else
            {
                isSuccess = false;
            }
        }

        out << "Case #" << caseNo+1 << ": ";
        if (isSuccess)
        {
            out << endl;
            for (int i=0; i<R; ++i)
            {
                for (int j=0; j<C; ++j)
                {
                    out << Field[j][i];
                }
                out << endl;
            }

        }
        else
        {
            out << endl;
            out << "Impossible";
            out << endl;
        }
    }


    return 0;
}

