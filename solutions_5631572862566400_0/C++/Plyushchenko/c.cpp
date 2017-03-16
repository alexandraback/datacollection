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
const int z = 11;
const double eps = 1e-9;
const int inf = int(1e9);
const ll llinf = ll(1e18);
using namespace std;

int a[z], e[z];
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
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
			cin >> e[i];
		}
		do
		{
/*			for (int k = 1; k <= n; k++)
				cout << a[k] << " ";
			cout << "\n";
*/			for (int k = 2; k <= n; k++)
			{
/*			    for (int i = 1; i <= k; i++)
			    	cout << a[i] << " ";
				cout << "\n";			    			
				for (int i = 1; i <= k; i++)
			    	cout << e[a[i]] << " ";
				cout << "\n";
				cout << (e[a[1]] == a[2] || e[a[1]] == a[k]) << " ";			    			
				for (int i = 2; i < k; i++)
					cout << (e[a[i]] == a[(i + 1)] || e[a[i]] == a[(i - 1)]) << " ";
				cout << (e[a[k]] == a[k - 1] || e[a[k]] == a[1]) << " ";
				cout << "\n\n";
*/			    int ok = (e[a[1]] == a[2] || e[a[1]] == a[k]) && (e[a[k]] == a[k - 1] || e[a[k]] == a[1]);
				for (int i = 2; i < k && ok && (k >= ans); i++)
					ok &= (e[a[i]] == a[(i + 1)] || e[a[i]] == a[(i - 1)]);					
				if (ok)
					ans = max(ans, k);
			}
		}
		while (next_permutation(a + 1, a + n + 1));
		cout << "Case #" << test << ": " << ans << "\n";

	}	
	
	return 0;
}