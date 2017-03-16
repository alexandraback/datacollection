//
//
//  noob
//
//  Created by Lingsong Zeng on 2/29/16.
//  Copyright © 2016 Lingsong Zeng. All rights reserved.
//



#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
set<string>st1,st2;
void dfs(string s,int pos,int num,string t)
{
    if(pos==s.size())
    {
        if(num==1)
            st1.insert(t);
        else
            st2.insert(t);
        return;
    }
    if(s[pos]=='?')
    {
        for(char i='0';i<='9';i++)
            dfs(s,pos+1,num,t+i);
    }
    else
        dfs(s,pos+1,num,t+s[pos]);
}
int main()
{
    int t;
    int cas=0;
    cin>>t;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        string s,t;
        cin>>s>>t;
        st1.clear();
        st2.clear();
        dfs(s,0,1,"");
        dfs(t,0,2,"");
        int ans=1005;
        int s1=1005,t1=1005;
        for(auto it1=st1.begin();it1!=st1.end();it1++)
            for(auto it2=st2.begin();it2!=st2.end();it2++)
            {
                string s=*it1;
                string t=*it2;
                int ss=0,tt=0;
                for(int i=0;i<s.size();i++)
                    ss=ss*10+s[i]-'0';
                for(int i=0;i<t.size();i++)
                    tt=tt*10+t[i]-'0';
                if(abs(ss-tt)<ans)
                {
                    ans=abs(ss-tt);
                    s1=ss;
                    t1=tt;
                }
                else if(abs(ss-tt)==ans)
                {
                    if(ss<s1)
                    {
                        s1=ss;
                        t1=tt;
                    }
                    else if(ss==s1&&tt<t1)
                    {
                        t1=tt;
                    }
                }
            }
        string out1=to_string(s1);
        string out2=to_string(t1);
        for(int i=0;i<s.size()-out1.size();i++)
            cout<<"0";
        cout<<out1<<" ";
        for(int i=0;i<t.size()-out2.size();i++)
            cout<<"0";
        cout<<out2;
        cout<<endl;
    }
}
