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
    ofstream cout("output.txt");
    long t;
    cin>>t;
    for(long q=0; q<t; q++)
    {
        string res;
        int x, y;
        cin>>x>>y;
        
        if(x > 0)
            for(int i=0; i<x; i++)
                res += "WE";
        else
            for(int i=0; i<-x; i++)
                res += "EW";
        
        if(y > 0)
            for(int i=0; i<y; i++)
                res += "SN";
        else
            for(int i=0; i<-y; i++)
                res += "NS";
        
        cout<<"Case #"<<q+1<<": "<<res<<"\n";
    }
    
}