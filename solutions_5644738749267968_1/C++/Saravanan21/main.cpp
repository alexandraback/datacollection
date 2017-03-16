//
//  main.cpp
//  Console Application
//
//  Created by Saravanan Sathyanandha on 03/12/2011.
//  Copyright (c) 2011 Elly Works. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <sstream>
using namespace std;

ifstream fin("/Users/Vanan/Downloads/D-large.in");
ofstream fout("/Users/Vanan/Downloads/output.txt");

void problemA();
void problemB();
void problemC();
void problemD();

void problemA()
{
    int row;
    int possible[4] = { -1, -1, -1, -1 };
    int temp;
    int possibleCount = 0;
    int possibleValue = -1;
    
    fin >> row;
    
    for (int i=1; i<=4; ++i) {
        for (int j=1; j<=4; ++j) {
            if (i == row)
                fin >> possible[j-1];
            else
                fin >> temp;
        }
    }
    
    fin >> row;
    for (int i=1; i<=4; ++i) {
        for (int j=1; j<=4; ++j) {
            fin >> temp;
            if (i == row) {
                for (int k=0; k<4; ++k) {
                    if (possible[k] == temp) {
                        ++possibleCount;
                        possibleValue = temp;
                        break;
                    }
                }
            }
        }
    }
    if (possibleCount == 0)
        fout << "Volunteer cheated!" << endl;
    else if (possibleCount == 1)
        fout << possibleValue << endl;
    else
        fout << "Bad magician!" << endl;
}

void problemB()
{
    double C, F, X;
    fin >> C >> F >> X;
    
    double k = floor((X-C)/C - 2.0f/F) + 1;
    if (k < 0)
        k = 0;
    if (C > X)
        k = 0;
    double t = 0;
    for (int i=0; i<k; ++i) {
        t += C/(2.0 + i*F);
    }
    t += X/(2.0 + k*F);
    fout.precision(10);
    fout << t << endl;
}

void problemC()
{
    fout << endl;
    int R,C,M;
    fin >> R >> C >> M;
    
    bool possible = false;
    int rowCount[50];
    for (int i=0; i<R; ++i)
        rowCount[i] = 0;
    
    int safes = R*C - M;
    
    if (safes == 1) {
        possible = true;
        rowCount[0] = 1;
    }
    else if (R == 1) {
        possible = true;
        rowCount[0] = safes;
    }
    else if (C == 1) {
        possible = true;
        for (int i=0; i<safes; ++i)
            rowCount[i] = 1;
    }
    else if (R == 2 && C == 2) {
        if (M == 0) {
            possible = true;
            rowCount[0] = 2;
            rowCount[1] = 2;
        }
        else {
            possible = false;
        }
    }
    else if (R == 2) {
        if (safes > 2 && ((M % 2) == 0)) {
            int halfway = safes/2;
            
            possible = true;
            rowCount[0] = halfway;
            rowCount[1] = halfway;
        }
        else {
            possible = false;
        }
    }
    else if (C == 2) {
        if (safes > 2 && ((M % 2) == 0)) {
            int halfway = safes/2;
            
            possible = true;
            for (int i=0; i<halfway; ++i)
                rowCount[i] = 2;
        }
        else {
            possible = false;
        }
    }
    else {
        // At least 3x3
        if (safes >= 3*C) {
            possible = true;
            
            int extra = safes % C;
            int rows = (safes - extra)/C;
            for (int i=0; i<rows; ++i) {
                rowCount[i] = C;
            }
            if (extra == 1) {
                --rowCount[rows-1];
                ++extra;
            }
            rowCount[rows] = extra;
        }
        else if (safes >= 3*R) {
            possible = true;
            
            int extra = safes % R;
            int columns = (safes - extra)/R;
            
            for (int i=0; i<R; ++i)
                rowCount[i] = columns;
            if (extra == 1) {
                --rowCount[R-1];
                ++extra;
            }
            for (int i=0; i<extra; ++i)
                ++rowCount[i];
            
        }
        else if (safes == 2 || safes == 3 || safes == 5 || safes == 7)
            possible = false;
        else {
            possible = true;
            
            int lowestSquare = floor(sqrt(safes));
            int diff = safes - lowestSquare*lowestSquare;
            for (int i=0; i<lowestSquare; ++i)
                rowCount[i] = lowestSquare;
            for (int i=lowestSquare; i<R; ++i)
                rowCount[i] = 0;
            if (diff == 1) {
                ++rowCount[0];
                ++rowCount[1];
                --rowCount[lowestSquare-1];
            }
            else if (diff <= lowestSquare) {
                for (int i=0; i<diff; ++i)
                    ++rowCount[i];
            }
            else if (diff == 1 + lowestSquare) {
                for (int i=0; i<lowestSquare - 1; ++i)
                    ++rowCount[i];
                rowCount[lowestSquare] += 2;
            }
            else {
                for (int i=0; i<lowestSquare; ++i)
                    ++rowCount[i];
                rowCount[lowestSquare] += (diff - lowestSquare);
            }
        }
    }
    
    if (possible) {
        for (int i=0; i<R; ++i) {
            for (int j=0; j<C; ++j) {
                if (i == 0 && j == 0)
                    fout << "c";
                else if (j < rowCount[i])
                    fout << ".";
                else
                    fout << "*";
            }
            fout << endl;
        }
    }
    else {
        fout << "Impossible" << endl;
    }
}

struct Block {
    bool isNaomi;
    double mass;
};

bool block_sorter(Block const& lhs, Block const& rhs);

bool block_sorter(Block const& lhs, Block const& rhs) {
    return lhs.mass < rhs.mass;
}

void problemD()
{
    int N;
    fin >> N;
    Block blocks[2000];
    for (int i=0; i<2*N; ++i) {
        blocks[i].isNaomi = (i < N);
        fin >> blocks[i].mass;
    }
    sort(blocks, blocks+2*N, &block_sorter);
    
    int y = 0;
    int nCount = 0;
    for (int i=2*N - 1; i>=0; --i) {
        if (blocks[i].isNaomi) {
            ++nCount;
        }
        else if (nCount > 0) {
            ++y;
            --nCount;
        }
    }
    
    int z = N;
    int kCount = 0;
    for (int i=2*N-1; i>=0; --i) {
        if (!blocks[i].isNaomi) {
            ++kCount;
        }
        else if (kCount > 0) {
            --z;
            --kCount;
        }
    }
    
    fout << y << " " << z << endl;
}

int main (int argc, const char * argv[])
{
    cout << "Start" << endl;
    int T;
    fin >> T;
    for (int t=1; t<=T; ++t)
    {
        fout << "Case #" << t << ": ";
        
        //problemA();
        //problemB();
        //problemC();
        problemD();
    }
    cout << "Done" << endl;
    return 0;
}

