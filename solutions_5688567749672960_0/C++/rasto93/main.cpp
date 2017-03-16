#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <numeric>
#include <tuple>
#include <climits>

#define INF 1023456789
#define SQR(x) ((x)*(x))
#define INIT(x,y) memset((x),(y),sizeof((x)))
#define SIZE(x) ((int)((x).size()))
#define REP(i, n) for (__typeof(n) i=0;i<(n);++i)
#define FOR(i, a, b) for (__typeof(a) i=(a);i<=(b);++i)
#define FORD(i, a, b) for (__typeof(a) i=(a);i>=(b);--i)
#define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)

#define DEBUG
#ifdef DEBUG
#define DBG(x) cerr << #x << ": " << (x) << endl;
#else
#define DBG(x)
#endif

using namespace std;
 
typedef long long LL;
typedef pair<int,int> PI;
typedef tuple<int,int,int>trio;

int P[1000047];

int rev(int x)
{
	int res = 0;
	while (x)
	{
		res = res*10 + (x%10);
		x /= 10;
	}
	return res;
}

void solve(int t)
{
	int N;
	scanf("%d",&N);
	printf("Case #%d: %d\n",t,P[N]);
}

int main()
{
	REP(i,1000047) P[i] = INT_MAX;
	P[1] = 1;
	queue<int>Q;
	Q.push(1);
	while (!Q.empty())
	{
		int x = Q.front();
		if (x>=1000000) break;
		Q.pop();
		if (P[x+1] > P[x] + 1) 
		{
			P[x+1] = P[x] + 1;
			Q.push(x+1);
		}
		int r = rev(x);
		if (P[r] > P[x] + 1)
		{
			P[r] = P[x] + 1;
			Q.push(r);
		}
	}
	int T;
	scanf("%d",&T);
	REP(i,T) solve(i+1);
        return 0;
}
