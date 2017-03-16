#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
#include<algorithm>
#include<queue>
#include<string>
#include<stack>
using namespace std;
#define maxn 111
#define INF 99999999
struct list
{
    string str;
    int index;
    int ip;
    friend bool operator <(const list &a,const list &b){
        return a.index<b.index;
    }
}ct[101];
int cmp(list a,list b)
{
    return a.str<b.str;
}
int maps[11][11];
int n;
vector<int>sum;
int can(vector<int>vec)
{
    stack<int>st;
    while(!st.empty())st.pop();
    int leap=0,i;
   // cout<<"pan=----------"<<endl;
    for(i=0;i<n;i++)
    {
        int x=vec[i];
     //   cout<<x<<" ";
        if(leap==0)
        {
            st.push(x);
            leap=1;
            continue;
        }
        while(!st.empty())
        {
            int y=st.top();
            if(maps[y][x])
            {
                st.push(x);
                break;
            }
            else st.pop();
        }
        if(st.empty())return 0;
    }
    //cout<<endl;
    //cout<<"--------------over"<<endl;
    return 1;
}
void chu(vector<int>vec)
{
    if(!can(vec))return;
    if(sum.size()==0)
    {
        sum=vec;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(ct[sum[i]].ip>ct[vec[i]].ip)
        {
            sum=vec;return;
        }
        if(ct[sum[i]].ip<ct[vec[i]].ip)return;
    }
}
void dfs(int st,vector<int>vec)
{
    if(st==0)
    {
        chu(vec);
        return;
    }
   // cout<<st<<"-"<<endl;
    vector<int>vec2;
    vec2=vec;
    for(int i=0;i<n;i++)
    {
        vec2=vec;
        if(st&(1<<i))
        {
            vec2.push_back(i+1);
            dfs(st-(1<<i),vec2);
        }
    }
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,t;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        sum.clear();
        int m,i,a,b,ans;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
           cin>>ct[i].str;
            ct[i].index=i;
        }
        sort(ct+1,ct+n+1,cmp);
        for(i=1;i<=n;i++)ct[i].ip=i;
        sort(ct+1,ct+n+1);
        memset(maps,0,sizeof(maps));
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            maps[a][b]=1;
            maps[b][a]=1;
        }
        int st=1<<n;
        st=st-1;
        vector<int>vec;
        vec.clear();
        dfs(st,vec);
        printf("Case #%d: ",t);
        for(i=0;i<n;i++)cout<<ct[sum[i]].str;
        cout<<endl;
    }
    return 0;
}
