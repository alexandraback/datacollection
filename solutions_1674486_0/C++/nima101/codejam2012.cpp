#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long ll;

//*
ifstream fin("A-small-attempt0.in");
#define cin fin
ofstream fout("A-small-attempt0.out");
#define cout fout
//*/

const int maxn = 1005;
vector<int> adj[maxn];
bool vis[maxn];

bool dfs(int v)
{
	if(vis[v])
		return true;
	vis[v] = true;
	for(int i=0; i<adj[v].size(); i++)
		if(dfs(adj[v][i]))
			return true;
	return false;
}

int main()
{
//	FILE * f = fopen("A-small-practice.out", "w");
	int tc;
	cin>>tc;

	for(int t=1; t<=tc; t++)
	{
		int n;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			int mi;
			cin >> mi;
			adj[i].clear();
			for(int j=0; j<mi; j++)
			{
				int temp;
				cin>>temp; temp--;
				adj[i].push_back(temp);
			}
		}
		bool found = false;
		for(int i=0; i<n; i++)
		{
			memset(vis, 0, sizeof vis);
			found |= dfs(i);
		}
		cout<<"Case #"<<t<<": "<<(found ? "Yes":"No")<<endl;
	}
	return 0;
}
