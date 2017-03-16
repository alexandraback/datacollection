//
//  main.cpp
//  Codeforces
//
//  Created by Taygrim on 20.03.13.
//  Copyright (c) 2013 Taygrim. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


int main()
{
    ifstream cin("B-small-attempt0.in.txt");
    ofstream cout("B-small-attempt0.out.txt");
    int T;
    cin >> T;
    for(int q = 0; q < T; q++)
    {
        int a, b, k, res = 0;
        cin>>a>>b>>k;
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                if((i&j) < k)
                    res++;
        
        
        cout<<"Case #" << q+1 << ": ";
        
        cout<<res;
        
        cout<<"\n";
        
    }
}