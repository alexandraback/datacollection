//
//  Solution.cpp
//  GoogleJam
//
//  Created by LIU YUJIE on 3/25/15.
//  Copyright (c) 2015 刘予杰. All rights reserved.
//

#include "Solution.h"
#include <string>

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void doCase(ifstream& file,int index, string &s)
{
    string ans;
    
    int X ,R, C;
    file >> X>>R>>C;
    if (X >= 7 || (R * C % X != 0)) {
        ans = "RICHARD";
        s += "Case #" + to_string(index) + ": " + ans + "\n";
        return;
    }
    else if (X == 2)
    {
        ans = "GABRIEL";
        s += "Case #" + to_string(index) + ": " + ans + "\n";
        return;
    }
    else if(R < (X - 1) / 2 + 1 || C < (X - 1)/2 + 1 || (R < X && C < X))
    {
        ans = "RICHARD";
        s += "Case #" + to_string(index) + ": " + ans + "\n";
        return;
    }
    else if(R < X || C < X)
    {
        int min = R<C?R:C;
        if(X - min >= min)
        {
            int left = X - min;
            for (int i = 1; i <= left - 1; ++i) {
                int a = min - i;
                bool flag = false;
                while (a < R * C - X) {
                    if (a % X == 0) {
                        flag = true;
                        break;
                    }
                    a += min;
                }
                if (!flag) {
                    
                    ans = "RICHARD";
                    s += "Case #" + to_string(index) + ": " + ans + "\n";
                    return;
                }
            }
        }
    }
    ans = "GABRIEL";
    
    
    s += "Case #" + to_string(index) + ": " + ans + "\n";
}
