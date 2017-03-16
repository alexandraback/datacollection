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

#define IN_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1A/C-small-attempt1.in")
#define OUT_NAME ("/Users/andriymedvid/Desktop/GCJ/Round_1A/C-small-attempt1.out")

void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int n;
bool processed[1010];

int edges[1010];
vector<int> reversed[1010];

bool visited[1010];

struct Path {
    int index;
    int len;
    bool finalized;
};

int GetReversed(int from, int prohibited) {
    int maxLen = 0;
    
    for(int i = 0; i < reversed[from].size(); i++)
        if(reversed[from][i] != prohibited) {
            int help = GetReversed(reversed[from][i], prohibited) + 1;
            if(help > maxLen)
                maxLen = help;
        }
    
    return maxLen;
}

Path GetCycle(int from) {
    visited[from] = true;
    processed[from] = true;
    if(visited[edges[from]]) {
        Path p;
        p.index = edges[from];
        p.len = 1;
        p.finalized = false;
        return p;
    }
    Path help = GetCycle(edges[from]);
    if(help.finalized)
        return help;
    
    help.len++;
    help.finalized = help.index == from;
    
    return help;
}

void iteration() {
    
    cin >> n;
    
    int help;
    
    for(int i = 0; i <= 1000; i++)
        reversed[i].clear();
    
    for(int i = 0; i < n; i++) {
        cin >> help;
        edges[i] = help-1;
        reversed[help-1].push_back(i);
    }
    
    memset(processed, 0, 1001);
    
    int maxLen = 0;
    
    for(int i = 0; i < n; i++)
        if(!processed[i]) {
            memset(visited, 0, 1001);
            Path p = GetCycle(i);
            if(p.len > maxLen)
                maxLen = p.len;
            if(p.len == 2) {
                for(int j = 0; j < reversed[p.index].size(); j++) {
                    int other = reversed[p.index][j];
                    bool contain = false;
                    for(int k = 0; k < reversed[other].size(); k++)
                        if(reversed[other][k] == p.index)
                            contain = true;
                    
                    if(contain) {
                        int h1 = GetReversed(p.index, other);
                        int h2 = GetReversed(other, p.index);
                        if(h1 + h2 + 2 > maxLen)
                            maxLen = h1 + h2 + 2;
                    }
                }
            }
        }
    
    cout << maxLen;
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


