#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <ctime>
#include <functional>

using namespace std;

#define PII pair<int,int>

int q,tc;
int n,cnt;
string str[110];
vector<PII> v[110];

void input()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
		v[i].clear();
	}
}

void solve()
{
	for(int i=0;i<n;i++)
	{
		int j=1,ch=str[i][0];
		v[i].push_back(PII(ch,1));
		while(j<str[i].size())
		{
			while(j<str[i].size() && str[i][j]==ch)
			{
				v[i][v[i].size()-1].second++;
				j++;
			}
			if(j<str[i].size())
			{
				ch=str[i][j];
				v[i].push_back(PII(ch,1));
				j++;
			}
		}
	}

	for(int i=1;i<n;i++)if(v[i].size()!=v[0].size())
	{
		cnt=-1;
		return;
	}

	cnt=0;
	for(int i=0;i<v[0].size();i++)
	{
		int mini=1000000;
		for(int j=0;j<n;j++)
		{
			int sum=0;
			for(int k=0;k<n;k++)
			{
				if(v[k][i].first!=v[j][i].first)
				{
					cnt=-1;
					return;
				}
				sum+=(int)abs((double)v[k][i].second-v[j][i].second);
			}
			mini=min(mini,sum);
		}
		cnt+=mini;
	}
}

void output()
{
	
}

int main()
{
	freopen("A-small-attempt0 (1).in","r",stdin);
	freopen("A-out.out","w",stdout);

	cin>>tc;
	for(q=1;q<=tc;q++)
	{
		input();
		solve();
		if(cnt==-1)
		cout<<"Case #"<<q<<": Fegla Won\n";
		else 
		cout<<"Case #"<<q<<": "<<cnt<<endl;	
	}

	return 0;
}
