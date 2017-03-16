#include <algorithm>
#include <cstdio>
#include <climits>
using namespace std;

int
main ()
{
	freopen ("Bl.in","r",stdin);
	freopen ("Bl.out","w",stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		int n, s, p, ans = 0;
		scanf ("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i ++){
			int t;
			scanf ("%d", &t);
			int tt = t - p*3;
			if ((-4 == tt || -3 == tt) && p-2 >= 0){
				if (s > 0){
					s --;
					ans ++;
				}
			}else if (-3 < tt) {
				ans ++;
			}
		}
		printf ("Case #%d: %d\n", tc, ans);
	}
	return 0;
}