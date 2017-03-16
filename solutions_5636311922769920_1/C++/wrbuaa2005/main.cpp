//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<unsigned long long> simpleCalc(unsigned long long K, int C, int S)
{
    vector<unsigned long long> res;
    
    if((K - 1) / C + 1 > S)
        return res;
    
    unsigned long long m = 1, max_val = pow(K, C);
    
    if(max_val == 1)
    {
        res.push_back(1);
        return res;
    }
    
    while(res.size() < S && m <= K)
    {
        unsigned long long opt = m;
        for(int i = 1; i < C; i++){
            opt = (opt - 1) * K + m;
            if (m + i <= K)
                opt += i;
        }
        
        res.push_back(opt);
        
        m += C;
    }

    return res;
}

int main() {
    int T, K, C, S;
    
    cin >> T;
    
    for(int i = 1; i <= T; i++) {
        cin >> K >> C >> S;
        cout << "Case #" << i << ": ";
        auto tmp = simpleCalc(K, C, S);
        if(tmp.size() == 0)
            cout << "IMPOSSIBLE\n";
        else{
            int cnt = 0;
            for(auto & a : tmp)
            {
                if(cnt)cout << ' ';
                cout << a;
                cnt++;
            }
            cout << endl;
        }
    }
}
