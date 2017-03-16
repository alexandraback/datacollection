//
//  main.cpp
//  hfjkdafb
//
//  Created by divya gupta on 16/04/16.
//  Copyright (c) 2016 divya gupta. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here
    int t,x,i;
    x=1;
    cin>>t;
    while(t--)
    {
        string s;
        string s1="";
        cin>>s;
        
        for(i=0;i<s.length();i++)
        {
            string s2=s[i]+s1;
            string s3=s1+s[i];
            if(s2>s3)
            {
                s1=s2;
            }
            else
                s1=s3;
        }
        cout<<"Case #"<<x<<": "<<s1<<endl;
        x++;
    }
    return 0;
}