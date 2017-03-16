#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;
#define N 5000000
#define oo 1000000000
#define mod 1000000007
long long sa, sb, k;
long long ans = 0;
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int tot;
	cin >> tot;
	for (int tt = 1; tt <= tot; tt++)
	{
		ans = 0;
		cin >> sa >> sb >> k;
		sa--, sb--, k--;
		cout << "Case #" << tt << ": ";
		for (long long s1 = 0; s1 <= sa; s1++)
			for (long long s2 = 0; s2 <= sb; s2++)
				if ((s1 & s2) <= k)
					ans++;
		cout << ans << endl;
	}
	return 0;
}
