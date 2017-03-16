#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define ll long long

int t, a, b;
map<ll, int> m;
map<ll, int>::iterator it;

int f(int n) {
	int c = 0;
	while (n) {
		n /= 10;
		c++;
	}
	return c;
}

int c[10];
int r(int n, int d) {
	int t = f(n), ans = 0;
	memset(c, 0, sizeof c);
	for (int i = 0; i < t; i++){
		c[i] = n % 10;
		n /= 10;
	}
	int k = 1;
	for (int i = d, j = 1; i < t; i++, j *= 10, k *= 10)
		ans += c[i] * j;
	for (int i = 0; i < d; i++, k *= 10)
		ans += c[i] * k;
	return ans;
}

int rmin(int &n) {
	int minimum = 214748364, t = n;
	for (int i = 0; i < f(n); i++)
		minimum = min(minimum, r(n, i));
	return minimum;
}

int main() {
	scanf("%d", &t);
	
	for (int C = 1; C <= t; C++) {
		m.clear();
		
		scanf("%d %d", &a, &b);
		
		for (int i = a; i <= b; i++)
			m[rmin(i)]++;
		
		long long ans = 0;
		for (it = m.begin(); it != m.end(); it++)
			if ((*it).second >= 2)
				ans += (*it).second * ((*it).second - 1) / 2;
		
		printf("Case #%d: %lld\n", C, ans);
	}
	return 0;
}
