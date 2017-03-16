#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

string solve(ifstream & in)
{
    int X, Y;
    string moves;
    in >> X;
    in >> Y;
    cout << "X: " << X << " Y: " << Y << endl;

    int x = 0; int y = 0;

    int j = 1;

    while (y != Y)
    {
        if (Y > y)
        {
            if (fabs(Y - y) > fabs(Y - (y+j)))
            {
                y += j;
                j += 1;
                moves.push_back('N');
            }

            else
            {
                y += 1;
                j += 2;
                moves.push_back('S');
                moves.push_back('N');
            }
        }

        else if (Y < y)
        {
            if (fabs(Y - y) > fabs(Y - (y-j)))
            {
                y -= j;
                j += 1;
                moves.push_back('S');
            }

            else
            {
                y -= 1;
                j += 2;
                moves.push_back('N');
                moves.push_back('S');
            }
        }
    }

    while (x != X)
    {
        if (X > x)
        {
            if (fabs(X - x) > fabs(X - (x+j)))
            {
                x += j;
                j += 1;
                moves.push_back('E');
            }

            else
            {
                x += 1;
                j += 2;
                moves.push_back('W');
                moves.push_back('E');
            }
        }

        else if (X < x)
        {
            if (fabs(X - x) > fabs(X - (x-j)))
            {
                x -= j;
                j += 1;
                moves.push_back('W');
            }

            else
            {
                x -= 1;
                j += 2;
                moves.push_back('E');
                moves.push_back('W');
            }
        }
    }

    return moves;
}
        

    
    

int main()
{
    ifstream in;
    in.open("b1.in");
    ofstream out;
    out.open("b1.out");

    size_t T;
    in >> T;
    cout << T << endl;
    for (size_t i = 1; i <= T; i++)
    {
        out << "Case #" << i << ": ";
        out << solve(in) << endl;
    }

    in.close();
    out.close();
    return 0;
}
