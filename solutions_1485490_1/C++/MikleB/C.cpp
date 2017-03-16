//
//  main.cpp
//  Contest
//
//  Created by User on 25.03.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <memory.h>
using namespace std;

int n, m;
unsigned long long a[111];
int A[111];
unsigned long long b[111];
int B[111];
unsigned long long res[111][111];
bool used[111][111];

unsigned long long solve(int i, int j) {
    if (used[i][j])
        return res[i][j];
    
    res[i][j] = 0;
    used[i][j] = true;
    if (i >= n || j >= m)
        return 0;
    
    if (A[i] == B[j]) {
        unsigned long long aa = 0;
        for (int ii = i; ii < n; ++ii) {
            if (A[ii] == A[i])
                aa += a[ii];
            unsigned long long bb = 0;
            for (int jj = j; jj < m; ++jj) {
                if (B[jj] == A[i])
                    bb += b[jj];
                unsigned long long add = min(aa, bb);
                res[i][j] = max(res[i][j], add + solve(ii + 1, jj + 1));
            }
        }
    }
    res[i][j] = max(res[i][j], solve(i + 1, j));
    res[i][j] = max(res[i][j], solve(i, j + 1));
                    
    return res[i][j];
}
int main (int argc, const char * argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> A[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i] >> B[i];
        }
        memset(used, false, sizeof(used));
        memset(res, 0, sizeof(res));
        printf("Case #%d: ", t + 1);
        cout << solve(0, 0) << endl;
    }
    
    
   
    return 0;
}

