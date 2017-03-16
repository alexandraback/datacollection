#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef unsigned long long int ulli;

bool isEnough(ulli y, ulli r, ulli t)
{
    return (2 * y * y + (2 * r - 1) * y <= t);
}

ulli findY( ulli r, ulli t )
{
    ulli y1 = 1;
    double y2D = (sqrt((2 * (double) r - 1) * (2 * r - 1) + 8 * t) - (2 * r - 1)) / 4;
    ulli y2 = y2D + 10;
    while(isEnough(y2, r, t))
    {
        y2 = y2 * 1.1 + 1;
    }
    
    if (!isEnough(y1, r, t) || isEnough(y2, r, t))
    {
        cout << "ERROR" << endl;
        return 0;
    }
    
    while (y2 - y1 > 1)
    {
        ulli yM = (y1 + y2) / 2;
        if (isEnough(yM, r, t))
        {
            y1 = yM;
        }
        else
        {
            y2 = yM;
        }
    }
    return y1;
}

int main()
{
    ifstream inFile( "A-small-attempt0.in" );
    int caseCount;
    inFile >> caseCount;
    
    for (int i = 1; i <= caseCount; ++i)
    {
        cout << "Case #" << i << ": ";
        ulli r, t;
        inFile >> r >> t;
        cout << findY(r, t) << endl;
    }
    
    inFile.close();
    return 0;
}
