#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<deque>
#include<cassert>

using namespace std;

const int INF = 1e9;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

int t;

inline void read()
{
	scanf("%d", &t);
}

bool gl[26];

inline void solve()
{
	gl[0] = true;
	gl['e' - 'a'] = true;
	gl['i' - 'a'] = true;
	gl['o' - 'a'] = true;
	gl['u' - 'a'] = true;
	forn (test, t)
	{
		string s;
		cin >> s;
		int v;
		scanf("%d", &v);
		int ans = 0;
		int tmp = 0;
		int l = -1;
		for (int i = l + 1; i < s.size(); ++i)
		{
			if(!gl[s[i] - 'a'])
			{
				tmp++;
				if(tmp >= v)
				{
					int left = i - l - v + 1;
					ans += left * (s.size() - i);
					l = i - v + 1;
				}
			}
			else
				tmp = 0;
		}
		printf("Case #%d: %d\n", test + 1, ans);
	}
}

int main()
{
#ifdef Baster
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	read();
	solve();
	return 0;
}