//ShivamRana...
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
using namespace std;
#define mod 1000000007
#define ll long long

int adj[30][30],nadj[30],in[30];
int vis[30]={false};

ll fact[50];

void pre()
{
    fact[0]=1;
    for(int i=1;i<50;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
}
ll dfs(int v)
{
    vis[v]=1;

    ll temp=fact[nadj[v]];
    for(int j=0;j<26;j++)
    {
        if(adj[v][j]&&!vis[v])
            temp=(temp*dfs(j))%mod;
    }
    return temp;
}

int main()
{
    freopen("input1.in","r",stdin);
    freopen("output1.out","w",stdout);
    int t;
    pre();
    cin>>t;
    for(int cs=1;cs<=t;cs++)
    {
        printf("Case #%d: ",cs);
        for(int i=0;i<30;i++)
        {
            for(int j=0;j<30;j++)
            {
                adj[i][j]=0;
            }
        }
        for(int i=0;i<30;i++)
        {
            nadj[i]=0;
            in[i]=0;
            vis[i]=0;
        }

        int n;
        cin>>n;
        vector<string> sv(n);
         int flag=0;
        for(int i=0;i<n;i++)
        {
           
            cin>>sv[i];
            char temp=sv[i][0];
            int flg=0;
            for(int j=1;j<sv[i].length();j++)
            {
                char tt=sv[i][j];
                if(tt==temp)
                    continue;
                flg=1;
                adj[temp-'a'][tt-'a']++;
                in[tt-'a']++;
                if(adj[temp-'a'][tt-'a']>1)
                    flag=1;
                temp=tt;
            }
            if(flg==0)
                nadj[temp-'a']++;
        }

        ////check multiple connections

        for(int i=0;i<26;i++)
        {
            int cnt=0;
            for(int j=0;j<26;j++)
            {
                if(adj[i][j]&&i!=j)
                    cnt++;
            }
            if(cnt>1)
                flag=1;
        }

        if(flag)
        {
            cout<<"0\n";
            continue;
        }
        else
        {
            ll ret=1;
            int tt=0;
            for(int i=0;i<26;i++)
            {
                if(vis[i]||in[i])
                   continue;
                int flg=0;
                if(nadj[i])
                    flg=1;
                for(int j=0;j<26;j++)
                {
                    if(adj[i][j])
                    flg=1;
                }
                if(!flg)
                    continue;
                ll temp=dfs(i);
                ret=(ret*temp)%mod;
                tt++;
            }
            ret=(ret*fact[tt])%mod;
            cout<<ret<<"\n";
        }
    }
    return 0;
}