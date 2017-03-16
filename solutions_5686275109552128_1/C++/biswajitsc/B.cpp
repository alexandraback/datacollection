#include <iostream>
#include <fstream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>

#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define foreach(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define sz(v) ((int) v.size())
#define mp(a, b) make_pair(a, b)
 
using namespace std;
 
typedef long long int lli;
typedef pair<int,int> pii;

const int maxn = 1010;

int p[maxn];

int main()
{
	int t;
	scanf("%d", &t);

	for(int tt = 1; tt<=t; tt++)
	{
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &p[i]);

		int mi = INF;
		for(int s=1; s<=maxn; s++)
		{
			int cnt = 0;
			for(int i=0; i<n; i++) cnt += (p[i]-1)/s;
			mi = min(mi, cnt+s);
		}

		printf("Case #%d: %d\n", tt, mi);
		// printf("%d\n", mi);
	}
    return 0;
}