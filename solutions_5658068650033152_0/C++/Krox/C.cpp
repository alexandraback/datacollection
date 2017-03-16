#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

int value(int a, int b)
{
	int v = a*b;

	{
		int e = n-a;
		int inc = b-2;
		while(e >= 2 && inc > 0)
		{
			e -= 2;
			v += 2*inc;
			inc -= 2;
		}
		if(e>0 && inc > 0)
			v += inc;
	}

	{
		int e = m-b;
		int inc = a-2;
		while(e >= 2 && inc > 0)
		{
			e -= 2;
			v += 2*inc;
			inc -= 2;
		}
		if(e>0 && inc > 0)
			v += inc;
	}
	//cout << "value of " << a << " " << b << " is " << v << endl;
	return v;
}

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";

		cin >> n >> m >> k;

		if(k<=3)
		{
			cout << k << endl;
			continue;
		}
		int bestCost = k;
		bool br = false;
		for(int a = 2; a <= n && !br; ++a)
			for(int b = 2; b <= m; ++b)
				if(value(a, b) >= k)
				{
					int cost = (a+b)*2 - 4;
					bestCost = min(bestCost, cost);
				}
		cout << bestCost << endl;
	}
}
