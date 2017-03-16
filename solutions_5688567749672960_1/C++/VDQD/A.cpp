#include <bits/stdc++.h>
using namespace std;

long long rev(long long x){
	long long R = 0;
	while (x > 0){
		R = R * 10 + x % 10;
		x /= 10;
	}
	return R;
}

long long sep(long long n, long long res){
    long long N1 = n, N2 = 0;
    while (N1 > 0){
        N2 = N2 * 10 + N1 % 10;
        N1 /= 10;
        res = min(res, rev(N1) + rev(N2));
    }
    return res;
}

long long solve(long long n){
	long long x = 1, res = 1, R;
	long long N1, N2;
	while (x < n){
        if (n < x*10){
            R = n - x;
            if (n % 10 != 0) R = sep(n, R);
            if ((n-1) % 10 != 0) R = sep(n-1, R-1) + 1;
            res += R;
            return res;
        }
        else{
            x *= 10;
            res += sep(x-1, (x-1)-(x/10)) + 1;
        }
        //printf("all = %lld, x = %lld\n", res, x);
	}
	return res;
}

int main(){
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    while (t--){
    	long long n;
    	scanf("%lld", &n);
    	printf("Case #%d: %lld\n", ++cases, solve(n));
    }
	return 0;
}
