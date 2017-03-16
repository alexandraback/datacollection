#include<cstdio>
#include<algorithm>

using namespace std;

int tc;
long long ans;
long long r,t;
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tcc=0;
	scanf("%d", &tc);
	while(tc--){
		scanf("%lld %lld", &r, &t);
		ans = 1;
		long long l = 1;
		long long u = 1000000000;
		long long m;
		while (l <= u) {
			m = (l+u)/2;
			if (2*r-3 <= t/m+1 && 2*m*(m+1)+m*(2*r-3) <= t) {
				ans = max(ans, m);
				l = m+1;
			} else {
				u = m-1;
			}
		}
		printf("Case #%d: %lld\n", ++tcc, ans);
	}
	return 0;
}