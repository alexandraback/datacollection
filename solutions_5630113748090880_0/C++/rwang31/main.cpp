//
//  main.cpp
//  try
//
//  Created by Ran Wang on 4/18/15.
//  Copyright (c) 2015 Ran Wang. All rights reserved.
//

#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int main() {
    int T, N;
    string str;
    cin >> T;
    
    for(int i = 1; i <= T; i++) {
        cin >> N;
        unordered_map<int, int> map;
        for(int j = 1; j <= 2*N-1; j++)
            for(int k = 1; k <= N; k++)
            {
                int num;
                cin >> num;
                map[num]++;
            }
        
        vector<int> res;
        for(auto & a : map)
            if(a.second % 2)
                res.push_back(a.first);
        sort(res.begin(), res.end(), less<int>());
        
        int cnt = 0;
        
        cout << "Case #" << i << ": ";
        for(auto & a : res){
            if(cnt)cout << ' ';
            cnt++;
            cout << a;
        }
        cout << endl;
    }
}
