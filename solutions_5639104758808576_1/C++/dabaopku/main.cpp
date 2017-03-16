//
//  main.cpp
//  Q_A
//
//  Created by dabao on 15/4/11.
//  Copyright (c) 2015年 Peking University. All rights reserved.
//
#include <iostream>

using namespace std;

int number[2000];
int s;

void input()
{
    char buffer[2000];
    scanf("%d %s", &s, buffer);
    
    for (int i = 0; i <= s; ++i) {
        number[i] = buffer[i] - '0';
    }
}


void solve()
{
    int total = 0;
    int need = 0;
    
    for (int i = 0; i <= s; ++i) {
        if (total < i) {
            need += i - total;
            total = i;
        }
        total += number[i];
    }
    printf("%d\n", need);
}

int main(int argc, const char * argv[])
{
    freopen("/Users/dabao/Desktop/GoogleCodeJam2015/Q_A/input.txt", "r", stdin);
    freopen("/Users/dabao/Desktop/GoogleCodeJam2015/Q_A/output.txt", "w", stdout);
    
    int caseNumber;
    
    scanf("%d", &caseNumber);
    
    for (int caseId = 1; caseId <= caseNumber; ++caseId) {
        printf("Case #%d: ", caseId);
        input();
        solve();
    }
    
    return 0;
}

