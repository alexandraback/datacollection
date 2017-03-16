#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

double E=1e-9;
using namespace std;

long long mabs(long long x)
{
	if (x>0)
		return x;
	else return -x;
}

bool was[1010], f=0;
vector <vector <int> > G;

void dfs(int v)
{
	if (was[v]!=0)
	{
		f=1;
		return; 
	}
	was[v]=1;
	for (int i=0;i<G[v].size();++i)
		dfs(G[v][i]);
}

int main()
{
	//freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int j=0;j<t;++j)
	{
		int n;
		cin >> n;
		G.resize(n);
		for (int i=0;i<n;++i)
		{
			int m;
			cin >> m;

			if(m!=0)
			for (int k=0;k<m;++k)
			{
				int x;
				cin >> x;
				G[i].push_back(x-1);
			}
		}

		string res="No";
		for (int i=0;i<n;i++)
		{
			dfs(i);
			if(f)
				res="Yes";
			memset(was, 0, sizeof(was));
			f=0;
		}
		
		G.clear();
		printf("Case #%d: ", j+1);
		cout << res <<endl;
	}
    return 0;
}