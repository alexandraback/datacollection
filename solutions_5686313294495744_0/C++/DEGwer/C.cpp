#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 2000
vector<int>pat[SIZE];
bool flag[SIZE];
int match[SIZE];
void adde(int a, int b)
{
	pat[a].push_back(b);
	pat[b].push_back(a);
}
bool dfs(int node)
{
	flag[node] = true;
	for (int i = 0; i<pat[node].size(); i++)
	{
		int f = pat[node][i], t = match[f];
		if (t == -1 || (!flag[t] && dfs(t)))
		{
			match[node] = f;
			match[f] = node;
			return true;
		}
	}
	return false;
}
int nod;
int bimatch()
{
	int ret = 0;
	fill(match, match + nod, -1);
	for (int i = 0; i<nod; i++)
	{
		if (match[i] == -1)
		{
			fill(flag, flag + nod, false);
			if (dfs(i))ret++;
		}
	}
	return ret;
}
typedef pair<string, string>pss;
vector<string>uni(vector<string>v)
{
	vector<string>ret;
	string n = "";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (n != v[i])
		{
			n = v[i];
			ret.push_back(v[i]);
		}
	}
	return ret;
}
int main()
{
	freopen("c-small-attempt0.in", "r", stdin);
	freopen("small.txt", "w", stdout);
	int data;
	scanf("%d", &data);
	for (int p = 1; p <= data; p++)
	{
		int num;
		scanf("%d", &num);
		vector<pss>zv;
		vector<string>va, vb;
		for (int i = 0; i < num; i++)
		{
			string sa, sb;
			cin >> sa >> sb;
			zv.push_back(make_pair(sa, sb));
			va.push_back(sa);
			vb.push_back(sb);
		}
		va = uni(va);
		vb = uni(vb);
		nod = va.size() + vb.size();
		for (int i = 0; i < 2000; i++)pat[i].clear();
		for (int i = 0; i < num; i++)
		{
			int la = lower_bound(va.begin(), va.end(), zv[i].first) - va.begin();
			int lb = lower_bound(vb.begin(), vb.end(), zv[i].second) - vb.begin();
			adde(la, lb + va.size());
		}
		printf("Case #%d: %d\n", p, num - (nod - bimatch()));
	}
}