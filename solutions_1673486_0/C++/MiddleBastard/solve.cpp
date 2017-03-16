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


double e, x, y;
int n, t;
vector < double > w, d;
int a, b;

const double INF = 1e100;
double ans;


int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out","w",stdout);
	
	cin >> t;
	
	cout.setf(ios::fixed);
	cout.precision(6);
	
	for (int z = 0; z < t; z++)
	{
		w.clear();
		d.clear();
		cin >> a >> b;
		
		for (int i = 0; i < a; i++)
		{
			cin >> x;
			w.push_back(x);
		}
		
		d.resize(a);
		d[0] = w[0];
		
		for (int i = 1; i < a; i++)
			d[i] = d[i - 1] * w[i];
			
		ans = INF;
		
		/////////////
		
		x = b - a + 1;
		y = b - a + 1 + b + 1;
		
		ans = min(ans, d[a - 1] * x + (1 - d[a - 1]) * y);
		
		////////////
		
		e = d[a - 1];
		
		for (int i = 1; i < a; i++)
		{
			e += d[a - i - 1] * (1 - w[a - i]);
			
			x = i + i + b - a + 1;
			y = x + b + 1;
			
			ans = min(ans, x * e + y * (1 - e));
		}
		
		///////////
		
		x = 1 + b + 1;
		
		ans = min(ans, x);
		
		cout << "Case #" << z + 1 << ": " << ans << endl;
	}

	return 0;
}
