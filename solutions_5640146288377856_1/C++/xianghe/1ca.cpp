#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("alout.out", "w", stdout);
	int t, n, m, w;
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		cin >> n >> m >> w;
		int x = n*((m+w-1)/w)+w-1;
		cout << "Case #" << i << ": " << x << endl;
	}
	return 0;
}