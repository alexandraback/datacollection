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

long long mod = 1000000007;

long long fact(int n) {
    if(n == 0)
        return 1;
    long long res = 1;
    for(int i = 2; i <= n; i++)
    {
        res *= i;
        res %= mod;
    }
    return res;
}

int main()
{
    ifstream cin("B-small-attempt2.in.txt");
    ofstream cout("B-small-attempt2.out.txt");
    int T;
    cin >> T;
    for(int q = 0; q < T; q++) {
        int n;
        cin >> n;
        
        vector<string> mass(n);
        for(int i = 0; i < n; i++)
            cin >> mass[i];
        
        bool flag = true;
        vector<vector<int> > hasLetter(26);
        vector<bool> oneLetter(n, true);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < mass[i].size(); j++) {
                if(j == 0)
                    hasLetter[mass[i][j] - 'a'].push_back(i);
                
                if(j > 0 && mass[i][j] != mass[i][j - 1] && hasLetter[mass[i][j] - 'a'].size() > 0 && hasLetter[mass[i][j] - 'a'].back() == i)
                    flag = false;
                
                if(j > 0 && mass[i][j] != mass[i][j - 1]) {
                    oneLetter[i] = false;
                    hasLetter[mass[i][j] - 'a'].push_back(i);
                }
            }
        vector<vector<long long> > ress(n, vector<long long> (n, 0));
        vector<long long> help;
        long long res = 1;
        for(int i = 0; i < 26 && flag; i++) {
            vector<int> mass2;
            int last = -1;
            int kol1 = 0, kol2 = 0, kol3 = 0, kol4 = 0;
            for(int j = 0; j < hasLetter[i].size(); j++) {
                if(oneLetter[hasLetter[i][j]]) {
                    kol3++;
                    mass2.push_back(hasLetter[i][j]);
                }
                else if(mass[hasLetter[i][j]][0] == 'a' + i) {
                    kol1++;
                    last = hasLetter[i][j];
                }
                else if(mass[hasLetter[i][j]].back() == 'a' + i) {
                    kol2++;
                    mass2.insert(mass2.begin(), hasLetter[i][j]);
                } else {
                    kol4++;
                }
            }
            if(last != -1)
                mass2.push_back(last);
            if(kol1 > 1 || kol2 > 1 || (kol4 && kol1 + kol2))
                flag = false;
            if(mass2.size() > 1) {
                for(int j = 1; j < mass2.size(); j++)
                    ress[mass2[j - 1]][mass2[j]] = 1;
                res *= fact(kol3);
                res %= mod;
            }
        }
        
        vector<int>todo;
        
        for(int i = 0; i < n; i++) {
            bool tmp = true;
            for (int j = 0; j < n; j++) {
                if(ress[i][j] && tmp == false)
                    flag = false;
                if(ress[i][j])
                    tmp = false;
            }
        }
        
        
        for(int i = 0; i < n; i++) {
            bool tmp = true;
            for (int j = 0; j < n; j++) {
                if(ress[j][i] && tmp == false)
                    flag = false;
                if(ress[j][i])
                    tmp = false;
            }
            if(tmp)
                todo.push_back(i);
        }
        
        int k = todo.size();
        res *= fact(k);
        res %= mod;
        if(k == 0)
            flag = false;
        
        
        
        cout << "Case #" << q + 1 << ": ";
        
        if(!flag)
            cout<<"0";
        else
            cout<<res;
        
        cout << "\n";
    }
}