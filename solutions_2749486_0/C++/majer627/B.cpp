//
//  LAwnmower
//
//
//  Created by Laszlo Majer
//
//


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

typedef unsigned long long UInt64;
typedef long long Int64;


int main()
{
    int T = 0;
    
    cin >> T;
    for (int caseNumber = 0; caseNumber < T; ++caseNumber)
    {
        Int64 targetX = 0;
        Int64 targetY = 0;
        cin >> targetX;
        cin >> targetY;
        
        bool negativeX = false;
        bool negativeY = false;
        if (targetX < 0)
        {
            targetX = -targetX;
            negativeX = true;
        }
        if (targetY < 0)
        {
            targetY = -targetY;
            negativeY = true;
        }

        string result = "";
        for (Int64 i = 0; i < targetX; ++i)
        {
            if (negativeX)
                result += "EW";
            else
                result += "WE";
        }
        for (Int64 i = 0; i < targetY; ++i)
        {
            if (negativeY)
                result += "NS";
            else
                result += "SN";
        }
        
        cout << "Case #" << caseNumber + 1 << ": " << result << endl;
    }
}
