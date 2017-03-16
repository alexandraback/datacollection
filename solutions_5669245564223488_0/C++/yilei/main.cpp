#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
const long long MOD = 1000000007;
bool valid(string s)
{
	map<char, bool> dict;
	char last = 0;
	for (int i=0;i<s.length();i++)
		if (s[i]!=last)
		{
			if (dict[s[i]])
				return false;
			last = s[i];
			dict[s[i]] = true;
		}
	return true;
}
bool cancon(string a, string b)
{
	string s = a+b;
	return valid(s);
}
long long cnt(vector<string> trains)
{	
	string s = "";
	for (int j=0;j<trains.size();j++)
		s += trains[j];
	if (!valid(s))
		return 0;
	else
	{
		long long ans = 1;
		for (int j=1;j<=trains.size();j++)
		{
			ans *= j;
			ans %= MOD;
		}
		return ans;
	}
}
bool same(string s)
{
	char c = s[0];
	for (int j=0;j<s.length();j++)
	{
		if (s[j]!=c)
			return false;
	}
	return true;
}
long long process(vector<string>& trains)
{
	if (trains.size()==0)
		return 1;
	sort(trains.begin(),trains.end());
	vector<string> tmp;
	int cnt = 1;
	long long ans = 1;
	char last = trains[0][0];
	tmp.push_back(trains[0]);
	for (int i=1;i<trains.size();i++)
	{
		char c = trains[i][0];
		if (c != last)
		{
			for (int j=1;j<=cnt;j++)
			{
				ans *= j;
				ans %= MOD;
			}
			tmp.push_back(trains[i]);
			last = c;
			cnt = 0;
		}
		cnt++;
	}
	for (int j=1;j<=cnt;j++)
	{
		ans *= j;
		ans %= MOD;
	}
	trains.clear();
	for (int i=0;i<tmp.size();i++)
		trains.push_back(tmp[i]);
	return ans;
}
int main()
{
	int T,N;
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d",&N);
		printf("Case #%d: ",i);
		vector<string> trains[2];
		vector<int> ids;
		string tmp;
		long long pre = 1;
		bool flag = true;
		for (int j=0;j<N;j++)
		{
			cin>>tmp;
			if (same(tmp))
				trains[0].push_back(tmp);
			else				
				trains[1].push_back(tmp);
			if (!valid(tmp))
				flag = false;
		}
		pre = process(trains[0]);
		for (int j=0;j<trains[1].size();j++)
			trains[0].push_back(trains[1][j]);
		trains[1].clear();
		if (!flag)
			printf("0\n", flag);
		else
		{
			int cur = 0;
			bool flag = true;
			while(flag)
			{
				int j,k;
				string s;
				flag = false;
				for (j=0;j<trains[cur].size();j++)
					for (k=j+1;k<trains[cur].size();k++)
					{
						char sa, sb, ea, eb;
						sa = trains[cur][j][0];
						sb = trains[cur][k][0];
						ea = trains[cur][j][trains[cur][j].length() - 1];
						eb = trains[cur][k][trains[cur][k].length() - 1];
						if (sa == eb && cancon(trains[cur][k], trains[cur][j]))
						{
							flag = true;
							s = trains[cur][k]+trains[cur][j];
							goto out;
						}
						if (sb == ea && cancon(trains[cur][j], trains[cur][k]))
						{
							flag = true;
							s = trains[cur][j]+trains[cur][k];
							goto out;
						}
					}
out:
				if (!flag)
					break;
				trains[1-cur].push_back(s);
				for (int l=0;l<trains[cur].size();l++)
				{
					if (l == j || l == k)
						continue;
					trains[1-cur].push_back(trains[cur][l]);					
				}
				trains[cur].clear();
				cur = 1-cur;
				pre = pre % MOD;
			}
			printf("%lld\n", (cnt(trains[cur]) * pre) % MOD);
		}
		
	}
	return 0;
}