//
//  main.cpp
//  CodeJam
//
//  Created by Sercan Tutar on 4/13/13.
//  Copyright (c) 2013 Sercan Tutar. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <fstream>

#define LOG_ERROR std::cout << "ERROR IN LINE: " << __LINE__ << std::endl

int N, M;
int a[100][100];
int rowMax[100];
int columnMax[100];

void solve()
{
    for (int i=0; i<N; i++) {
        rowMax[i] = 0;
        for (int j=0; j<M; j++)
            if (a[i][j] > rowMax[i])
                rowMax[i] = a[i][j];
    }
    for (int j=0; j<M; j++) {
        columnMax[j] = 0;
        for (int i=0; i<N; i++)
            if (a[i][j] > columnMax[j])
                columnMax[j] = a[i][j];
    }
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (a[i][j] < rowMax[i] && a[i][j] < columnMax[j]) {
                std::cout << "NO" << std::endl;
                return;
            }
    std::cout << "YES" << std::endl;
}

int main(int argc, const char * argv[])
{
    int noOfCases;
    std::cin >> noOfCases;
    for (int i = 0; i < noOfCases; i++) {
        std::cin >> N >> M;
        for (int j=0; j<N; j++) {
            for (int k=0; k<M; k++) {
                std::cin >> a[j][k];
            }
        }
        
        std::cout << "Case #" << i+1 << ": ";
        solve();
    }
    
    return 0;
}
