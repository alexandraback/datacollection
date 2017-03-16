#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	for (int tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> n;
		vector<double> a, b;
		
		for (int i = 0; i < n; ++i)
		{
			double j;
			cin >> j;
			a.push_back(j);
		}
		for (int i = 0; i < n; ++i)
		{
			double j;
			cin >> j;
			b.push_back(j);
		}
		
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		
		int w = 0;
		int dw = 0;
		int ind = 0;
		for (int i = 0; i < n; ++i)
		{
			if (b[ind] > a[i])
				ind++;
			else
				w++;
		}
		ind = n - 1;
		for (int i = n - 1; i >= 0; --i)
		{
			if (a[i] > b[ind])
			{
				dw++;
				ind--;
			}
		}
		cout << "Case #" << tt << ": " << dw << " " << w << endl;
	}
	
	return 0;
}
