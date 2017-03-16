// GCJ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int bbegin[30]={},eend[30]={};
int zh[30]={};
int visited[30]={};
long long ans=1;
int used[30]={};
long long mod=1000000007;
string str[110];
int tmp=0;
long long dfs(int k,int ttt)
{
	if (used[k]==0)
		used[k]=1;
	else 
	{
		tmp=1;
		return 0;
	}
	long long sum=0;
	if (bbegin[k]!=0 || zh[k]!=0) sum=1;
	for (int i=1;i<=zh[k];i++) sum=sum*i%mod;
	if (sum==0) return 1;
	if (ttt!=-1 && bbegin[k]!=0 ) 
		sum=sum*dfs(str[bbegin[k]][str[bbegin[k]].length()-1]-'a',1)%mod;
	if (ttt!=1 && eend[k]!=0 ) 
		sum=sum*dfs(str[eend[k]][0]-'a',-1)%mod;
	return sum;
}
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	for (int cs=1;cs<=t;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		int n;
		tmp=0;
		ans=1;
		memset(bbegin,0,sizeof(bbegin));
		memset(eend,0,sizeof(eend));
		memset(zh,0,sizeof(zh));
		memset(visited,0,sizeof(visited));
		memset(used,0,sizeof(used));
		ans=1;
		cin>>n;
		for (int i=1;i<=n;i++)
		{
			cin>>str[i];
			int b=0;
			while (b<str[i].length()-1 && str[i][b]==str[i][b+1]) b++;
			if (b==str[i].length()-1) 
			{
				zh[str[i][0]-'a']++;
				continue;
			}
			int e=str[i].length()-1;
			while (e>1 && str[i][e]==str[i][e-1]) e--;
			for (int j=b+1;j<e;j++)
			{
				while (str[i][j+1]==str[i][j]) j++;
				if (visited[str[i][j]-'a']==0 && bbegin[str[i][j]-'a']==0 && eend[str[i][j]-'a']==0)
					visited[str[i][j]-'a']=i;
				else tmp=-1;
			}
			if (bbegin[str[i][b]-'a']==0 && visited[str[i][b]-'a']==0)
				bbegin[str[i][b]-'a']=i;
			else tmp=-1;
			if (eend[str[i][e]-'a']==0 && visited[str[i][e]-'a']==0)
				eend[str[i][e]-'a']=i;
			else tmp=-1;
		}
		if (tmp==-1)
		{
			cout<<"0"<<endl;
			continue;
		}
		int q=0;
		for (int i=0;i<26;i++)
		{
			if (!used[i])
			{
				if (bbegin[i]!=0 || zh[i]!=0) 
				{
					q++;
					ans=ans*dfs(i,0)%mod;
				}
			}
		}
		for (int i=1;i<=q;i++) ans=ans*i%mod;
		if (tmp==-1)
			cout<<"0"<<endl;
		else
			cout<<ans<<endl;
	}
		return 0;
}
