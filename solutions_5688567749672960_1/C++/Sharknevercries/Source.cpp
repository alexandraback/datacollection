#include<bits\stdc++.h>
using namespace std;
long long swap(long long n){
	long long res = 0;
	if (n % 10 == 0)
		return 1e14 + 5;
	while (n > 0)
		res = res * 10 + n % 10, n /= 10;
	return res;
}
int digit(long long n, int k){
	while (k > 0)
		n /= 10, k--;
	return n % 10;
}
long long solve(long long n){
	long long res = 0; 
	long long last = 0, cost = 0;;
	for (long long tmp = n; tmp > 0; last++, tmp /= 10);
	long long s = n % (long long)pow(10, last / 2);
	if (s == 1 && swap(n) < n)
		n = swap(n), res++;
	while (n != 0){
		int op = 0;
		last = cost = 0;
		for (long long tmp = n; tmp > 0; last++, tmp /= 10);
		s = n % (long long)pow(10, last / 2);
		if (s == 0)
			cost = 1;
		else if (s != 1)
			cost = s - 1;
		else
			cost = 1;
		n -= cost;
		res += cost;
		if (swap(n) < n)
			n = swap(n), res++;
	}
	return res;
}
int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		long long n;
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", c++, solve(n));
	}
	return 0;
}