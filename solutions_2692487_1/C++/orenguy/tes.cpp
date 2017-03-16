#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
#include<string>
#include<string.h>
#include<deque>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
#include<set>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

double PI = acos(-1);
double EPS = 1e-7;
int INF = 1000000000;
int MAXINT = 2147483647;
LL INFLL = 1000000000000000000LL;
LL MAXLL = 9223372036854775807LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define SIZE(a) (int)a.size()
#define ALL(a) a.begin(),a.end()
#define RESET(a,b) memset(a,b,sizeof(a))
#define FOR(a,b,c) for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a,b,c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a,b) for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); (a)++)
#define MIN(a, b) (a) = min((a), (b))
#define MAX(a, b) (a) = max((a), (b))
#define PAUSE system("pause")

#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)

pii M[8] = {mp(0,1),mp(1,0),mp(-1,0),mp(0,-1),mp(-1,1),mp(-1,-1),mp(1,-1),mp(1,1)};

/*\   \
\   \*/

int ar[1000];

int dp[105][1000005];
int n;

int go(int k,int sum)
{
	if (k > n) return 0;
	if (sum > 1000000) return 0;
	if (dp[k][sum] != -1) return dp[k][sum];
	int mins = 1+go(k+1,sum);
	int add = sum + sum-1;
	int un = -1;
	FOR(a,k,n)
	{
		if (add > ar[a])
		{	
			add += ar[a];
		}
		else
		{
			un = a;
			break;
		}
	}
	if (un == -1) MIN(mins,1);
	else if (add != sum)
	{
		MIN(mins,1+go(un,add));
	}
	return dp[k][sum] = mins;
}

int main()
{
	int T;
	scanf("%d",&T);
	FOR(tc,1,T)
	{
		RESET(dp,-1);
		int num;
		scanf("%d%d",&num,&n);
		FOR(a,1,n)
		{
			scanf("%d",&ar[a]);
		}
		sort(ar+1,ar+n+1);
		int un = -1;
		FOR(a,1,n)
		{
			if (num > ar[a])
			{
				num += ar[a];
			}
			else
			{
				un = a;
				break;
			}
		}
		printf("Case #%d: ",tc);
		if (un == -1) puts("0");
		else
		{
			printf("%d\n",go(un,num));
		}
	}
}
