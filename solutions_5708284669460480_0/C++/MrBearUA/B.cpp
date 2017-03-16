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

#define MAX_NUM 1000010

#define IN_NAME ("/Users/andriymedvid/Downloads/B-small-attempt0.in")
#define OUT_NAME ("/Users/andriymedvid/Documents/GCM-out/B-small-attempt0.out")



int boardlen,wordlen,s;

char keyboard[105], keyword[105];

int word[105];

bool nextWord() {
    for(int i = s-1; i >= 0; i--)
        if(word[i] != boardlen-1) {
            word[i]++;
            for(int j = i + 1; j < s; j++)
                word[j] = 0;
            return true;
        }
    return false;
}


void OutCase(int caseNum) {
    cout << "Case #" << (caseNum+1) << ": ";
}

int main(int argc, const char * argv[]) {
    
    freopen(IN_NAME, "r", stdin);
    freopen(OUT_NAME, "w", stdout);
    
    int T;
    
    cin >> T;
    
    for(int tIter = 0; tIter < T; tIter++) {
        
        cin >> boardlen >> wordlen >> s;
        
        cin >> keyboard >> keyword;
        
        int max = 0;
        int variants = 0;
        int sum = 0;
        
        for(int i = 0; i < s; i++)
            word[i] = 0;
        
        do {
            int cnt = 0;
            for(int i = 0; i <= s - wordlen; i++) {
                bool consist = true;
                for(int j = 0; j < wordlen; j++)
                    if(keyboard[word[i+j]] != keyword[j]) {
                        consist = false;
                        break;
                    }
                if(consist)
                    cnt++;
            }
            if(cnt > max)
                max = cnt;
            sum += cnt;
            variants++;
        } while(nextWord());
    
        OutCase(tIter);
        // out answer
        
        printf("%.6lf", ((double)max) - ((double)sum / variants));
        
        cout << endl;
    }
    
    return 0;
}

