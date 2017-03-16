#include <bits/stdc++.h>
using namespace std;
int tcs, p, q;
int gcd(int a, int b){
	if(b==0)return a;
	else return gcd(b, a%b);
}
int main(){
	scanf("%i", &tcs);
	for(int tc = 1; tc <= tcs; tc++){
		scanf("%i/%i", &p, &q);
		int gc = gcd(p, q);
		p /= gc;
		q /= gc;
		if(q & (q - 1)) {
			printf("Case #%i: impossible\n", tc);
			continue;
		}
		int ans = 0;
		while(p/q < 1){
			p *= 2;
			ans++;
		}
		printf("Case #%i: %i\n",tc, ans);
	}
}