#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     (int)c.size()
#define clr(c)    c.clear()
#define pb        push_back
#define mp        make_pair
#define cin(x)    scanf("%d",&x)
#define MOD		1000000007
#define EPS		1E-10

ifstream fin("B-small.in");
ofstream fout("B.out");

string REV(string str, int pos)
{
	reverse(str.begin() , str.begin() + pos + 1);
	for(int i = 0; i <= pos; i++)
		if(str[i] == '+')
			str[i] = '-';
		else
			str[i] = '+';
	return str;
}

int brute(string s)
{
	string reqd;
	for(int i = 0; i < sz(s); i++)
		reqd += "+";
	map<string , int> vis;
	vis[s] = 0;
	queue<string> bfs;
	bfs.push(s);
	while(!bfs.empty())
	{
		string now = bfs.front();
		bfs.pop();
		if(now == reqd) return vis[now];
		for(int i = 0; i < sz(now); i++)
		{
			// reverse[top , i]
			string f = REV(now , i);
			if(vis.find(f) == vis.end())
			{
				vis[f] = vis[now] + 1;
				bfs.push(f);
			}
		}
	}
	assert(false);
}

int main()
{
	int t;
	fin >> t;
	for(int i = 1; i <= t; i++)
	{
		fout << "Case #" << i << ": ";
		string s;
		fin >> s;
		fout << brute(s) << "\n";
	}
	return 0;
}