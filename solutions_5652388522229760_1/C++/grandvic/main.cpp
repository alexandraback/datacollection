#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <deque>
#include <iterator>
#include <string>
#include <limits>
 
using namespace std;

void solve()
{
	long long n; cin >> n;
	if (n == 0)
	{
		cout << "INSOMNIA" << endl;
	}
	else
	{
		set<int> a;
		for (long long i = 1; a.size() < 10; ++i)
		{
			long long k = i * n;
			while (k)
			{
				a.insert(k % 10);
				k /= 10;
			}
			if (a.size() == 10)
			{
				cout << (n * i) << endl;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("i:/input.txt", "rt", stdin);
	int T; cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ": ";
		solve();
	}
}
