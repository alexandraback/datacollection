#include <ios>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#define FAIL -1000000

std::vector<std::vector<int> > adjlist;
std::vector<std::vector<int> > adjback;
std::bitset<1005> visit;
int t, scc;
int ftov[1005] = {};
int siz[1005] = {};
int scc_num[1005] = {};
int base[1005] = {};
int lans[1005] = {};
int maxi[1005] = {};

std::vector<std::vector<int> > adj;

void dfs(int a)
{
	visit[a] = true;
	for (std::vector<int>::iterator it = adjback[a].begin(); it != adjback[a].end(); it++)
	{
		if (!visit[*it])
		{
			dfs(*it);
		}
	}
	ftov[t] = a;
	t++;
}

int dfs2(int a, int b)
{
	int tot = 1;
	visit[a] = true;
	for (std::vector<int>::iterator it = adjlist[a].begin(); it != adjlist[a].end(); it++)
	{
		if (!visit[*it])
		{
			scc_num[*it] = b;
			tot += dfs2(*it, b);
		}
	}
	return tot;
}

int calc(int a)
{
	if (siz[scc_num[a]] == 2)
	{
		base[a] = a;
		lans[a] = 0;
	}
	else if (siz[scc_num[a]] > 2)
	{
		base[a] = a;
		lans[a] = FAIL;
	}
	else
	{
		calc(adjback[a].front());
		base[a] = base[adjback[a].front()];
		lans[a] = lans[adjback[a].front()]+1;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	int tc, v, e, a, b, ans, ans2, siz2;
	std::cin >> tc;
	for (int xxx = 0; xxx < tc; xxx++)
	{
		std::cout << "Case #" << xxx+1 << ": ";
		
		std::cin >> v;
		t = 0;
		scc = 0;
		ans = 0;
		ans2 = 0;
		siz2 = 0;
		adjlist.clear();
		adjback.clear();
		adj.clear();
		adjlist.resize(v+1);
		adjback.resize(v+1);
		adj.resize(v+1);
		for (int i = 0; i < v; i++)
		{
			std::cin >> a;
			adjlist[a-1].push_back(i);
			adjback[i].push_back(a-1);
		}
		
		for (int i = 0; i < v; i++) visit[i] = false;
		for (int i = v-1; i >= 0; i--)
		{
			if (!visit[i])
				dfs(i);
		}
		
		for (int i = 0; i < v; i++) visit[i] = false;
		
		for (int i = v-1; i >= 0; i--)
		{
			if (!visit[ftov[i]])
			{
				scc_num[ftov[i]] = scc;
				siz[scc] = dfs2(ftov[i], scc);
				scc++;
			}
		}
		
		for (int i = 0; i < scc; i++)
		{
			if (siz[i] == 2) siz2++;
			if (ans < siz[i]) ans = siz[i];
		}
		
		//the REAL problem begins.
		
		//sccs with size 2 are "stable"
		
		for (int i = 0; i < v; i++)
		{
			calc(i);
		}
		
		for (int i = 0; i < v; i++)
			maxi[i] = FAIL;
		for (int i = 0; i < v; i++)
		{
			if (maxi[base[i]] < lans[i]) maxi[base[i]] = lans[i];
		}
		
		for (int i = 0; i < v; i++)
		{
			if (maxi[i] > 0) ans2 += maxi[i];
		}
		
		if (ans > ans2+2*siz2) std::cout << ans << '\n';
		else std::cout << ans2+2*siz2 << '\n';
	}
}
