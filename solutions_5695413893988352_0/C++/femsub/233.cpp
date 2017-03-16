//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <string>
using namespace std;
double esp=1e-11;
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define cle(a) while(!a.empty())a.pop()
#define mem(p) memset(p,0,sizeof(p))
#define memf(p) memset(p,0x3f,sizeof(p))
#define memn(p) memset(p,-1,sizeof(p))
#define mp(A, B) make_pair(A, B)
#define pb push_back
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
typedef long long int LL;
typedef long double LD;
const double PI = acos(-1.0);
const LL INF=0x3f3f3f3f;
const int maxn=3010;
char s1[30],s2[30];
int len;
pair<LL,LL>ans;
void dfs(LL a,LL b,int t)
{
    if(t==len)
    {
        if(ans==mp(-1ll,-1ll))ans=mp(a,b);
        else
        {
            if(abs(a-b)<abs(ans.fi-ans.se))
                ans=mp(a,b);
            else if(abs(a-b)==abs(ans.fi-ans.se))
                ans=min(ans,mp(a,b));
        }
        return;
    }
    if(a==b)
    {
        if(s1[t]==s2[t])
        {
            if(s1[t]=='?'&&s2[t]=='?')
            {
                dfs(a*10,b*10,t+1);
                dfs(a*10+1,b*10,t+1);
                dfs(a*10,b*10+1,t+1);
            }
            else
                dfs(a*10+(s1[t]-'0'),b*10+(s2[t]-'0'),t+1);
        }
        else if(s1[t]=='?'&&s2[t]!='?')
        {
            dfs(a*10+(s2[t]-'0'),b*10+(s2[t]-'0'),t+1);
            if((s2[t]-'0')<=8)
            dfs(a*10+(s2[t]-'0')+1,b*10+(s2[t]-'0'),t+1);
            if((s2[t]-'0')>=1)
            dfs(a*10+(s2[t]-'0')-1,b*10+(s2[t]-'0'),t+1);
        }
        else if(s1[t]!='?'&&s2[t]=='?')
        {
            dfs(a*10+(s1[t]-'0'),b*10+(s1[t]-'0'),t+1);
            if((s1[t]-'0')<=8)
            dfs(a*10+(s1[t]-'0'),b*10+(s1[t]-'0')+1,t+1);
            if((s1[t]-'0')>=1)
            dfs(a*10+(s1[t]-'0'),b*10+(s1[t]-'0')-1,t+1);
        }
        else
            dfs(a*10+(s1[t]-'0'),b*10+(s2[t]-'0'),t+1);
    }
    else if(a>b)
    {
        int t1,t2;
        if(s1[t]=='?')t1=0;
        else t1=s1[t]-'0';
        if(s2[t]=='?')t2=9;
        else t2=s2[t]-'0';
        dfs(a*10+t1,b*10+t2,t+1);
    }
    else
    {
        int t1,t2;
        if(s1[t]=='?')t1=9;
        else t1=s1[t]-'0';
        if(s2[t]=='?')t2=0;
        else t2=s2[t]-'0';
        dfs(a*10+t1,b*10+t2,t+1);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //map<long long int,int>ma;                 %I64d
    //vector<int>::iterator iter;
    //memset(m,0,sizeof(int));               for(iter=trtr[rt].begin();iter!=trtr[rt].end();iter++)
    //for(int x=1;x<=n;x++)
    //for(int y=1;y<=n;y++)
    //scanf("%d%d",&a,&b);
    //scanf("%d",&n);
    //printf("%d\n",ans);
    int T;
    scanf("%d",&T);
    for(int gg=1;gg<=T;gg++)
    {
        scanf("%s%s",s1,s2);
        len=strlen(s1);
        ans=mp(-1ll,-1ll);
        dfs(0,0,0);
        LL t1=ans.fi,t2=ans.se;
        for(int x=len-1;x>=0;x--)
            {s1[x]=t1%10+'0';t1/=10;}
        for(int x=len-1;x>=0;x--)
            {s2[x]=t2%10+'0';t2/=10;}
        printf("Case #%d: %s %s\n",gg,s1,s2);
    }
    return 0;
}

