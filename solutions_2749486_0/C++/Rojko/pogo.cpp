#include<cstdio>
#include<cmath>
#include<vector>
//#include<algorithm>

using namespace std;

typedef long long ll;

void count(ll x, ll y) {
	ll suc = 0, i = 1;
	if (x != 0) {
	for (;; ++i) {
		if (suc+i <= abs(x)) {
			suc+=i;
			if (x < 0) printf("W");
			else printf("E");
		} else break;	
	}
	if (suc < abs(x)) {
		if (x<0) 
			for (int j = suc; j<abs(x); j++) { printf("EW"); i+=2; }
		else
			for (int j = suc; j<abs(x); j++) {printf("WE"); i+=2; }
	}
	}
	if (y != 0) {
	suc = 0;	
	for (;; ++i) {
		if (suc+i <= abs(y)) {
			suc+=i;
			if (y < 0) printf("S");
			else printf("N");
		} else break;	
	}
	if (suc < abs(y)) {
		if (y<0) 
			for (int j = suc; j<abs(y); j++) { printf("NS"); i+=2; }
		else
			for (int j = suc; j<abs(y); j++) { printf("SN"); i+=2; }
	}
	}
	printf("\n");
}

int main(){
	ll T;
	scanf("%lld", &T);
	for (ll t = 0; t<T; ++t) {
		ll x,y;
		scanf("%lld %lld", &x, &y);

		printf("Case #%lld: ", t+1);
		count(x,y);
	}
	return 0;
}
