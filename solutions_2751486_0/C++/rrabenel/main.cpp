//
//  main.cpp
//  Round1C_A
//
//  Created by RRA on 5/12/13.
//  Copyright (c) 2013 com.mycompany. All rights reserved.
//


#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;




int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);

    std::set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
//    vowels.insert('y');
    std::string name;
    cout.precision(6);
    int N, T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        cin >> name >> N;
        int length = name.size();
        int startLetter = 0;
        int soFar = 0, rank = 0;
        while(startLetter < length && startLetter + N <= length)
        {
            bool good = true;
            for(int i = 0; i < N ; ++i)
            {
                if(vowels.find(name.at(i + startLetter)) != vowels.end())
                {
                    good = false;
                }
            }
            if(good)
            {
                if( rank == 0)
                {
                    rank++;
                }
                if(startLetter > 0)
                {
                    rank += startLetter;
                    soFar = 1;
                }
                if(startLetter == 0 && startLetter + N < length)
                {
                    rank += length - startLetter - N;
                    soFar = 1;
                }
                for(int j = 0; startLetter > 0 && startLetter + N < length && j < length - N - startLetter; ++j)
                {
                    rank += startLetter;
                    soFar = 1;
                }
                if(startLetter == 0 && startLetter + N == length)
                {
                    rank = 1;
                }
            }
            startLetter++;
        }
        
        printf("Case #%d: %d\n", k, rank);
//        printf("\n");
    }
    
    return 0;
}


