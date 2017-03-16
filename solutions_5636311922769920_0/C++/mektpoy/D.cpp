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
	int T;
	cin >> T;
	for (int test = 1; test <= T; test ++)
	{
		int k, c, s;
		cin >> k >> c >> s;
		printf ("Case #%d: ", test);
		for (int i = 1; i <= s; i ++)
			printf ("%d ", i);
		puts("");
	}
	return 0;
}

