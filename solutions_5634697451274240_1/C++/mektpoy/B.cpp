#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define sc second
#define ft first

#define FOR(i,N) for (int i=1; i<=N; i++)
#define REP(i,l,r) for (int i=l; i<=r; i++)

#define INF ~0U>>1
#define eps 1e-9

char s[100010];

int main ()
{
#ifndef ONLINE_JUDGE
#ifndef MEKTPOY
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
#else
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
#endif
#endif
	int T, n;
	cin >> T;
	for (int test = 1; test <= T; test ++)
	{
		scanf ("%s", s);
		n = strlen(s);
		int ans;
		if (strstr(s, "-") == NULL) ans = 0;
		else
		for (int k = 1; ; k ++)
		{
			for (int i = 1; i < n; i ++)
			{
				if (s[i] == s[0])
				{
					if (s[0] == '+') s[i] = '-';
					else s[i] = '+';
				}
				else break;
			}
			if (s[0] == '+') s[0] = '-'; else s[0] = '+';
			if (strstr(s, "-") == NULL) { ans = k; break; }
		}
		printf ("Case #%d: %d\n", test, ans);
	}
	return 0;
}

