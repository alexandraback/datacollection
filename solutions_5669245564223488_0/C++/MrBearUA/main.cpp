//
//  main.cpp
//  gcj-1c-b
//
//  Created by Andriy Medvid' on 11.05.14.
//  Copyright (c) 2014 Andriy Medvid'. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    
    int n;
    char train[100][110];
    int cycles[26];
    int child[26];
    bool starts[26];
    bool finishes[26];
    
    for(int t = 0; t < T; t++) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", train[i]);
        
        for(int i = 0; i < 26; i++) {
            cycles[i] = 0;
            child[i] = -1;
            starts[i] = false;
            finishes[i] = false;
        }
        
        bool impossible = false;
        
        for(int i = 0; i < n; i++) {
            bool hasDiffer = false;
            for(int j = 0; train[i][j] && train[i][j+1]; j++) {
                int from = train[i][j] - 'a';
                int to = train[i][j+1] - 'a';
                
                if(from != to) {
                    hasDiffer = true;
                    if(starts[from] || finishes[to]) {
                        impossible = true;
                        break;
                    } else {
                        child[from] = to;
                        starts[from] = true;
                        finishes[to] = true;
                    }
                }
            }
            
            if(impossible) {
                break;
            }
            
            if(!hasDiffer)
                cycles[train[i][0] - 'a']++;
        }
        
        int parts = 0;
        for(int i = 0; i < 26; i++) {
            if(starts[i] && !finishes[i]) {
                parts++;
            }
        }
        for(int i = 0; i < 26; i++)
            if(!starts[i] && !finishes[i] && cycles[i] > 0)
                parts++;
        
        bool visited[26];
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++)
                visited[j] = false;
            
            int a = i;
            
            while(a != -1) {
                if(visited[a]) {
                    impossible = true;
                    break;
                }
                visited[a] = true;
                a = child[a];
            }
            if(impossible) break;
        }
    
        if(impossible) {
            printf("Case #%d: 0\n", t+1);
        } else {
            long long result = 1;
            long long modulo = 1000000007;
            for(int i = 0; i < 26; i++)
                for(int  j = 2; j <= cycles[i]; j++)
                    result = (result * j) % modulo;
            for(int j = 2; j <= parts; j++)
                result = (result * j) % modulo;
            
            printf("Case #%d: %lld\n", t+1, result);
        }
        
    }
    return 0;
}

