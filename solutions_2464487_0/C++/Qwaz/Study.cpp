#include <cstdio>

typedef long long ll;

ll r, t;

void input(){
	scanf("%lld%lld", &r, &t);
}

ll calc(ll s){
	return 2*s-1+2*r;
}

void solve(){
	ll f=1, s=1000000000, m, max=0;

	while(f <= s){
		m = (f+s)>>1;
		if(calc(m) <= t/m){
			if(max < m) max = m;
			f = m+1;
		} else
			s = m-1;
	}

	printf("%lld\n", max);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cc;

	scanf("%d", &cc);
	for(t=1; t<=cc; t++){
		printf("Case #%d: ", t);
		input();
		solve();
	}

	return 0;
}