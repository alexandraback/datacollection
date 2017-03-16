#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define MAXN 1000001

inline bool is_vow(char ch)
{
	return ch == 'a' || ch == 'i' || ch == 'u' || ch == 'o' || ch == 'e';
}

int k, n, l;
char s[MAXN];
int pos[MAXN];

inline ll solve()
{
	scanf("%s %d", s, &k);
	n = strlen(s);
	ll r = 0;
	l = 0;
	for (int i = 0, kol = 0, c = -1; i < n; ++i)
	{
		if (!is_vow(s[i]))
		{
			if (!c)
				++kol;
			else
				kol = 1;
			if (kol >= k)
				pos[l++] = i;
			c = 0;
		}
		else
		{
			if (c == 1)
				++kol;
			else
				kol = 1;
			c = 1;
		}
		if (l)
			r += (pos[l - 1] - k + 2);
	}
	return r;
}

int main()
{
	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
		printf("Case #%d: "I64"\n", t + 1, solve());
	return 0;
}
