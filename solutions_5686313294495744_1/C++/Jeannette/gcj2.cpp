#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <math.h>
using namespace std;

int d1, d2;
vector < vector<int> > g;
vector<int> mt;
vector<char> used;
 
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
		
int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin>>t;
	for (int l = 0; l < t; ++l)
	{
		map<string, int> f;
		map<string, int> s;
		map<string, vector<string>> fs;
		map<string, vector<string>> sf;
		vector<string> bf, bs;
		string s1, s2;
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>s1>>s2;
			if (f.find(s1) == f.end())
				f[s1] = f.size();
			if (s.find(s2) == s.end())
				s[s2] = s.size();
			if (fs.find(s1) == fs.end())
			{
				fs[s1] = vector<string>();
			}
			fs[s1].push_back(s2);
			if (sf.find(s2) == sf.end())
			{
				sf[s2] = vector<string>();
			}
			sf[s2].push_back(s1);
		}
		d1 = f.size();
		d2 = s.size();
		g.assign(f.size(), vector<int>());
		mt.assign(d2, -1);
		for (map<string,int>::iterator it= f.begin(); it != f.end(); ++it)
		{
			for (int i = 0; i < fs[it->first].size(); ++i)
			{
				g[it->second].push_back(s[fs[it->first][i]]);
			}
		}
		for (int v=0; v<d1; ++v) {
			used.assign (d1, false);
			try_kuhn (v);
		}
		int z = 0;
		for (int i=0; i<d2; ++i)
			if (mt[i] != -1)
				++z;
		int res = n + z - d1 - d2;

		cout<<"Case #"<<l+1<<": "<<res<<endl;
	}
	return 0;
}