//
//  ProblemA.cpp
//  GoogleCodeJam
//
//  Created by Luan Nguyen on 4/15/16.
//  Copyright © 2016 Luan Nguyen. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

vector<string> dp;
vector<bool> has;

string calc(int x, const string& S)
{
    if (x < 0)
        return "";
    
    if (x == 0)
        return S.substr(0, 1);
    
    if (has[x])
        return dp[x];
    
    char c = S[0];
    for (int i = 0; i <= x; ++i)
        if (S[i] > c)
            c = S[i];
    
    string best = "";
    for (int i = 0; i <= x; ++i)
        if (S[i] == c)
        {
            auto temp = c + calc(i-1, S);
            if (i < x)
                temp = temp + S.substr(i+1, x-i);
            if (best == "" || best < temp)
                best = temp;
        }

    has[x] = true;
    return dp[x] = best;
}

std::string solve(const string& S)
{
    int n = (int)S.length();
    dp.clear();
    dp.resize(n);
    
    has.clear();
    has.resize(n);
    
    return calc(n-1, S);
}

int main()
{
    ofstream outFile;
    outFile.open("/users/superkinhluan/documents/Xcode projects/GoogleCodeJam/GoogleCodeJam/a-large.out", ios::out);
    
    ifstream inFile;
    inFile.open("/users/superkinhluan/documents/Xcode projects/GoogleCodeJam/GoogleCodeJam/a-large.in", ios::in);
    
    int T;
    inFile >> T;
    
    for (int i = 1; i <= T; ++i)
    {
        string N;
        inFile >> N;
        
        auto res = solve(N);
        //cout << res << endl;
        
        outFile << "Case #" << i << ": " << res << endl;
    }
    
    outFile.close();
    inFile.close();

    cout << "Successful" << endl;
    
    return 0;
}