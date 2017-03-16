//
//  main.cpp
//  Q_B
//
//  Created by dabao on 15/4/11.
//  Copyright (c) 2015年 Peking University. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> cakes;

void input()
{
    while (!cakes.empty()) {
        cakes.pop();
    }
    
    int n, c;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &c);
        cakes.push(c);
    }
}


void solve()
{
    int cost= cakes.top();
    int turn = 0;
    
    while (true) {
        turn++;
        int top = cakes.top();
        if (top <= 3) {
            break;
        }
        cakes.pop();
        cakes.push(top / 2);
        cakes.push(top - top / 2);
        int current = cakes.top() + turn;
        if (current < cost) {
            cost = current;
        }
    }
    
    printf("%d\n", cost);
}

int main(int argc, const char * argv[])
{
    freopen("/Users/dabao/Desktop/GoogleCodeJam2015/Q_B/input.txt", "r", stdin);
    freopen("/Users/dabao/Desktop/GoogleCodeJam2015/Q_B/output.txt", "w", stdout);
    
    int caseNumber;
    
    scanf("%d", &caseNumber);
    
    for (int caseId = 1; caseId <= caseNumber; ++caseId) {
        printf("Case #%d: ", caseId);
        input();
        solve();
    }
    
    return 0;
}

