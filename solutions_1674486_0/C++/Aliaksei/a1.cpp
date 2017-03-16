#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;
vector <vector<int> > g;
vector <bool> used;

bool bfs(int s)
{
	bool flag=false;
	used[s]=true;
	for (int i=0; i<g[s].size(); ++i)
		if (!used[g[s][i]])
		{
			if (bfs(g[s][i]) ) flag=true;
		}
		else
			flag=true;

	return flag;




}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin>>t;
	for (int st=0; st<t; ++st)
	{
		printf ("Case #%d:", st+1);
		int n;
		cin>>n;
		g.clear();
		g.resize(n);
		used.clear();
		
		for (int i=0; i<n; ++i)
		{
			int m, tp;
			cin>>m;
			for (int j=0; j<m;++j)
			{
				cin>>tp;
				--tp;
				g[i].push_back(tp);
			}
		}

		for (int i=0; i<n; ++i)
		{
			used.assign(n, false);
			if (!used[i])
				if (bfs(i)){
					cout<<" Yes";
					goto qwer;
				}
		}

		cout<<" No";
		
qwer: printf("\n");


	}


}