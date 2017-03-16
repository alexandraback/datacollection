#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <utility>

#define forn( i,n ) for ( int i=0; i<(int)(n); i++ )

using namespace std;

int t,n;
vector < vector<int> > g,p;
bool tt = false;
void dfs (int st,int v) {
	for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
	{
		forn(j,p[st].size())
			if (p[st][j] == *i)
			{ tt = true; return; }
			p[st].push_back(*i);
			dfs (st,*i);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> t;
	forn(i,t)
	{
		tt = false;
		g.clear();
		p.clear();
		cin >> n;
		p.resize(n);
		g.resize(n);
		int k,k1;
		forn(j,n)
		{
			cin >> k;
			forn(p,k)
			{
				cin >> k1;
				g[j].push_back(k1-1);
			}
		}
		forn(j,n)
		{
			if (tt) break;
			dfs(j,j);
		}
		cout << "Case #" << i+1 << ": ";
		if (!tt) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}