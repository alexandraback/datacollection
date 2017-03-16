//
//  round1C.c
//  codejam
//
//  Created by jie zheng on 14-5-11.
//  Copyright (c) 2014年 jie zheng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;


struct Node{
    long long ways;
    char s;
    char e;
};
/*
int mainb()
{
    //freopen("/Users/jiezheng/Dev/poj/A-small-attempt2.in", "r", stdin);
    //freopen("/Users/jiezheng/Dev/poj/a1-out.txt", "w", stdout);

    int T, N;
    string cars[105];
    cin>>T;
    for(int caseid = 1; caseid <= T; ++caseid)
    {
        cin>>N;
        long long ans = 0;
        for(int i = 0; i < N; ++i)
        {
            cin>>cars[i];
        }
        vector<Node> v;
        v.clear();
        for(int i = 0; i < N; ++i)
        {
            bool flags = false;
            bool flage = false;
            char a = cars[i][0];
            char b = cars[i][cars[i].size()-1];
            for(int j = 0; j < v.size(); ++j)
            {
                if(a == v[j].s || a == v[j].e)
                {}
                    
            }
        }
    }
    return 0;
}
*/
int main()
{
    freopen("/Users/jiezheng/Dev/poj/A-small-attempt4.in", "r", stdin);
    freopen("/Users/jiezheng/Dev/poj/a1-out.txt", "w", stdout);
    int T;
    string s;
    
    cin>>T;
    for(int caseid = 1; caseid <= T; ++caseid)
    {
        cin>>s;
        long long p = 0;
        long long q = 0;
        bool flag = true;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '/')
            {
                flag = false;
                continue;
            }
            if(flag)
            {
                p = p*10 + s[i] - '0';
            }
            else
            {
                q = q*10 + s[i] - '0';
            }
        }
        flag = true;
        if(q%p == 0)
        {
            q /= p;
            p = 1;
        }
        int ans = 0;
        while(q != 1)
        {
            if(q%2)
            {
                flag = false;
                break;
                
            }
            else
            {
                
                if(q > p)
                    ans++;
                q/=2;
                    
            }
        }

        

        cout<<"Case #"<<caseid<<": ";
        if(flag && ans <= 40)
            cout<<ans<<endl;
        else
            cout<<"impossible"<<endl;
            
    }
    return 0;
}
