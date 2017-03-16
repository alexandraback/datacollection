//
//  main.cpp
//  codejam2012-1C
//
//  Created by Петро Бойчук on 5/6/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int a[1000][1000];
int was[1000];
bool found;
int n;
void dfs(int k, int start) {
    if(was[k] == start) {
        found = true;
    }
    was[k] = start;
    for (int i=0; i<n; i++) {
        if(a[k][i]) {
            dfs(i, start);
        }
    }
}

bool solve(int t) {
    cin >> n;
    found = false;
    for (int i=0; i<n; i++) {
        was[i] = -1;
        for (int j=0; j<n; j++) {
            a[i][j] = 0;
        }
    }
    vector<int> start;
    
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;
        if(m == 0) {
            start.push_back(i);
        }
        for (int j=0; j<m; j++) {
            int k;
            cin >> k;
            k--;
            a[k][i] = 1;
        }
    }
    for (int i=0; i<start.size(); i++) {
        dfs(start[i], start[i]);
    }
    return found;
}



int main(int argc, const char * argv[])
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        cerr << "Solving " << i+1 << endl; 
        cout << "Case #" << i+1 << ": ";
        if (solve(i+1)) {
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }
        
    }
    
    return 0;
}

