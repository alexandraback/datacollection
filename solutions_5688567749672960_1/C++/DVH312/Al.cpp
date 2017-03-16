#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1000000;
int T;
long long n;
long long f[22];
long long kbase(long long k){
	long long res = 0;
	long long n1 = 1;
	long long n2 = 1;

	for (int i = 1; i <= k / 2; i++) n1 *= 10;
	for (int i = 1; i <= k - (k / 2); i++) n2 *= 10;
	res = n1 + n2 -1;
	return res;
}
long long xuly(long long x2){
	long long x = x2;
	long long num1, num2;
	num1 = num2 = 0;
	string s;
	s.clear();
	while (x > 0){
		s = (char)('0' + (x % 10)) + s;
		x /= 10;
	}

	for (int i = s.length() / 2; i < s.length(); i++) num1 = num1 * 10 + (s[i] - '0');
	for (int i = s.length() / 2 - 1; i >= 0; i--) num2 = num2 * 10 + (s[i] - '0');
	if (num2 == 1) return f[s.length() - 1] + num1;
	return num1 + num2 + f[s.length() - 1];
	
}
int main(){	
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d", &T);
	for (int test = 1; test <= T; test++){
		scanf("%lld", &n);
		for (int i = 1; i <= 14; i++) f[i] = kbase(i) + f[i - 1];

		long long res = xuly(n);
		if (n % 10 == 0) res = xuly(n - 1) + 1;

		printf("Case #%d: %d\n", test, res);
	}
	return 0;
}