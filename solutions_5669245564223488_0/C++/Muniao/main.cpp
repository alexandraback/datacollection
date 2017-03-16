//
//  main.cpp
//  a
//
//  Created by qylqy on 14-5-11.
//  Copyright (c) 2014年 linqiuyan. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
typedef  long long llong;
const llong MOD = 1000000007;
const int maxn = 105;
multiset<string> st;
multiset<string>::iterator it;
llong P[maxn];

void init()
{
    P[0] = P[1] = 1;
    for (int i=2; i<=100; i++)
    {
        P[i] = (P[i-1]*i) % MOD;
    }
}

llong solve(int n)
{
    int t, c, i, j, flg, l, r;
    llong ans = 1;
    string head, tail, mid;
    
    //check;
    for (t=0; t<='z'-'a'; t++)
    {
        c = t+'a';
        tail = ""; head = ""; mid = "";
        vector<string> all;
        
        //for (i=0; i<n; i++)
        for (it=st.begin(); it!=st.end(); it++)
        {
            //check all equal 'c';
            flg = 1;
            for (j=0; j<(*it).size(); j++)
            {
                if ((*it)[j]!=c) flg = 0;
            }
            if (flg)
            {
                all.push_back((*it));
                continue;
            }
            //c is head;
            if ((*it)[0]==c)
            {
                if (head.size()==0) //only one head;
                    head = (*it);
                else
                    return 0;
            }
            //c is tail;
            j = (int)it->size()-1;
            if ((*it)[j]==c)
            {
                if (tail.size()==0)
                    tail = (*it);
                else
                    return 0;
            }
            //c is mid;
            for (l=0; l<it->size(); l++) if ((*it)[l]!=c) break;
            for (r=(int)it->size()-1; r>=0; r--) if ((*it)[r]!=c) break;
            for (j=l+1; j<r; j++)
            {
                flg = 1;
                if ((*it)[j]==c)
                {
                    flg = 0;
                    
                    if (mid.size() == 0)
                    {
                        mid = (*it);
                    }
                    else
                        return 0;
                    
                    while (j<r && (*it)[j]==c) j++;
                    
                    j++;
                    while (j<r && (*it)[j]!=c) j++;
                    
                    if (j<r) return 0;
                    
                    break;
                    
                }
            }
        }
        //cout << (char) c << ": ";
        //cout << mid << head << " " << tail << " " << all.size() << endl;
        
        if (mid.size())
        {
            if (head.size()|| tail.size() || all.size()) return 0;
        }
        else{
            string ns;
            if (tail.size())
            {
                ns += tail;
                st.erase(tail);
            }
            
            for (i=0; i<all.size(); i++)
            {
                ns += all[i];
                st.erase(all[i]);
            }
            ans = (ans * P[all.size()]) % MOD;
            
            if (head.size())
            {
                ns += head;
                st.erase(head);
            }
            //cout << "s: " << ns << endl;
            
            if (ns.size()) st.insert(ns); 
            
        }
        /*cout << ans << " ";
        for (it=st.begin(); it!=st.end(); it++)
        {
            cout << (*it) << " ";
        }
        cout << endl;*/
    }
    return ans * P[st.size()];
}


int main()
{
    
    int T, I, n, i;
    llong ans;
    char str[maxn];
    scanf ("%d", &T); I = 1;
    init();
    while (T--)
    {
        printf ("Case #%d: ", I++);
        st.clear();
        
        scanf ("%d", &n);
        for (i=0; i<n; i++)
        {
            scanf ("%s", str);
            st.insert((string) str);
        }
        //cout << p << " " << q;
        ans = solve(n);
        
        printf ("%lld\n", ans);
    }
    return 0;
}

