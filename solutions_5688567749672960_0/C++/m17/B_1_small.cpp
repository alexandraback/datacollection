/* Man Mohan Mishra aka m17
   IIIT - Allahabad */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <iterator>

#define MOD 1000000007
#define INF 1000000000000000000
#define PI acos(-1)

using namespace std;

long long GCD (long long a,long long b) {
	if (b == 0) return a;
	return(a % b == 0 ? b : GCD(b,a % b));
}

long long POW (long long base,long long exp) {
	long long val;
	val = 1;
	while (exp > 0) {
		if (exp % 2 == 1) {
			val = (val * base) % MOD;
		}
		base = (base * base) % MOD;
		exp = exp / 2;
	}
	return val;
}

struct num {
	int id,moves;
};

int vis[1000005];

int main()
{
//	freopen("input.in","r",stdin);
//	freopen("output.in","w",stdout);
	int t,tc;
	scanf("%d",&t);
	tc = 1;
	while (t --) {
		int n,rev;
		scanf("%d",&n);
		queue <num> q;
		struct num ss,pp;
		memset(vis,0,sizeof(vis));
		ss.id = 1;
		ss.moves = 1;
		vis[ss.id] = 1;
		q.push(ss);
		while (!q.empty()) {
			pp = q.front();
			q.pop();
			if (pp.id == n) {
				printf("Case #%d: %d\n",tc,pp.moves);
				tc += 1;
				break;
			}
			if (pp.id + 1 <= n && vis[pp.id + 1] == 0) {
				ss.id = pp.id + 1;
				ss.moves = pp.moves + 1;
				vis[ss.id] = 1;
				q.push(ss);
			}
			rev = 0;
			while (pp.id > 0) {
				rev = rev * 10 + pp.id % 10;
				pp.id = pp.id / 10;
			}
			if (rev <= n && vis[rev] == 0) {
				ss.id = rev;
				ss.moves = pp.moves + 1;
				vis[ss.id] = 1;
				q.push(ss);
			}
		}
	}
	return 0;
}
