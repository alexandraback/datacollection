#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0; i<int(n); ++i)
#define out(x) cout<<#x"="<<x<<endl
LL p[18], g[18];
void init() {
	p[0] = 1;
	for (int i=1; i<18; ++i)
		p[i] = p[i-1] * 10;
	for (int i=2; i<18; ++i) {
		int j = i / 2;
		g[i] = p[i-1] + p[j] - 1;
	}
}
LL rev(LL x) {
	LL y = 0;
	while(x){
		y=y*10+x%10;
		x/=10;
	}
	return y;
}
int main() {
	init();
	int T;
	scanf("%d",&T);
	REP(tt,T){
		LL n, ans = 0;
		cin >> n;
		ans = n;
		for(int i=2; i<18; ++i) {
			if(n>=rev(g[i])){
				ans -= rev(g[i]) - g[i] - 1;
			} else { // n < rev(g[i])
				 int j = i / 2;
				 if (n<=p[i-1]) break;
				 LL t = p[i-1]+rev(n-1)%p[j];
				 if (rev(t)>t) {
				 	//out(t);
				 	ans -= rev(t) - t - 1;
				 }
			}
		}
		printf("Case #%d: %lld\n", tt+1, ans);
	}
}