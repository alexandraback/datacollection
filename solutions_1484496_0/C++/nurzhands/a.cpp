// iTwin
#ifdef UNIX
#define i64 "%lld"
#else
#define i64 "%I64d"
#endif

#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <bitset>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define fill(a,key) memset(a, key, sizeof(a))
#define all(x) x.begin(), x.end()
#define sqr(x) (x)*(x)
#define fi first
#define se second
#define forn(i,n) for (i = 0; i < n; i++)
#define curtime double(clock())/double(CLOCKS_PER_SEC)
typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int dx[] = {-1,0,1,0,-1,-1,1,1,0};
const int dy[] = {0,1,0,-1,-1,1,1,-1,0};
const int inf = 1<<30;

int sum,cur,i,t,x,n,s[20],mask,cnt,j;

ii a[1<<20];

int main()
{
	//ios_base::sync_with_stdio(0);
	srand(time(0));
	#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	cin >> t;

	for (x = 1; x <= t; x++)
	{
		cin >> n;

		sum = 0;

		for (i = 0; i < n; i++)
		{
			cin >> s[i];
			sum += s[i];
		}

		printf("Case #%d:\n", x);

		cnt = 0;

		for (mask = 1; mask < 1048576; mask++)
		{
			cur = 0;
			for (i = 0; i < n; i++)
			if (mask&(1<<i))
				cur += s[i];
			a[cnt++] = mp(cur,mask);
		}

		sort(a,a+cnt);

		for (i = 1; i < cnt; i++)
		if (a[i].first == a[i-1].first)
		{
			for (j = 0; j < n; j++)
			if (a[i].second&(1<<j))
				printf("%d ", s[j]);
			printf("\n");
			for (j = 0; j < n; j++)
			if (a[i-1].second&(1<<j))
				printf("%d ", s[j]);
			printf("\n");
			goto br;
		}

		printf("Impossible\n");

		br:;
	}

	return 0;
}