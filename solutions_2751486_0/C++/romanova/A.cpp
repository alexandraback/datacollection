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
pair<int, int> segs[1000005];
int sz = 0;

bool isvov(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int t, n, l;
	long long ans;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt)
	{
		scanf("%s%d", s, &n);
		l = strlen(s);

	/*	ans = (l-n+2ll)*(l-n+1)/2;
		sz = 0;
		for(int i = 0; i < l; ++i)
			if(isvov(s[i]))
				segs[sz++] = make_pair(max(0, i-n+1), min(l-1, i+n-1));

		int fs = -1, ls;
		for(int i = 0; i < sz; ++i)
		{
			if(!i || segs[i].first > segs[i-1].second)
				fs = segs[i].first;
			if(i == sz - 1 || segs[i+1].first > segs[i].second)
			{
				ls = segs[i].second;
				ans -= 1ll * (ls-fs-n+3)*(ls-fs-n+2)/2;
			}
		}
*/
		long long ach = 0;
		for(int i = 0; i < l; ++i)
			for(int j = i; j < l; ++j)
				if(j-i+1 >= n)
				{
					int mxl = 0, tl = 0;
					for(int k = i; k <= j; ++k)
					{
						if(!isvov(s[k]))
							++tl;
						else
						{
							mxl = max(mxl, tl);
							tl = 0;
						}
					}
					mxl = max(mxl, tl);
					if(mxl >= n)
						++ach;
				}
/*		if(ach != ans)
			printf("ERROR %d\n", tt);
*/
		printf("Case #%d: %lld\n", tt, ach);
	}

	return 0;
}