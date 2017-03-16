#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define _(a, b) memset(a, b, sizeof(a))

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 4000000000000000000ll;
const double eps = 1e-9;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int TEST = 0;

char s[1000005];
int l, n;

bool isVowel(char x)
{
	return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

bool solve()
{
	lint ans = 0ll;
	vector< pair<int, int> > parts;

	scanf("%s%d", s, &n);
	l = strlen(s);
	s[l] = 'a';

	for (int i = 0; i < l; i++)
		if (!isVowel(s[i]))
		{
			int st = i;
			while (!isVowel(s[i])) i++;
			int en = i;
			i--;
			parts.pb( mp(en - st, st) );
		}

	lint prev = 0ll;
	for (int i = 0; i < parts.size(); i++)
	{
		lint len = parts[i].first;
		lint off = parts[i].second - prev;
		lint off2 = l - parts[i].second - len;

		if (len >= n)
		{
			ans += (len - n) * (off + 1);
			ans += (len - n) * (off2 + 1);

			lint v = max(len - 2 - n + 1, 0ll);
			ans += v * (v + 1) / 2;

			ans += (off + 1) * (off2 + 1);
			prev = parts[i].second + len + 1 - n;
		}
	}

	TEST++;
	printf("Case #%d: %lld\n", TEST, ans);

	return false;
}

int main()
{
	prepare();
	int tn;
	for (scanf("%d", &tn); tn; tn--)
		solve();
	return 0;
}