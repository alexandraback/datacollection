#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>

using namespace std;

string ans;
int cc = 0;
int order[50];
int visited[50];
int parent[50];
int fback[50];
string zip[50];
vector<int> ady[50];

void solve (int pos, int v, int n)
{
	//printf("Estoy en %d\n",v+1);
	
	if (pos == n)
	{
		string sol;
		for (int i = 0; i < n; i += 1)
		{
			sol += zip[order[i]];
		}
		
		if (ans.empty() || sol < ans)
			ans = sol;
		return;
	}
	
	for (int i = 0; i < ady[v].size(); i += 1)
	{
		int dv = ady[v][i];
		
		if (!visited[dv])
		{
			//printf("Visito %d de %d\n",dv+1,v+1);
			
			visited[dv] = true;
			fback[v]++;
			order[pos] = dv;
			parent[dv] = v;
			solve(pos+1,dv,n);
			fback[v]--;
			visited[dv] = false;
		}
		else if (parent[v] == dv && fback[dv])
		{
			//printf("Me regreso a %d de %d\n",dv+1,v+1);
			fback[dv]--;
			solve(pos,dv,n);
			fback[dv]++;
		}
	}
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; t += 1)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		
		char str[12];
		for (int i = 0; i < n; i += 1)
		{
			scanf("%s",str);
			zip[i] = str;
		}
		
		for (int i = 0; i < m; i += 1)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			
			--a;
			--b;
			
			ady[a].push_back(b);
			ady[b].push_back(a);
		}
		
		ans.clear();
		for (int i = 0; i < n; i += 1)
		{
			order[0] = i;
			parent[i] = i;
			visited[i] = true;
			//printf("Iniciando en %d\n",i+1);
			solve(1,i,n);
			visited[i] = false;
		}
		
		printf("Case #%d: %s\n",t,ans.c_str());
		
		for (int i = 0; i < n; i += 1)
		{
			ady[i].clear();
		}
	}
	
	return 0;
}
