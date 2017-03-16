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

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    ifstream cin("A-small-attempt0.in.txt");
    ofstream cout("output.txt");
    long t;
    cin>>t;
    for(long q=0; q<t; q++)
    {
        string s;
        cin>>s;
        long long n;
        long long prev = 0;
        cin>>n;
        long long res = 0;
        for(long i=0; i<s.size(); i++)
        {
            if(!is_vowel(s[i]))
            {
                long fin = i;
                while(fin < s.size() && !is_vowel(s[fin]))
                    fin++;
                long long kol = fin - i;
                if(kol >= n)
                {
                    res += (i - prev + 1) * (s.size() - fin + 1);
                    res += (kol - n) * (i - prev + 1);
                    res += (kol - n) * (s.size() - fin + 1);
                    kol -=2;
                    if(kol >= n)
                        res += (kol - n + 1)*(kol - n + 2)/2;
                    prev = fin - n + 1;
                }
                i = fin;
            }
        }
        cout<<"Case #"<<q+1<<": "<<res<<"\n";
    }
    
}