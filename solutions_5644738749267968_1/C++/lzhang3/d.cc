#include <iostream>

#include <cstdio>
#include <cstdlib>

#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
	int n; cin >> n;
	vector<double> a, b;
	for (int i = 0; i < n; ++i)
	{
		double x; cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n; ++i)
	{
		double x; cin >> x;
		b.push_back(x);
	}
	sort(begin(a), end(a));
	sort(begin(b), end(b));

	vector<int> mk(n);

	int nocheat = 0;

	// not cheat
	for (int i = 0; i < n; ++i)
	{
		int flag = 0;
		for (int j = 0; j < n; ++j)
		{
			if (mk[j]) continue;
			if (b[j] > a[i])
			{
				flag = mk[j] = 1;
				break;
			}
		}
		if (!flag)
		{
			++nocheat;
			for (int j = 0; j < n; ++j)
				if (!mk[j])
				{
					mk[j] = 1;
					break;
				}
		}
	}

	int cheat = 0;

	int a_small_ptr = 0, a_large_ptr = n - 1;
	int b_small_ptr = 0, b_large_ptr = n - 1;

	// cheat		
	for (int i = 0 ; i < n; ++i)
	{
		if (a[a_large_ptr] > b[b_large_ptr])
		{
			++cheat;
			--a_large_ptr;
			--b_large_ptr;
		} 
		else
		{
			++a_small_ptr;
			--b_large_ptr;
		}
	}

	cout << cheat << " " << nocheat << endl;
}

int main(void)
{
	int t;  cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		printf("Case #%d: ", i);
		solve();
	}
}