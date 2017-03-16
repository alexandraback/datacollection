#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long n, x, y, z;
long long a[20], _10[20];
long long ans;
int w;

void init() {
	int tmp = 20;
	a[1] = 1;
	for (int i = 2; i <= 16; i++) {
		a[i] = a[i-1]+tmp-1;
		if (i % 2)
			tmp *= 10;
	}
	_10[0] =1;
	for (int i = 1; i <= 16; i++)
		_10[i] = _10[i-1]*10;
}

long long form(int tn) {
	long long ret;
	ret = (_10[tn/2]-1)*_10[tn-tn/2]+1;
	return ret;
}

int getW(long long n) {
	int ret = 0;
	while (n) {
		ret++;
		n /= 10;
	}
	return ret;
}

long long solve(long long n) {
	long long ret = 0;
	int p[20];
	x = n;
	for (int i = 0; i < w; i++) {
		p[i] = n % 10;
		n /= 10;
	}
	p[0] = 1;
	for (int i = 1; i < w/2; i++) {
		if (p[i])
			p[i] = 0;
	}
	y = 0;
	for (int i = w-1; i >= 0; i--) {
		(y *= 10) += p[i];
	}
	ret += (x - y);
	z = 0;
	for (int i = 0; i < w; i++) {
		(z *= 10) += p[i];
	}
	//cout << x << " " << y << " " << z << endl;
	//cout << "ret = " << ret << endl;
	if (z != y)
		ret++;
	//cout << "ret = " << ret << endl;
	if (w <= 2)
		ret += z;
	else
		ret += ((z-form(w-1))+a[w-1]);
	//cout << "form(w-1) = " << form(w-1) << endl;
	//cout << "a[w-1] = " << a[w-1] << endl;
	//cout << "ret = " << ret << endl;
	return ret;
}

int main(void) {

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int t;
	init();
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%I64d", &n);
		ans = 0;
		if (n % 10 == 0) {
			ans++;
			n--;
		}
		w = getW(n);
		if (w != 0) {
			ans += solve(n);
		}
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}
