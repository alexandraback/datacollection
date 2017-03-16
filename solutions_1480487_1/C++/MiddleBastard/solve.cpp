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


vector < int > a;
int t, n, x;
double q, s;
vector < bool > st;
int s2, m, n2;
vector < double > ans;

const double EPS = 1e-7;


bool bad()
{
	for (int i = 0; i < n; i++)
		if (ans[i] < -EPS)
			return 1;
			
	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	cin >> t;
	
	cout.setf(ios::fixed);
	cout.precision(6);
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		
		a.clear();
		s = 0;
		
		for (int j = 0; j < n; j++)
		{
			cin >> x;
			a.push_back(x);
			s += x;
		}
		
		q = 2.0 / n;
		
		cout << "Case #" << i + 1 << ": ";
		
		ans.assign(n, 0);
		st.assign(n, 0);
		
		for (int j = 0; j < n; j++)
			ans[j] = (q - a[j] * 1.0 / s) * 100;
			
		n2 = 0;
		s2 = 0;
			
		while (bad())
		{			
				
			for (int j = 0; j < n; j++)
				if (ans[j] < -EPS)
				{
					s2 += a[j];
					ans[j] = 0;
					st[j] = 1;
					n2++;
				}
				
			
			q = (1 + (s - s2) * 1.0 / s) / (n - n2);
			
			for (int j = 0; j < n; j++)
				if (!st[j])
					if (s - s2 != 0)
						ans[j] = (q - a[j] * 1.0 / s) * 100;
					else
						ans[j] = 100.0 / (n - n2);
		}
		
		for (int j = 0; j < n; j++)
			cout << ans[j] << ' ';
		cout << endl;
	}

	return 0;
}
