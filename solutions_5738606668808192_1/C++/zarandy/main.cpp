#include <cstdio>
#include <iostream>

using namespace std;

int db;
int t;
int n;
int j;

int numones(int x)
{
	int res = 0;
	while (x)
	{
		res += x & 1;
		x >>= 1;
	}
	return res;
}

int main()
{
	cin >> t;
	cin >> n >> j;
	//j is even
	cout << "Case #1:" << endl;
	db = 0;
	for (int i = 1; i < 1 << (n/2 - 1); i++)
	{
		if (numones(i) % 3 == 2)
		{
			cout << 1;
			for (int k = 1; k < (1 << (n/2 - 1)); k <<= 1)
			{
				cout << ((i & k) ? 1 : 0) << ((i & k) ? 1 : 0);
			}
			cout << 1 << ' ' << 3 << ' ' << 2 << ' ' << 3 << ' ' << 2 << ' ' << 7 << ' ' << 2 << ' ' << 3 << ' ' << 2 << ' ' << 3 << endl;
			db++;
			if (db == j) break;
		}
	}
	//cerr << db;
	return 0;
}
