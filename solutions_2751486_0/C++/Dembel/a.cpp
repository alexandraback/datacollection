#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

const int N = 1100000;
char s[N];
int cnt[N];

int getCount(int i, int j)
{
	if (i > j)
		return 0;
	if (cnt[i] != 0 && cnt[j] == cnt[i] + j - i)
		return cnt[j] - cnt[i] + 1;
	return cnt[j];
}

bool isConsonant(char ch)
{
	return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
}

bool check(char *s, int n, int len)
{
	int cnt = 0;
	bool ok = false;
	for (int k = 0; k < len; ++k)
	{
		cnt = isConsonant(s[k]) ? cnt + 1 : 0;
		ok |= (cnt == n);
	}
	return ok;
}

int solveStupid(char * s, int n)
{
	int ans = 0;
	for (int i = 0; s[i]; ++i)
		for (int j = i; s[j]; ++j)
		{
			if (check(s + i, n, j - i + 1))
				++ans;
		}
	dbg("%s %d = %d\n", s, n, ans);
	return ans;
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		int n;
		scanf("%s%d", s, &n);

		ll ans = 0;
		int len = strlen(s);
		cnt[0] = isConsonant(s[0]) ? 1 : 0;
		for (int i = 1; i < len; ++i)
			cnt[i] = isConsonant(s[i]) ? cnt[i - 1] + 1 : 0;

//		for (int i = 0; i < len; ++i)
//			dbg("%d ", cnt[i]);
//		dbg("\n");

		int i = 0;
		int j = 0;
		while (i < len)
		{
			while (j < len && getCount(i, j) < n)
				++j;
			if (j >= len)
				break;
			dbg("%d %d %s\n", i, j, s + i);
			if (!check(s + i, n, j - i + 1))
				throw 42;
			ans += len - j;
			++i;
		}
		printf("%lld\n", ans);
		if (ans != solveStupid(s, n))
		{
			throw 42;
		}
	}

	return 0;
}
