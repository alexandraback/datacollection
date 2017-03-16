#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

char s[1000005];

bool isvov(int i)
{
	char c = s[i];
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t, n, l;
	long long ans;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt)
	{
		scanf("%s%d", s, &n);
		l = strlen(s);

		int lst = -1, tl = 0;
		long long ans = 0;
		for(int i = 0; i < l; ++i)
		{
			if(!isvov(i))
				++tl;
			else
				tl = 0;
			if(tl >= n)
			{
				ans += 1ll*(i-n+1-lst)*(l-i);
				lst = i-n+1;
			}
		}

		printf("Case #%d: %lld\n", tt, ans);
	}

	return 0;
}