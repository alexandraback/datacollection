#include <algorithm>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <deque>
#include <ctime>
#include <list>
#include <set>
#include <map>
//zlb//

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
int MOD    = 1000000007;
int MAXINT = 2147483647;
LL INFLL   = 1000000000000000000LL;
LL MAXLL   = 9223372036854775807LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back
#define SIZE(a)       (int)a.size()
#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))
#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)
#define RESET(a, b)   memset(a,b,sizeof(a))
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ------------ //

int A,B,K;

LL dp[35][2][2][2];

LL go(int pos,int limA,int limB,int limK)
{
	if (pos == -1) return 1;
	if (dp[pos][limA][limB][limK] != -1) return dp[pos][limA][limB][limK];
	bool dA = (A & (1 << pos));
	bool dB = (B & (1 << pos));
	bool dK = (K & (1 << pos));
	LL ans = 0;
	FOR(pA,0,1)
	{
		if (limA && pA > dA) continue;
		FOR(pB,0,1)
		{
			if (limB && pB > dB) continue;
			bool pK = pA&pB;
			if (limK && pK > dK) continue;
			int nA = limA;
			int nB = limB;
			int nK = limK;
			if (pA != dA) nA = 0;
			if (pB != dB) nB = 0;
			if (pK != dK) nK = 0;
			ans += go(pos-1,nA,nB,nK);
		}
	}
	return dp[pos][limA][limB][limK] = ans;
}

int main()
{
	int tc,T=0;
	scanf("%d",&tc);
	while(tc--)
	{
		RESET(dp,-1);
		T++;
		scanf("%d%d%d",&A,&B,&K);
		A--;
		B--;
		K--;
		printf("Case #%d: %lld\n",T,go(30,1,1,1));
	}
}
