#include <bits/stdc++.h>
using namespace std;
long long tcs, p, q;
long long gcd(long long a, long long b){
	if(b==0)return a;
	else return gcd(b, a%b);
}
int main(){
	scanf("%lld", &tcs);
	for(long long tc = 1; tc <= tcs; tc++){
		scanf("%lld/%lld", &p, &q);
		long long gc = gcd(p, q);
		p /= gc;
		q /= gc;
		if(q & (q - 1)) {
			printf("Case #%i: impossible\n", tc);
			continue;
		}
		long long ans = 0;
		while(p/q < 1){
			p *= 2;
			ans++;
		}
		printf("Case #%lld: %lld\n",tc, ans);
	}
}