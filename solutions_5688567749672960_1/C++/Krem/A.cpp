#include <cstdio>

typedef long long ll;

long long pow[20];

int main() {
	pow[0] = 1;
	for(int i = 1; i < 20; i++)
		pow[i] = pow[i-1]*10;
	int T; scanf("%d", &T);
	for(int _ = 0; _ < T; _++) {
		ll n; scanf("%lld", &n);
		if(n < 10) {
			printf("Case #%d: %lld\n", _+1, n);
			continue;
		}
		ll res = 1;
		long long nn = 1;
		int nn_c = 0;
		long long xx = 1;
		int xx_c = 0;
		while(nn*10 <= n) { nn*= 10; nn_c++;}
		if(xx < nn && xx == 1) {
			res += 9;
			xx*= 10;
			xx_c++;
		}
		while(xx < nn) {
			res += pow[xx_c/2+1]+pow[xx_c/2+xx_c%2]-1;
			xx*= 10;
			xx_c++;
		}
		ll half = 1;
		for(int i = 0; i < ((nn_c)/2+1); i++) {
			half *= 10;
		}
		ll front = n/half;
		ll back = n%half;
		ll other_half = nn/half;
		ll rev_front = 0;
		for(ll x = front; x > 0; x /= 10) {
			rev_front = rev_front*10 + x%10;
		}
		rev_front--;
		if(back == 0) {
			if(front == other_half) {
				//pass
			} else {
				res++;
				n--;
				ll front = n/half;
				ll back = n%half;
				ll other_half = nn/half;
				ll rev_front = 0;
				for(ll x = front; x > 0; x /= 10) {
					rev_front = rev_front*10 + x%10;
				}
				rev_front--;
				res += back;
				if(front != other_half) {
					res += 1 + rev_front;
				}
			}
		} else {
			res += back;
			if(front != other_half) {
				res += 1 + rev_front;
			}
		}
		printf("Case #%d: %lld\n", _+1, res);
	}
	return 0;
}
