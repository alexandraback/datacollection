//
//  main.cpp
//  GC2014R1B_A
//
//  Created by lmotorin on 5/3/14.
//  Copyright (c) 2014 Lior. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{

    int tc =0 , tc_i = 0;
    cin >> tc;
    for (tc_i = 1; tc_i <= tc ; ++tc_i)
    {
        
        long long A,B,K;
        cin >> A >> B >> K;
        
        
        long long min = (A>B) ? B : A;
        long long max = (A>B) ? A : B;
        long long res = 0;
        if (K>min)
        {
            res = min * max;
        }
        else
        {
            long long t = 0;
            long long i = 0 , j =0 ;
            for (i=K; i<min ; ++i)
            {
                for (j=K ; j < max ; ++j)
                if ((i & j) < K)
                {
                    t++;
                }
            }
        
            res = K*max + (min-K)*K +t ;
        }
        cout << "Case #" << tc_i << ": " << res <<  endl;
    }
    return 0;
}

