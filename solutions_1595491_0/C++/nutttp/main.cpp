//
//  main.cpp
//  GCJ_Q2
//
//  Created by MBP13 on 4/14/55 BE.
//  Copyright (c) 2555 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int bestNot(int sum);
int bestSur(int sum);

int bestNot(int sum)
{
    if(sum%3 == 0)  return sum/3;
    return sum/3+1;
}

int bestSur(int sum)
{
    if(sum <= 1)    return 0;
    if(sum%3 == 2) return (sum/3)+2;
    return (sum/3)+1;
}

int main ()
{
    freopen("/Users/mbp13/Documents/Google Code Jam/GCJ_Q2/GCJ_Q2/input", "r", stdin);
    freopen("/Users/mbp13/Documents/Google Code Jam/GCJ_Q2/GCJ_Q2/output_q2", "w", stdout);
    int score[105];
    int pass[105];
    int scoreNum;
    int cnt;
    int bound;
    int surprise;
    int i,j;
    int isFound;
    int caseNum;
    cin >> caseNum;
    for (i=0; i<caseNum; i++) {
        cin >> scoreNum >> surprise >> bound;
        cnt = 0;
        for(j=0;j<scoreNum;j++)
        {
            pass[j] = 0;
            cin >> score[j];
            if(bestNot(score[j])>=bound)
            {
                pass[j] = 1;
                cnt++;
                //cout << "add normal " << score[j] << endl;
            }
        }
        while(surprise > 0)
        {
            isFound = 0;
            for(j=0;j<scoreNum;j++)
            {
                if(bestSur(score[j]) >= bound && pass[j] == 0)
                {
                    pass[j] = 1;
                    cnt++;
                    //cout << "add surprise " << score[j] << endl;
                    surprise--;
                    isFound = 1;
                    break;
                }
            }
            if(isFound == 0)
                break;
        }
        cout << "Case #" << i+1 << ": " << cnt << endl;
    }
    return 0;
}

