#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define upd(a,b) (a)=min((a),(b))

int T, c, d, v, ans, t[105], ind, cur;
int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d\n", &T);
	for(int z = 1; z <= T; z++) {
		scanf("%d %d %d", &c, &d, &v);
		ans = 0;
		ind = 0;
		cur = 0;
		for(int i = 0; i < d; i++) scanf("%d", &t[i]);
		while(cur < v) {
			if(t[ind] <= cur+1 && ind < d) {
				cur += t[ind];
				ind++;
			} else {
				ans++;
				cur += cur+1;
			}
		}
		printf("Case #%d: %d\n", z, ans);
	}
}
