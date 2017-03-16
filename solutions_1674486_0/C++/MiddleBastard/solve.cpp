#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;


vector < vector < int > > a;
vector < bool > st;
int t, n, m, x;
vector < int > d, num;
queue < int > q;


void make(int x, int y)
{
	int to;
	
	
	d.assign(n, 0);
	
	d[x] = 1;
	q.push(x);
	
	num.assign(n, 0);
	
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		
		for (int i = 0; i < a[x].size(); i++)
		{
			to = a[x][i];
			
			if (num[to] > 10)
				continue;
				
			d[to] += d[x];
			q.push(to);
			num[to]++;
		}
	}
}


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	cin >> t;
	
	for (int z = 0; z < t; z++)
	{
		cin >> n;
		
		a.clear();
		a.resize(n);
		
		for (int i = 0; i < n; i++)
		{
			cin >> m;
			
			for (int j = 0; j < m; j++)
			{
				cin >> x;
				x--;
				a[i].push_back(x);
			}
		}
		
		cout << "Case #" << z + 1 << ": ";
		
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
				if (x != y)
				{
					make(x, y);
					
					if (d[y] >= 2)
					{
						cout << "Yes\n";
						goto lab;
					}
				}
				
		cout << "No\n";
		lab:;
	}

	return 0;
}
