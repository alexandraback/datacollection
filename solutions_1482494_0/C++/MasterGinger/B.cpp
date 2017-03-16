//
//  B.cpp
//  GCJ
//
//  Created by Bian Jiang on 4/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;
struct item
{
    int one;
    int two;
    bool playedOne;
    bool playedTwo;
    item() {
        playedOne = false;
        playedTwo = false;
    }
};

bool operator < (const item& a, const item& b) {
    bool ret = false;
    ret = a.two > b.two;
    
    return ret;
}
deque<item> list;
int main() {
    int t;
    scanf("%d", &t);
    for (int nt = 1; nt <= t; nt++) {
        int n;
        scanf("%d", &n);
        list.clear();
        for (int i = 0; i < n; i++) {
            int one, two;
            scanf("%d%d", &one, &two);
            item it;
            it.one = one;
            it.two = two;
            list.push_back(it);
        }
        
        sort(list.begin(), list.end());
        int total = 0, totalPlayed = 0;
        bool found = true, played = false;
        while (found) {
            played = false;
            found = false;
            int len = list.size();
            bool playedTwo = false;
            for (int i = 0; i < len; i++) {
                item& it = list[i];
                if (!it.playedTwo && it.two <= total) {
                    it.playedTwo = true;
                    totalPlayed++;
                    played = true;
                    playedTwo = true;
                    if (it.playedOne) {
                        total++;
                    }
                    else {
                        total += 2;
                    }
                }
                if (!it.playedTwo) {
                    found = true;
                }                
            }
            if (playedTwo) {
                continue;
            }
            for (int i = 0; i < len; i++) {
                item& it = list[i];
                if (!it.playedOne && it.one <= total) {
                    it.playedOne = true;
                    played = true;
                    total++;
                    totalPlayed++;
                    break;
                }
            }
            if (!found) {
                break;
            }
            if (!played) {
                break;
            }
        }
        
        if (played) {
            printf("Case #%d: %d\n", nt, totalPlayed);
        }
        else {
            printf("Case #%d: Too Bad\n", nt);
        }
    }
    return 0;
}