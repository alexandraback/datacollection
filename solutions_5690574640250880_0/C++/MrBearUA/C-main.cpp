//
//  main.cpp
//  GCJ-2014-c
//
//  Created by Andriy Medvid' on 12.04.14.
//  Copyright (c) 2014 Andriy Medvid'. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;

int main(int argc, const char * argv[])
{
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    int T;
    cin >> T;
    int R, C, M, freeCells;
    char field[51][51];
    for(int t = 0; t < T; t++) {
        cin >> R >> C >> M;
        printf("Case #%d:\n", t+1);
        
        freeCells = R*C - M;
        if(((freeCells > 1 && freeCells < 4) || freeCells == 5 || freeCells == 7) && (R != 1) && (C != 1)) {
            printf("Impossible\n");
            continue;
        }
        
        for(int i = 0; i < R; i ++) {
            for(int j = 0; j < C; j++)
                field[i][j] = '*';
            field[i][C] = 0;
        }
        
        field[0][0] = 'c';
        
        if(R == 1) {
            for(int i = 1; i < freeCells; i++)
                field[0][i] = '.';
        } else if(C == 1) {
            for(int i = 1; i < freeCells; i++)
                field[i][0] = '.';
        } else if((R == 2 || C == 2) && freeCells > 1) {
            if((freeCells&1) == 1) {
            printf("Impossible\n");
            continue;
            } else {
                if(C == 2) {
                    for(int i = 0; i < freeCells / 2; i++) {
                        if(i != 0) field[i][0] = '.';
                        field[i][1] = '.';
                    }
                } else {
                    for(int i = 0; i < freeCells / 2; i++) {
                        if(i != 0) field[0][i] = '.';
                        field[1][i] = '.';
                    }
                }
            }
        } else if(freeCells > 1) {
            
            int mainLen, restLen, mainCount;
            mainCount = freeCells / C;
            restLen = freeCells % C;
            mainLen = C;
            if(mainCount < 2) {
                restLen = 3*(freeCells&1);
                mainCount = 2;
                mainLen = (freeCells - restLen) / 2;
            }
            
            for(int i = 0; i < mainCount; i++)
                for(int j = 0; j < mainLen; j++)
                    if(field[i][j] != 'c')
                        field[i][j] = '.';
            for(int i = 0; i < restLen; i++)
                field[mainCount][i] = '.';
            
            if(restLen == 1) {
                field[mainCount][restLen] = '.';
                field[mainCount-1][mainLen-1] = '*';
                if(mainCount == 2) {
                    field[mainCount][restLen+1] = '.';
                    field[0][mainLen-1] = '*';
                }
            }
        }
        for(int i = 0; i < R; i++)
            printf("%s\n",field[i]);
    }
    return 0;
}