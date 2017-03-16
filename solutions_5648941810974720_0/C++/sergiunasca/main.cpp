//
//  main.cpp
//  Getting the Digits
//
//  Created by Nasca Sergiu Alin on 30/04/16.
//  Copyright © 2016 Nasca Sergiu Alin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

vector<int> a;

// "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"

int main(int argc, const char * argv[])
{
    int n, ch[40];
    char buffer[3000];
    ifstream fin("file.in");
    ofstream fout("file.out");
    fin>>n;
    for(int i = 1; i <= n; ++i)
    {
        a.clear();
        fin>>buffer;
        for(int j = 0; j <= 39; ++j)
        {
            ch[j] = 0;
            if(j <= 10)
            {
                a.push_back(0);
            }
        }
        for(int j = 0; j < strlen(buffer); ++j)
        {
            ch[ buffer[j] - 'A' ] += 1;
        }
        a[0] = ch[ 'Z' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'Z' - 'A' ];
        ch[ 'R' - 'A' ] -= ch[ 'Z' - 'A' ];
        ch[ 'O' - 'A' ] -= ch[ 'Z' - 'A' ];
        ch[ 'Z' - 'A' ] = 0;
        
        a[2] = ch[ 'W' - 'A' ];
        ch[ 'T' - 'A' ] -= ch[ 'W' - 'A' ];
        ch[ 'O' - 'A' ] -= ch[ 'W' - 'A' ];
        ch[ 'W' - 'A' ] = 0;
        
        a[6] = ch[ 'X' - 'A' ];
        ch[ 'S' - 'A' ] -= ch[ 'X' - 'A' ];
        ch[ 'I' - 'A' ] -= ch[ 'X' - 'A' ];
        ch[ 'X' - 'A' ] = 0;
        
        a[7] = ch[ 'S' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'S' - 'A' ];
        ch[ 'V' - 'A' ] -= ch[ 'S' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'S' - 'A' ];
        ch[ 'N' - 'A' ] -= ch[ 'S' - 'A' ];
        ch[ 'S' - 'A' ] = 0;
        
        a[5] = ch[ 'V' - 'A' ];
        ch[ 'F' - 'A' ] -= ch[ 'V' - 'A' ];
        ch[ 'I' - 'A' ] -= ch[ 'V' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'V' - 'A' ];
        ch[ 'V' - 'A' ] = 0;
        
        a[4] = ch[ 'F' - 'A' ];
        ch[ 'O' - 'A' ] -= ch[ 'F' - 'A' ];
        ch[ 'U' - 'A' ] -= ch[ 'F' - 'A' ];
        ch[ 'R' - 'A' ] -= ch[ 'F' - 'A' ];
        ch[ 'F' - 'A' ] = 0;
        
        a[3] = ch[ 'R' - 'A' ];
        ch[ 'T' - 'A' ] -= ch[ 'R' - 'A' ];
        ch[ 'H' - 'A' ] -= ch[ 'R' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'R' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'R' - 'A' ];
        ch[ 'R' - 'A' ] = 0;
        
        a[1] = ch[ 'O' - 'A' ];
        ch[ 'N' - 'A' ] -= ch[ 'O' - 'A' ];
        ch[ 'E' - 'A' ] -= ch[ 'O' - 'A' ];
        ch[ 'O' - 'A' ] = 0;
        
        a[9] = ch[ 'N' - 'A' ]/2;
        ch[ 'I' - 'A' ] -= ch[ 'N' - 'A' ]/2;
        ch[ 'E' - 'A' ] -= ch[ 'N' - 'A' ]/2;
        ch[ 'N' - 'A' ] = 0;
        
        a[8] = ch[ 'E' - 'A' ];
        ch[ 'I' - 'A' ] -= ch[ 'E' - 'A' ];
        ch[ 'G' - 'A' ] -= ch[ 'E' - 'A' ];
        ch[ 'H' - 'A' ] -= ch[ 'E' - 'A' ];
        ch[ 'T' - 'A' ] -= ch[ 'E' - 'A' ];
        ch[ 'E' - 'A' ] = 0;
        
        /*for(int j = 0; j <= 30; ++j)
        {
            fout<<ch[j]<<" ";
        }*/
        
        fout<<"Case #"<<i<<": ";
        for(int j = 0; j <= 9; ++j)
        {
            for(int k = 1; k <= a[j]; ++k)
            {
                fout<<j;
            }
        }
        fout<<'\n';
    }
    
    return 0;
}
