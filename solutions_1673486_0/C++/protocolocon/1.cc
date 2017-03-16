//  -*- mode: c++; coding: utf-8; c-file-style: "stroustrup"; -*-

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits>
#include <set>

using namespace std;

int main(int narg, char **arg)
{
    int t;
    cin >> t;
    cout.precision(10);
    for(int it=0; it<t; it++)
    {
        cout << "Case #" << it+1 << ": ";

        int typed, total, to_type;
        cin >> typed >> total;
        to_type=total-typed;
        double typed_p[typed];
        for(int i=0; i<typed; i++) cin >> typed_p[i];

        double press_ret=total+2;

        double prob_good[typed], prob=1.0;
        for(int j=0; j<typed; j++)
        {
            prob*=typed_p[j];
            prob_good[j]=prob;
        }

        for(int j=0; j<typed; j++)
        {
            double new_prob=(j*2+to_type+1)*prob_good[typed-j-1] + (j*2+to_type+1+typed+to_type+1)*(1-prob_good[typed-j-1]);
            if(new_prob<press_ret) press_ret=new_prob;
        }

        cout << press_ret << endl;
    }
    return 0;
}
