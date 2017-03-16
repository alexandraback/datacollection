#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>

#define lld long long
#define INF 210000000
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int, int>
#define pb push_back
#define lb lower_bound
#define ub upper_bound

using namespace std;

int main()
{
	int T, n, i, j, k, cas = 0;
	int a,b;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> T;

	while (T--)
	{
		scanf("%d%d%d", &a, &b, &k);
		int ans = 0;
		for(i = 0; i < a; i++)
			for(j = 0; j < b; j++)
			if ((i & j) < k) ans++;
		printf("Case #%d: %d\n", ++cas, ans);

		}
	return 0;
}
