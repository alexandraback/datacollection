#include<cstdio>
#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;

#define inf 1023456789
#define linf 1023456789123456789ll
#define pii pair<int,int>
#define pipii pair<int, pii >
#define pll pair<long long,long long>
#define vint vector<int>
#define vvint vector<vint >
#define ll long long
#define pdd pair<double, double>

#define DEBUG
#ifdef DEBUG
#define db(x) cerr << #x << " = " << x << endl
#else
#define db(x)
#endif

int main()
{
	int t;
	scanf("%d",&t);
	for(int testcase = 0; testcase < t; testcase++)
	{
		int d;
		scanf("%d",&d);
		vint p(d);
		int maxp = -1;
		for(int i=0; i<d; i++)
		{
			scanf("%d",&p[i]);
			maxp = max(maxp, p[i]);
		}
		int res = inf;
		for(int zec = 1; zec<= maxp; zec++)
		{
			int split = 0;
			for(int i=0; i<d; i++)
			{
				split += (p[i]-1)/zec;
			}
			res = min(res, split + zec);
		}
		printf("Case #%d: %d\n",testcase+1, res);
	}
	return 0;
}