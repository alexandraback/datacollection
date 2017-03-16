//
//  ProblemB.cpp
//  GoogleCodeJam
//
//  Created by Luan Nguyen on 4/9/16.
//  Copyright © 2016 Luan Nguyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

bool compare(const vector<int>& x, const vector<int>& y)
{
    int n = (int)x.size();
    for (int i = 0; i < n; ++i)
    {
        if (x[i] < y[i])
            return true;
        if (x[i] > y[i])
            return false;
    }
    
    return false;
}


vector<int> solve(int N, vector<vector<int>>& a)
{
    unordered_map<int, int> f;
    for (auto& row : a)
    {
        for (int x : row)
        {
            f[x]++;
        }
    }
    
    vector<int> res;
    for (auto& p : f)
    {
        if (p.second % 2 == 1)
            res.push_back(p.first);
    }
    
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ofstream outFile;
    outFile.open("/users/superkinhluan/documents/Xcode projects/GoogleCodeJam/GoogleCodeJam/b-small-attempt0.out", ios::out);
    
    ifstream inFile;
    inFile.open("/users/superkinhluan/documents/Xcode projects/GoogleCodeJam/GoogleCodeJam/b-small-attempt0.in", ios::in);
    
    int T;
    inFile >> T;
    
    for (int i = 1; i <= T; ++i)
    {
        int N;
        inFile >> N;
        
        vector<vector<int>> a(2*N-1, vector<int>(N, 0));
        for (int i = 0; i < 2*N-1; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                inFile >> a[i][j];
            }

        }
        
        auto res = solve(N, a);
        //cout << res << endl;
        outFile << "Case #" << i << ":";
        for (int i : res)
            outFile << " " << i;
        outFile << endl;
    }
    
    outFile.close();
    inFile.close();
    
    cout << "Success" << endl;

    return 0;
}