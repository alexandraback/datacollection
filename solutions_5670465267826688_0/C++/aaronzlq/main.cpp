//
//  main.cpp
//  Main
//
//  Created by AIdancer on 15/4/3.
//  Copyright (c) 2015年 AIdancer. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

const int dict[8][4] = {
    {0,1,2,3},
    {1,4,3,6},
    {2,7,4,1},
    {3,2,5,4},
    {4,5,6,7},
    {5,0,7,2},
    {6,3,0,5},
    {7,6,1,0}
};
const int N = 10005;
int T, L, X, n;
char str[N];

string bfs() {
    queue< pair<int, int> > q;
    set < pair<int, int> > h;
    q.push(make_pair(0, (int)str[0]-'0'));
    while(!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        int pos = u.first, state = u.second, nstate;
        if(pos == n-1) {
            if(state == 123)
                return  "YES";
            else continue;
        }
        pair<int, int> tmp;
        if(state < 10) {
            nstate = dict[state][str[pos+1]-'0'];
            tmp =make_pair(pos+1, nstate);
            if(h.find(tmp) == h.end()) {
                h.insert(tmp);
                q.push(tmp);
            }
            tmp = make_pair(pos+1, state*10+str[pos+1]-'0');
            if(h.find(tmp) == h.end()) {
                h.insert(tmp);
                q.push(tmp);
            }
        }
        else if(state < 100) {
            nstate = dict[state % 10][str[pos+1]-'0'];
            tmp =make_pair(pos+1, state/10*10+nstate);
            if(h.find(tmp) == h.end()) {
                h.insert(tmp);
                q.push(tmp);
            }
            tmp = make_pair(pos+1, state*10+str[pos+1]-'0');
            if(h.find(tmp) == h.end()) {
                h.insert(tmp);
                q.push(tmp);
            }
        }
        else if(state < 1000) {
            nstate = dict[state%10][str[pos+1]-'0'];
            tmp = make_pair(pos+1, state/10*10+nstate);
            if(h.find(tmp) == h.end()) {
                h.insert(tmp);
                q.push(tmp);
            }
        }
    }
    return  "NO";
}

int main(int argc, const char * argv[]) {
    cin >> T;
    string tmp;
    for(int Case = 1; Case <= T; Case++) {
        cin >> L >> X;
        cin >> tmp;
        for(int i = 0; i < L; i++) {
            if(tmp[i] == 'i')  tmp[i] = '1';
            else if(tmp[i] == 'j')  tmp[i] = '2';
            else if(tmp[i] == 'k')  tmp[i] = '3';
        }
        n = 0;
        while(X) {
            for(int j = 0; j < L; j++)  str[n++] = tmp[j];
            X--;
        }
        string ans = bfs();
        printf("Case #%d: %s\n", Case, ans.c_str());
    }
    return 0;
}















