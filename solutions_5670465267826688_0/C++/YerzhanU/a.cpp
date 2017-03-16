#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
#define sz(s) (int(s.size()))
#define fname "a"
#define ms(a,x) memset(a, x, sizeof(a))
#define forit(it,s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define MAXN 1000001

int n;
ll k;
char s[MAXN];

inline int get(int a, int b)
{
	if (a == 1) return b;
	if (b == 1) return a;
	if (a == 2 && b == 2) return -1;
	if (a == 2 && b == 3) return 4;
	if (a == 2 && b == 4) return -3;

	if (a == 3 && b == 2) return -4;
	if (a == 3 && b == 3) return -1;
	if (a == 3 && b == 4) return 2;

	if (a == 4 && b == 2) return 3;
	if (a == 4 && b == 3) return -2;
	if (a == 4 && b == 4) return -1;

	return 0;
}

inline int mult(int a, int b)
{
	if (a * b < 0)
		return -get(abs(a), abs(b));
	else
		return get(abs(a), abs(b));
}

inline int convert(char ch)
{
	if (ch == 'i') return 2;
	if (ch == 'j') return 3;
	if (ch == 'k') return 4;
	return 0;
}

inline int power(int a, ll b)
{
	int r = 1;
	while(b)
	{
		if (b & 1) r = mult(r, a);
		a = mult(a, a);
		b >>= 1;
	}
	return r;
}

inline void solve()
{
	scanf("%d"I64, &n, &k);
	scanf("%s", s);
	int t = 1;
	for (int i = 0; i < n; ++i)
		t = mult(t, convert(s[i]));
	int one = t;
	t = power(t, k);
	if (t != -1)
	{
		puts("NO");
		return;
	}

	int ans1 = -1, pos1 = -1;
	for (int it = 0; it < 20 && ans1 == -1; ++it)
	{
		t = power(one, it);
		for (int i = 0; i < n && ans1 == -1; ++i)
		{
			t = mult(t, convert(s[i]));
			if (t == 2)
			{
				ans1 = it;
				pos1 = i;
			}
		}
	}

	int ans2 = -1, pos2 = -1;
	for (int it = 0; it < 20 && ans2 == -1; ++it)
	{
		int tt = power(one, it);
		t = 1;
		for (int i = n - 1; i >= 0 && ans2 == -1; --i)
		{
			t = mult(convert(s[i]), t);
			if (mult(t, tt) == 4)
			{
				ans2 = it;
				pos2 = i;
			}
		}
	}

	if (ans1 == -1 || ans2 == -1 || (ans1 + ans2 + (pos1 + 1 < pos2 ? 1 : 2)) > k)
	{
		puts("NO");
		return;
	}
	puts("YES");
}

int main()
{
	#ifdef LOCAL
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	#endif

	int tt;
	scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}
