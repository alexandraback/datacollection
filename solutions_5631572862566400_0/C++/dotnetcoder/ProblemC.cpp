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

using namespace std;

int dp[1<<10][10][10][2][2];
int n;

int solve(int mask, int first, int last, int hasFirst, int hasLast, const vector<int>& a)
{
    if (dp[mask][first][last][hasFirst][hasLast] != -2)
        return dp[mask][first][last][hasFirst][hasLast];
    
    int res = -1;
    
    if (first != last && (hasFirst || a[first] == last) && (hasLast || a[last] == first))
        res = 0;
    
    for (int i = 0; i < n; ++i)
    {
        if (((mask >> i) & 1) == 0)
        {
            if (!hasLast && a[last] != i)
                continue;
            
            int newHasLast = (a[i] == last) ? 1 : 0;
            int newHasFirst = hasFirst;
            if (first == last && hasFirst == 0 && a[first] == i)
                newHasFirst = 1;
            
            int temp = solve(mask | (1<<i), first, i, newHasFirst, newHasLast, a);
            if (temp != -1)
            {
                res = max(res, temp + 1);
            }
        }
    }
    
    return dp[mask][first][last][hasFirst][hasLast] = res;
}


int solve(int N, const vector<int>& a)
{
    n = N;
    
    for (int i = 0; i < 1<<10; ++i)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; ++k)
                for (int u = 0; u < 2; ++u)
                    for (int v = 0; v < 2; ++v)
                        dp[i][j][k][u][v] = -2;
    
    int res = 1;
    for (int i = 0; i < N; ++i)
    {
        int temp = 1+solve( 1<<i, i, i, 0, 0, a);
        res = max(res, temp);
    }
    
    return res;
}

int main()
{
    ofstream outFile;
    outFile.open("/users/superkinhluan/documents/Xcode projects/GoogleCodeJam/GoogleCodeJam/c-small-attempt0.out", ios::out);
    
    ifstream inFile;
    inFile.open("/users/superkinhluan/documents/Xcode projects/GoogleCodeJam/GoogleCodeJam/c-small-attempt0.in", ios::in);
    
    int T;
    inFile >> T;
    
    for (int i = 1; i <= T; ++i)
    {
        int N;
        inFile >> N;

        vector<int> a(N, 0);
        for (int i = 0; i < N; ++i)
        {
            inFile >> a[i];
            a[i]--;
        }
        
        auto res = solve(N, a);
        //cout << res << endl;
        outFile << "Case #" << i << ": " << res << endl;
    }
    
    outFile.close();
    inFile.close();
    
    cout << "Success" << endl;

    return 0;
}