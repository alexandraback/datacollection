#include<cstdio>

long long gcd(long long m, long long n){
	if (m % n == 0LL)return n;
	return m > n ? gcd(n, m%n): gcd(n, m);
}

bool isPow(long long n){
	while(n > 1LL){
		if (n%2 == 1LL)return false;
		n = n >> 1;
	}
	return true;
}

int period(long m, long n){
	int ret = 0;
	while(m < n){
		ret++;
		n = n >> 1;
	}
	return ret;
}

int main(){
//	freopen("a.in","r", stdin);
//	freopen("a.out", "w", stdout);
	int T;
	long long m, n;
	scanf("%d", &T);
	for(int i = 1;i <= T;i++){
		bool flag = 0;
		scanf("%lld/%lld", &m, &n);
		long long g = gcd(m, n);
		m /= g;
		n /= g;
		if(isPow(n))flag = 1;
		if(flag){
			printf("Case #%d: %d\n", i, period(m,n));
		}
		else printf("Case #%d: impossible\n", i);
	}
	return 0;
} 
