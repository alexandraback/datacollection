#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i(a), _b(b); i < _b; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORD(i,a,b) for(int i(a), _b(b); i >= _b; --i)
#define sz(a) (int)((a).size())
#define X first
#define Y second
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<pii> vpii;

#define N 222

int a[N],n,m,x,y;
double p[N];
bool used[N];
bool flag;

int main()
{
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int test;
	scanf("%d",&test);
	REP(t,test)
	{
		scanf("%d", &n);
		x = 0;
		REP(i, n)
		{
			scanf("%d", &a[i]);
			x += a[i];
		}
		memset(used,0,sizeof(used));
		printf("Case #%d:", t+1);
		flag = false;
		while(!flag)
		{
			flag = true;
			y = 0;
			m = 0;
			REP(i, n)
				if(!used[i])
				{
					y += a[i];
					++m;
				}
			REP(i, n)
				if(!used[i])
				{
					p[i] = 100 * (double(x + y) / (m * x) - double(a[i]) / x);
					if(p[i] < 0)
					{
						p[i] = 0;
						used[i] = true;
						flag = false;
					}
				}
		}
		REP(i,n)
			printf(" %.9lf", p[i]);
		printf("\n");
	}
	return 0;
}