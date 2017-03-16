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

void bit(vector<int> &mass, int a) {
    while(a) {
        mass.push_back(a%2);
        a/=2;
    }
}

string dfs(vector<vector<int> > &g, vector<string> &codes, vector<bool> &used, vector<int> availible, string &current) {
    //cout << current << "\n";
    if(current.size() == codes.size() * 5)
        return current;
    
    string res = "";
    
    for(int i = (int)availible.size() - 1; i >= 0; i--) {
        int v = availible[i];
        availible.resize(i + 1);
        string best = "99999";
        int num = -1;
        for(int j = 0; j < g[v].size(); j++)
            if(!used[g[v][j]])
                if(codes[g[v][j]] <= best)
                {
                    best = codes[g[v][j]];
                    num = g[v][j];
                }
        if(num != -1) {
            availible.push_back(num);
            used[num] = true;
            current += codes[num];
            
            string temp = dfs(g, codes, used, availible, current);
            
            if(temp != "" && (res == "" || res > temp))
                res = temp;
            
            used[num] = false;
            current.resize(current.size() - 5);
        }
    }
    
    return res;
}

int main()
{
    ifstream cin("C-small-attempt0.in.txt");
    ofstream cout("C-small-attempt0.out.txt");
    int T;
    cin >> T;
    for(int q = 0; q < T; q++)
    {
        int n, m;
        cin >> n >> m;
     
        vector<string> codes(n);
        
        for(int i = 0; i < n; i++)
            cin>>codes[i];
        
        vector<vector<int> > g(n);
        
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        
        vector<bool> used(n, false);
        vector<int> availible(1, 0);
        
        for (int i = 1; i < n; i++) {
            if(codes[availible[0]] > codes[i])
                availible[0] = i;
        }
        
        string current = codes[availible[0]];
        used[availible[0]] = true;
        string res = dfs(g, codes, used, availible, current);
        
        cout<<"Case #" << q+1 << ": ";
        
        cout << res;
        
        cout<<"\n";
        
    }
}