#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<functional>
#include<algorithm>

using namespace std;

#define _INFILE		"B-small-attempt0.in"
#define _OUTFILE	"B-small0.out"
//#define _INFILE		"B.in"
//#define _OUTFILE	"B.out"

typedef long long ll;

int solve()
{
	int n, s, p;
	scanf("%d%d%d",&n,&s,&p);

	int result = 0;
	for(int i=0; i<n; i++)
	{
		int t;
		scanf("%d",&t);
		int average = t / 3;
		int remain = t % 3;
		if (average >= p || (average == p - 1 && remain > 0))
		{
			result++;
		}
		else if (average == p - 1 && t > 0 && s > 0)
		{
			s--;
			result++;
		}
		else if (average == p - 2 && remain == 2 && s > 0)
		{
			s--;
			result++;
		}
	}

	return result;
}

int main(void)
{
	int T;
	freopen(_INFILE, "r", stdin);
	freopen(_OUTFILE, "w", stdout);
	scanf("%d",&T);
	for(int i=0; i<T; i++)
	{
		printf("Case #%d: %d\n", i+1, solve());
	}
	return 0;
}

