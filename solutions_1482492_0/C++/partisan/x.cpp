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
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<vi> vii;
typedef vector<pii> vpii;

#define N 2005
#define A 255

int n,m;
double t[N],x[N],v[N],a[N],d,ans;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
	scanf("%d",&test);
	REP(tt,test)
	{
		scanf("%lf%d%d",&d,&n,&m);
		REP(i,n)
			scanf("%lf%lf",&t[i],&x[i]);
		REP(i,m)
			scanf("%lf",&a[i]);
		REP(i,n-1)
			v[i] = (x[i+1] - x[i])/(t[i+1] - t[i]);
		printf("Case #%d:\n", tt+1);
		REP(i,m)
		{
			if(n == 1)
			{
				ans = sqrt(2 * d / a[i]);
			}else
			if(n == 2)
			{
				double t_car = v[0] / a[i] + sqrt(v[0] * v[0] / (a[i] * a[i]) + 2 * x[0] / a[i]);
				double t_other = (d - x[0]) / v[0];
				if(t_car > t_other)
					ans = sqrt(2 * d / a[i]);
				else
					ans = t_other;
			}
			printf("%.9lf\n",ans);
		}
	}
	return 0;
}