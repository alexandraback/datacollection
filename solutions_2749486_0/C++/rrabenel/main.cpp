//
//  main.cpp
//  Round1C_B
//
//  Created by RRA on 5/12/13.
//  Copyright (c) 2013 com.mycompany. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;


int main()
{
	freopen("b1.in","r",stdin);
	freopen("b1.out","w",stdout);
    
    cout.precision(6);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int X, Y, step = 1;
//        bool stepEven = false;
        cin >> X >> Y;
//        bool xEven = ((X % 2) == 0);
//        bool yEven = ((Y % 2) == 0);
        
        char xForward = X > 0 ? 'E' : 'W';
        char xBackward = X <= 0 ? 'E' : 'W';
        char yForward = Y > 0 ? 'N' : 'S';
        char yBackward = Y <= 0 ? 'N' : 'S';
        
        X = X > 0 ? X : X * (-1);
        Y = Y > 0 ? Y : Y * (-1);
        printf("Case #%d: ", i);
        while(1)
        {
            if(X > 0)
            {
                if(step < X)
                {
                    cout << xForward;
                    X -= step;
                    step++;
                }
                else
                {
                    cout << xBackward << xForward;
                    X -= 1;
                    step += 2;
                }
            }
            
            if(Y > 0)
            {
                if(step < Y)
                {
                    cout << yForward;
                    Y -= step;
                    step++;
                }
                else
                {
                    cout << yBackward << yForward;
                    Y -= 1;
                    step += 2;
                }
            }
            if(X == 0 && Y == 0)
            {
                break;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}

