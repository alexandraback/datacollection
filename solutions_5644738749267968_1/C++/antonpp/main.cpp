#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <queue>

using namespace std;

const int N = 55;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	for (int k = 0; k < t; ++k)
	{
		int n;
		double l;
		cin >> n;
		set<double> a;
		set<double> b;
		set<double> c;
		set<double> d;
		for (int i = 0; i < n; ++i)
		{
			cin >> l;
			a.insert(l);
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> l;
			b.insert(l);
		}
		c = a;
		d = b;
		int r1 = 0;
		int r2 = 0;
		while (!a.empty() && *a.begin() < *b.rbegin())
		{
			double k = *a.begin();
			a.erase(a.begin());
			b.erase(b.upper_bound(k));
		}
		r1 = a.size();

		while (c.size() > 1 && *d.begin() < *c.rbegin())
		{
			double k = *d.begin();
			d.erase(d.begin());
			c.erase(c.upper_bound(k));
			r2++;
		}

		

		if (c.size() == 1)
		{
			r2 += *d.begin() < *c.begin();
		}
		else
		{
			//r2 += c.size();
		}

		printf("Case #%i: %i %i\n", k + 1, r2, r1);
	}


	return 0;
}
