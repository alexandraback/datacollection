#include <bits/stdc++.h>
using namespace std;

inline long long function(long long n) {
	long long m = 1;

	bool v[10];
	int L = 0;

	memset(v, 0, sizeof v);
	while(1) {		
		long long N = m * n;
		while(N) {
			if(v[N % 10] == false) {
				v[N % 10] = true;
				++L;
			}
			N /= 10;
		}
		if(L == 10) break;
		m += 1;
	}
	return (n * m);
}

int main(int argc, char const *argv[])
{
	freopen("sublime-in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	int cs = 0;
	while(t--) {
		int n;
		scanf("%d", &n);
		if(n == 0) printf("Case #%d: INSOMNIA\n", ++cs);
		else printf("Case #%d: %lld\n", ++cs, function(n));
	}
	return 0;
}