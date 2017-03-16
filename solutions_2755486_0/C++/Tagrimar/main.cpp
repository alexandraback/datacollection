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

struct attack
{
    long w;
    long e;
    long s;
    long t;
};

bool operator < (const attack &a, const attack &b)
{
    return a.t < b.t;
}

int main()
{
    ifstream cin("C-small-attempt1.in.txt");
    ofstream cout("output.txt");
    long t;
    cin>>t;
    for(long q=0; q<t; q++)
    {
        long res = 0;
        vector<attack> mass;
        long n;
        cin>>n;
        attack temp;
        for(long i=0; i<n; i++)
        {
            long nn, d, p, s;
            cin>>temp.t>>nn>>temp.w>>temp.e>>temp.s>>d>>p>>s;
            mass.push_back(temp);
            for(int j=1; j<nn; j++)
            {
                temp.t += d;
                temp.e += p;
                temp.w += p;
                temp.s += s;
                mass.push_back(temp);
            }
        }
        sort(mass.begin(), mass.end());
        
        long minn = mass[0].w, maxx = mass[0].e;
        for(int i=0; i<mass.size(); i++)
        {
            minn = min(mass[i].w, minn);
            maxx = max(mass[i].e, maxx);
        }
        
        vector<long> wall(2*(maxx - minn + 1), 0);
        for(int i=0; i<mass.size(); i++)
        {
            mass[i].w -= minn;
            mass[i].e -= minn;
        }
        
        vector<int> flag(mass.size(), false);
        
        for(int i=0; i<mass.size(); i++)
        {
            int j = i;
            while(mass[i].t == mass[j].t)
                j++;
            for(int l=0; l<wall.size(); l++)
            {
                long maxi = 0;
                for(int k=i; k<j; k++)
                    if(l >= 2*mass[k].w && l <= 2*mass[k].e)
                        if(wall[l] < mass[k].s)
                        {
                            maxi = max(maxi, mass[k].s);
                            flag[k] = true;
                        }
                wall[l] = max(wall[l], maxi);
            }
            i = j-1;
        }
        
        for(int i=0; i<flag.size(); i++)
            res += flag[i];
        
        cout<<"Case #"<<q+1<<": "<<res<<"\n";
    }
    
}