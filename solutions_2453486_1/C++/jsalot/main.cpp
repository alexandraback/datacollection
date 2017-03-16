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

char board[4][4];
char result;
bool dotFound;

bool checkCoord(int i, int j) {
    if (board[i][j] == '.') {
        result = '.';
        return false;
    } else if (board[i][j] == 'O') {
        result = result == 'O' || result =='T' ? 'O' : (result == '.' ? '.' : '-');
    } else if (board[i][j] == 'X') {
        result = result == 'X' || result =='T' ? 'X' : (result == '.' ? '.' : '-');
    }
    return true;
}

bool analyze()
{
    if (result == '.') {
        dotFound = true;
    } else if (result == 'X' || result == 'O') {
        std::cout << result << " won" << std::endl;
        return true;
    }
    return false;
}

void solve()
{
    dotFound = false;
    for (int i=0; i<4; i++) {
        result = board[i][0];
        for (int j=1; j<4 && result != '.' && checkCoord(i, j); j++);
        if (analyze())
            return;
        
        result = board[0][i];
        for (int j=1; j<4 && result != '.' && checkCoord(j, i); j++);
        if (analyze())
            return;
    }
    
    result = board[0][0];
    for (int j=1; j<4 && result != '.' && checkCoord(j, j); j++);
    if (analyze())
        return;
    
    result = board[0][3];
    for (int j=1; j<4 && result != '.' && checkCoord(j, 3-j); j++);
    if (analyze())
        return;

    if (dotFound)
        std::cout << "Game has not completed" << std::endl;
    else
        std::cout << "Draw" << std::endl;
}

int main(int argc, const char * argv[])
{
    int noOfCases;
    std::cin >> noOfCases;
    for (int i = 0; i < noOfCases; i++) {
        std::string line;
        for (int j = 0; j < 4; j++) {
            std::cin >> line;
            for (int k = 0; k < 4; k++)
                board[j][k] = line[k];
        }
        
        std::cout << "Case #" << i+1 << ": ";
        solve();
    }
    
    return 0;
}
