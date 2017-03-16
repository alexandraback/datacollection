#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <map>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define REP(a,b) for(int a = 0; a < b; ++a)
#define FORU(a,b,c) for(int a = b; a <= c; ++a)
#define FORD(a,b,c) for(int a = b; a >= c; --a)
#define MOD 1000000000
#define MODLL 1000000000LL
#define INF 2123123123
#define pb push_back
using namespace std;

int main()
{
	int n, T, cnt;
	double a, dis, t[1005], d[1005];
	
//	freopen("2.in", "r", stdin);
//	freopen("2.out", "w", stdout);
	
	scanf("%d", &T);
	
	FORU(tc, 1, T) {
		scanf("%lf %d %d", &dis, &n, &cnt);
		
		REP(i, n)
			scanf("%lf %lf", &t[i], &d[i]);
		
		printf("Case #%d:\n", tc);
		
		REP(i, cnt) {
			scanf("%lf", &a);
			
			if (n == 1) {
				printf("%.7lf\n", sqrt(dis*2.0/a));
			}
			else if (n == 2) {
				double v = (d[1]-d[0])/(t[1]-t[0]);
				
				double time = (dis-d[0])/v;
				double ans = max(time, sqrt(dis*2.0/a));
				
				printf("%.7lf\n", ans);
			}
		}
	}
	
	return 0;
}
