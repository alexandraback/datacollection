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


//#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/C.in")
//#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/C.out")

//#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/C-large.in")
//#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/C-large.out")

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/C-small-attempt0 (1).in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1C/C-small-attemp0 (1).out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int n1, n2, n3, k;

map<int, int> pairsNum;
map<int, int> tripplesNum;

int GetIndex(int a1, int a2, int a3) {
    return ((a1 + 1)*121) + ((a2 + 1)*11) + (a3 + 1);
}

void iteration() {
    
    cin >> n1 >> n2 >> n3 >> k;
    
    pairsNum.clear();
    tripplesNum.clear();
    
    for(int i1 = 0; i1 < n1; i1++)
        for(int i2 = 0; i2 < n2; i2++)
            pairsNum[GetIndex(i1, i2, -1)] = k;
    
    for(int i1 = 0; i1 < n1; i1++)
        for(int i3 = 0; i3 < n3; i3++)
            pairsNum[GetIndex(i1, -1, i3)] = k;
    
    for(int i2 = 0; i2 < n2; i2++)
        for(int i3 = 0; i3 < n3; i3++)
            pairsNum[GetIndex(-1, i2, i3)] = k;
    
    
    for(int i1 = 0; i1 < n1; i1++)
        for(int i2 = 0; i2 < n2; i2++)
            for(int i3 = 0; i3 < n3; i3++)
                tripplesNum[GetIndex(i1, i2, i3)] = 0;
    
    vector<int> result;
    
    bool wasAdded = true;
    
    while(wasAdded) {
        wasAdded = false;
        
        for(int i2 = 0; i2 < n2; i2++) {
            for(int i3 = 0; i3 < n3; i3++) {
                
                if(pairsNum[GetIndex(-1, i2, i3)] > 0) {
                    int mx = 0;
                    int maxNum = 0;
                    
                    for(int i1 = 0;  i1 < n1; i1++)
                    {
                        int val = min(pairsNum[GetIndex(i1, -1, i3)], pairsNum[GetIndex(i1, i2, -1)]);
                        if(tripplesNum[GetIndex(i1, i2, i3)] > 0)
                            val = 0;
                        if(val > mx) {
                            mx = val;
                            maxNum = i1;
                        }
                    }
                    
                    if(mx > 0) {
                        result.push_back(GetIndex(maxNum, i2, i3));
                        tripplesNum[GetIndex(maxNum, i2, i3)] = 1;
                        wasAdded = true;
                        
                        pairsNum[GetIndex(maxNum, i2, -1)]--;
                        pairsNum[GetIndex(maxNum, -1, i3)]--;
                        pairsNum[GetIndex(-1, i2, i3)]--;
                    }
                }
            }
        }
    }
    
    cout << result.size() << endl;
    
    for(int i = 0; i < result.size(); i++)
    {
        int a = (result[i] / 121);
        int b = ((result[i] / 11) % 11);
        int c = (result[i] % 11);
        
        cout << a << " " << b << " " << c << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        
        OutCase(tIter);
        
        iteration();
        
        cout << endl;
    }
    
    return 0;
}


