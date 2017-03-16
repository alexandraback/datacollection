#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


class Edge
{
public:
	int en;
};

vector<Edge> edg;
int first[1100], next[1000001];
int n, m;

void AddEdge(int be, int en)
{
	Edge a;
	a.en = en;
	edg.push_back(a);
	next[edg.size() - 1] = first[be];
	first[be] = edg.size() - 1;
}

int was[1100];
int match[1100];

int Dfs(int ver)
{
	int i;
	was[ver] = 1;
	for (i = first[ver]; i != -1; i = next[i])
	{
		if (match[edg[i].en] == 0)
		{
			match[edg[i].en] = ver;
			return 1;
		}
		else
		{
			if (was[match[edg[i].en]] == 0)
			{
				if (Dfs(match[edg[i].en]))
				{
					match[edg[i].en] = ver;
					return 1;
				}
			}
		}
	}
	return 0;
}

int Bipartite()
{
	memset(match, 0, sizeof(match));
	memset(was, 0, sizeof(was));
	int i, res = 0;
	for (i = 1; i <= n; i++)
	{
		memset(was, 0, sizeof(was));
		if (Dfs(i))
		{
			memset(was, 0, sizeof(was));
			res++;
		}
	}
	return res;
}



map<string, int> m1, m2;

int GetID1(string s) {
	if (m1.find(s) == m1.end()) {
		m1[s] = m1.size();
	}
	return m1[s];
}

int GetID2(string s) {
	if (m2.find(s) == m2.end()) {
		m2[s] = m2.size();
	}
	return m2[s];
}

int e;


void Load()
{
	memset(first, 0xFF, sizeof(first));
	memset(next, 0xFF, sizeof(next));
	edg.clear();
	m1.clear();
	m2.clear();
	cin >> e;
	for (int i = 0; i < e; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		AddEdge(GetID1(s1), GetID2(s2));
	}
	n = m1.size();
	m = m2.size();
}

void Solve()
{
	int gd = Bipartite();
//	cerr << "bp " << gd << "\n";
	gd = m + n - gd;
//	cerr << "good e " << gd << "\n";
	gd = e - gd;
	cout << gd << "\n";
}

int main()
{
	cout.setf(ios::fixed|ios::showpoint);
	cout.precision(10);
	int nt, tt;
	cin >> nt;
	for (tt = 1; tt <= nt; tt++) {
		cout << "Case #" << tt << ": ";
		Load();
		Solve(); 
	}
	return 0;
}
