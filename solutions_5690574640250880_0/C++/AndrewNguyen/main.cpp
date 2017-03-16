//
//  main.cpp
//  Minesweeper Master
//
//  Created by Nguyen Trong Quan on 4/12/14.
//  Copyright (c) 2014 Contrary Kid. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[])
{
//    freopen("test.txt", "r", stdin);
//    freopen("ouput.txt", "w", stdout);
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    
    int ncases;
    char grid[60][60];
    scanf("%d", &ncases);
    
    for (int i = 0; i < ncases; ++i)
    {
        int R, C, M;
        scanf("%d %d %d", &R, &C, &M);
        
        printf("Case #%d:\n",i+1);
        
        if (R*C - M == 1)
        {
            for (int j = 0; j < R; ++j)
            {
                for (int k = 0; k < C; ++k)
                {
                    if (j*C+k < M)
                        printf("*");
                    else
                        printf("c");
                }
                printf("\n");
            }
        }
        else if (R == 1 || C == 1)
        {
            for (int j = 0; j < R; ++j)
            {
                for (int k = 0; k < C; ++k)
                {
                    int idx = j*C+k;
                    if (idx < M)
                        printf("*");
                    else if (idx == R*C-1)
                        printf("c");
                    else
                        printf(".");
                }
                printf("\n");
            }
        }
//        else if (R*C - M <4)
//        {
//            printf("Impossible\n");
//        }
        else
        {
            bool possible = false;
            int r, c, r1, c1;
            
            for (r = 2; r <= R; ++r)
            {
                for (c = 2; c <= C; ++c)
                {
                    for (r1 = 0; r1 < r; ++r1)
                    {
                        if (r1 == 1) continue;
                        for (c1 = 0; c1 < c; ++c1)
                        {
                            if (c1 == 1) continue;
                            if (r*c+r1+c1 == R*C-M)
                                possible = true;
                            if (possible) break;
                        }
                        if (possible) break;
                    }
                    if (possible) break;
                }
                if (possible) break;
            }
            
            
            if (!possible)
            {
                printf("Impossible\n");
            }
            else
            {
                //
                for (int j = 0; j < R; ++j)
                {
                    for (int k = 0; k < C; ++k)
                        grid[j][k] = '*';
                }
                //
                for (int j = 0; j < r; ++j)
                {
                    for (int k = 0; k < c; ++k)
                    {
                        grid[j][k] = '.';
                    }
                }
                
                for (int j = 0; j < c1; ++j)
                {
                    grid[r][j] = '.';
                }
                
                for (int j = 0; j < r1; ++j)
                {
                    grid[j][c] = '.';
                }
                
                grid[0][0] = 'c';
                //
                for (int j = 0; j < R; ++j)
                {
                    for (int k = 0; k < C; ++k)
                        printf("%c", grid[j][k]);
                    printf("\n");
                }
            }
        }
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}

