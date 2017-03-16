#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>
#include <cassert>
#include <unordered_set>
#include <unordered_map>

#define mp make_pair
#define pb push_back
#define problem "test"
typedef __int128 ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
const int z = 11111;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

int cnt[z];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen(problem".in", "r", stdin);
	freopen(problem".out", "w", stdout);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++)
	{
		int n;
		cin >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < 2 * n - 1; i++)
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				cnt[x] ^= 1;
			}
		cout << "Case #" << test << ": ";
		for (int i = 0; i < z; i++)
			if (cnt[i])
				cout << i << " ";
		cout << "\n";							     
	}	
	
	return 0;
}