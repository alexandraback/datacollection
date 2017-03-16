//
//  main.cpp
//  GoogleJam
//
//  Created by Alexandre Decuq on 24/03/14.
//  Copyright (c) 2014 Alexandre Decuq. All rights reserved.
//

//#include "main.h"

#include <vector>
#include <set>
#include <map> //set_intersection()
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cassert>
#include <iomanip> //for setprecision()
#include <cmath> //ceil() or floor()

using namespace std; //std::to_string(int)

#define DEBUG 1

int main()
{
    int T;
    scanf("%d", &T);
    
    for(int t=1; t<=T; t++)
    {
        int A, B, K;
        scanf("%d %d %d", &A, &B, &K);

        int res=0;
        for (int i=0;i<A;++i) {
            for (int j=0;j<B;++j) {
                int tmp = i & j;
                if (tmp<K) ++res;
            }
        }
        
        printf("Case #%d: %d\n", t, res);
        
        
    }
}


