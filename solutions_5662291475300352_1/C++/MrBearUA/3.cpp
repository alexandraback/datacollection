//
//  main.cpp
//  FHC_Pattern
//
//  Created by Andriy Medvid on 11.01.15.
//  Copyright (c) 2015 Andriy Medvid. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define MAX_NUM 1000000000

#define IN_NAME ("/Users/andriymedvid/Documents/GCM-out/C-small-2-attempt1.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/C-small-2-attempt1.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

bool CompareHikes(pair<long long, long long> a, pair<long long, long long> b) {
    long long res = (360 - a.first) * a.second - (360 - b.first) * b.second;
    if(res < 0)
        return false;
    if(res > 0)
        return true;
    if(a.second > b.second)
        return true;
    return false;
}

bool EnoughTime(pair<long long, long long> a, pair<long long, long long> b, int k) {
    return (k*360 - a.first) * a.second <= (360 - b.first) * b.second;
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        int n;
    
        long long  d, h, m;
        
        cin >> n;
        
        vector<pair<long long, long long>> hikers;
        
        for(int i = 0; i < n; i++) {
            cin >> d >> h >> m;
            for(int j = 0; j < h; j++)
                hikers.push_back(make_pair(d, m + j));
        }
        
        OutCase(tIter);
        // out answer
        
        sort(hikers.begin(), hikers.end(), CompareHikes);
        
        int min = n;
        
        for(int i = 0; i < n- 1; i++) {
            int res = i;
            
            for(int j = i + 1; j < n; j++) {
                for(int k = 2; k <= n+1; k++)
                    if(EnoughTime(hikers[j], hikers[i], k))
                        res++;
            }
            if(res < min)
                min = res;
        }
        
        cout << min;
        
        cout << endl;
    }
    
    return 0;
}


