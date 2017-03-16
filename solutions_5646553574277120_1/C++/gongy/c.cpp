#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define upd(a,b) (a)=min((a),(b))
typedef long long ll;

int T; 
ll c, d, v, ans, t[105], ind, cur, nu;

int main(){
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%lld\n", &T);
	for(int z = 1; z <= T; z++) {
		scanf("%lld %lld %lld", &c, &d, &v);
		ans = 0;
		ind = 0;
		cur = 0;
		for(int i = 0; i < d; i++) scanf("%lld", &t[i]);
		while(cur < v) {
			if(t[ind] <= cur+1 && ind < d) {
				cur += t[ind] * c;
				ind++;
			} else {
				ans++;
				cur += (cur+1) * c;
			}
		}
		printf("Case #%d: %lld\n", z, ans);
	}
}
