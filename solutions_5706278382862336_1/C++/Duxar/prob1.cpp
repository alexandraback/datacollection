#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;

#define LL long long

typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back

LL gcd (LL a, LL b) {
	LL r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void solve() {
	LL p, q, g;
	scanf("%lld/%lld", &p, &q);
	g = gcd(p, q);
	q /= g;
	p /= g;
	if ((q - (q & ((q - 1) ^ q))) > 0) {
		printf("impossible");
		return ;
	}
	if (p == 1 && q == 2) {
		printf("1");
		return;
	}
	LL b;
	LL pw;
	for (b = 2, pw = 1; b <= q; ++pw, b *= 2) { 
		LL cnt = q / b;
		LL a = cnt;		
		if (a <= p) break;
	}
	printf("%lld", pw);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}
	
	return 0;
}

