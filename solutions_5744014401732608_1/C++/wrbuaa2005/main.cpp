//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>
#include <cmath>
#include <limits>

#define REP(i,N) for(int (i)=0;(i)<(N);(i)++)

using namespace std;


int main()
{
    int T;
    
    cin >> T;
    REP(caset, T)
    {
        unsigned long long B, M;
        cin >> B >> M;
        cout << "Case #" << caset + 1 << ": ";
        unsigned long long max1 = 1, cur;
        
        max1 <<=  B - 1;
        cur = 1;
        
        M = M * 2 - 1;
        if(M <= max1)cout << "POSSIBLE\n";
        else {cout << "IMPOSSIBLE\n"; continue;}

        string tmp(B, '0');
        vector<string> res;
        REP(i, B)res.push_back(tmp);

        int cnt = 0;
        while(B--)
        {
            if(M & cur)
                for(int i = 0; i < B; i++)res[i][B] = '1';
            else
                for(int i = 1; i < B; i++)res[i][B] = '1';
            cur <<= 1;
            cnt++;
        }
        for(auto & a : res)
            cout << a << endl;
    }
}