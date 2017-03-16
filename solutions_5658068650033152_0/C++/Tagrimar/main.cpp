//
//  main.cpp
//  Codeforces
//
//  Created by Taygrim on 20.03.13.
//  Copyright (c) 2013 Taygrim. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long mod = 1000000007;

int main()
{
    ifstream cin("C-small-attempt2.in.txt");
    ofstream cout("C-small-attempt2.out.txt");
    int T;
    cin >> T;
    for(int q = 0; q < T; q++) {
        int n, m, k;
        cin >> n >> m >> k;
        
        int res = k;
        
        //vector<bool> used(n * m, false);
        
        
        for(int i = 1; i + 1 < n; i++)
            for(int j = 1; j + 1 < m; j++) {
                //used[(i + 2) * (j + 2)  - 4] = true;
                int got = (i + 2) * (j + 2)  - 4;
                if( got >= k) {
                    res = min(res, 2 * (i + j));
                    break;
                }
                else
                    res = min(res, 2 * (i + j) + k - got);
                    
            }
        
        
        if(k <= 4)
            res = k;
        
        cout << "Case #" << q + 1 << ": ";
        cout << res;
        cout << "\n";
    }
}