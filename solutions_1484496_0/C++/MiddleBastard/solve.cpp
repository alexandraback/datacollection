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


vector < vector < int > > d;
int n, t, x, s;
vector < int > a;


bool bit(int k, int x)
{
	return ((k & (1 << x)) ? 1 : 0);
}



int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		
		a.clear();
		
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			a.push_back(x);
		}
		
		d.clear();
		d.resize(2000001);
		
		for (int j = 0; j < (1 << n); j++)
		{
			s = 0;
			
			for (int l = 0; l < n; l++)
				if (bit(j, l))
					s += a[l];
					
			d[s].push_back(j);
		}
		
		cout << "Case #" << i + 1 << ": " << endl;
		
		for (int j = 0; j < 2000001; j++)
		{
			for (int x = 0; x < d[j].size(); x++)
				for (int y = x + 1; y < d[j].size(); y++)
					if (!(d[j][x] & d[j][y]))
					{
						for (int l = 0; l < n; l++)
							if (bit(d[j][x], l))
								cout << a[l] << ' ';
								
						cout << endl;
						
						for (int l = 0; l < n; l++)
							if (bit(d[j][y], l))
								cout << a[l] << ' ';
							
						cout << endl;
							
						goto lab;
					}
		}
		
		cout << "Impossible\n";
		lab:;
	}

	return 0;
}
