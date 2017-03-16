#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <set>
#include <string>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tcase = 1; tcase <= t; tcase++)
	{
		printf("Case #%d: ", tcase);
		int a, b, k, ans = 0;
		cin >> a >> b >> k;
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				if ((i & j) < k)
					ans++;
		
		printf("%d\n", ans);				
	}
}