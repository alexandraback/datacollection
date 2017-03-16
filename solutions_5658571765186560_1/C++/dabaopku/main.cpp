//
//  main.cpp
//  Q_D
//
//  Created by dabao on 15/4/11.
//  Copyright (c) 2015年 Peking University. All rights reserved.
//

#include <iostream>

using namespace std;

int X, R, C;

void input()
{
    scanf("%d %d %d", &X, &R, &C);
}

bool check()
{
    if (R * C % X != 0) {
        return false;
    }
    
    if (X >= 7) {
        return false;
    }
    
    if (R < X && C < X) {
        return false;
    }
    
    int halfX = (X + 1) / 2;
    if (!(R >= halfX && C >= halfX)) {
        return false;
    }
    
    if (X >=4 && (R == halfX || C == halfX)) {
        return false;
    }
    
    
    if (X == 6 && (R ==3 || C == 3)) {
        return false;
    }
    
    
    return true;
}

void solve()
{
    bool result = check();
    printf("%s\n", (result ? "GABRIEL" : "RICHARD"));
}

int main(int argc, const char * argv[])
{
    freopen("/Users/dabao/Desktop/Q_D/Q_D/input.txt", "r", stdin);
    freopen("/Users/dabao/Desktop/Q_D/Q_D/output.txt", "w", stdout);
    
    int caseNumber;
    
    scanf("%d", &caseNumber);
    
    for (int caseId = 1; caseId <= caseNumber; ++caseId) {
        printf("Case #%d: ", caseId);
        input();
        solve();
    }

    return 0;
}
