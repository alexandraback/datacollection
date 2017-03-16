#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

string richard = "RICHARD";
string gabriel = "GABRIEL";

string solve()
{
	int n, r, c;
	scanf("%d%d%d", &n, &r, &c);
	
	if ( (r * c) % n != 0)
		return richard;

	if (n >= 7)
		return richard;
	if (n <= 2)
		return gabriel;
	if (r < n && c < n)
		return richard;
	
	if (r > c)
		swap(r, c);
	if (n >= 3)
	{
		if (n >= r + r + 1)
			return richard;
		for (int len = r; len + r - 1 <= n && len <= c; len++)
		{
			int mn = 0;
			int mx = len * r - n;

			for (int i = mn; i < mx; i++)
			{
				bool bad = true;
				for (int j = 0; j + len <= c; j++)
				{
					if ( (r * j + i) % n == 0)
						bad = false;
				}
				if (bad)
					return richard;
			}
		}
		
		return gabriel;
	}

	return gabriel;
}


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		eprintf("Case %d..%d", i, t);
		printf("Case #%d: ", i);
		printf("%s", solve().c_str() );
		printf("\n");
		eprintf("  done\n");
	}

	return 0;
}


