/* ***********************************************
Author        :axp
Created Time  :2016/5/1 0:58:04
TASK		  :C.cpp
LANG          :C++
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 16;
int T;
int n;
string s;
map<string,int> mp;
int dp[1<<N];
bool vis[1<<N];
int num[N][2];
int cnt;

int f(int st)
{
	int &re=dp[st];
	if(vis[st])return re;
	vis[st]=1;
	re=0;
	for(int i=0;i<n;i++)
		if(st&(1<<i))
		{
			int flag=0;
			for(int k=0;k<n;k++)
			{
				if(k==i || (st&(1<<k))==0)continue;
				for(int j=0;j<2;j++)
					flag|=(num[k][j]==num[i][j])<<j;
			}
			if(flag==3)re=max(re,f(st-(1<<i))+1);
			else re=max(re,f(st-(1<<i)));
		}
	return re;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
	for(int kase=1;kase<=T;kase++)
	{
		mp.clear();
		cin>>n;
		string s,t;
		for(int i=0;i<n;i++)
		{
			cin>>s>>t;
			if(!mp.count(s))mp[s]=cnt++;
			if(!mp.count(t))mp[t]=cnt++;
			num[i][0]=mp[s];
			num[i][1]=mp[t];
		}
		memset(vis,0,sizeof vis);
		int ans=f((1<<N)-1);
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}
