#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

#define all(x) (x).begin(),(x).end()

using namespace std;

const int nmax = 1e3;
int n;
int a[nmax];

long long sum(int mask)
{
	long long res = 0;
	for (int i = 0; i < n; i ++)
		if (mask & (1 << i))
			res += a[i];
	return res;
}

void print_mask(int mask)
{
	for (int i = 0; i < n; i++)
		if (mask & (1 << i))
			cout << a[i] << " ";
	cout << endl;
}

void solve(int cn)
{
	map <long long, int> m;
	printf("Case #%d:\n", cn);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int mask = 1; mask < (1 << n); mask ++)
	{
		long long s = sum(mask);
		if (m[s] == 0) 
			m[s] = mask;
		else
		{
			print_mask(m[s]);
			print_mask(mask);
			return;
		}
	}
	printf("Impossible\n");
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++)
		solve(i + 1);
	return 0;
};
