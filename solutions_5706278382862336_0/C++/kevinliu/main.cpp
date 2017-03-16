#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long int gcd(long long int m, long long int n) {
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	if (m < n) {
		long long int tmp = m;
		m = n;
		n = tmp;
	}
	while (n != 0) {
		long long int tmp = m % n;
		m = n;
		n = tmp;
	}
	return m;
}
long long int getMi(long long zi) {
	if (zi <= 2)
		return zi;
	else {
		long long int base = 2;
		while (base < zi) {
			base = base * 2;
		}
		return base / 2;
	}
}
long long int digui(long long int zi, long long int mu) {
	//printf("digui  zi=%lld  mu=%lld \n",zi,mu);
	long long int gc = gcd(zi, mu);
	zi = zi / gc;
	mu = mu / gc;
	if (zi == mu)
		return 0;
	else if (zi == 1) {
		long long int count = 1;
		while (mu / 2 != 1) {
			mu = mu / 2;
			count++;
		}
		return count;
	} else {
		mu = mu / 2;
		return digui(getMi(zi), mu) + 1;
	}

}

int main() {
	int index, cc = 0;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out","w",stdout);
	scanf("%d", &index);
	long long int zi, mu, result, gc;
	char cha;
	while (index--) {
		scanf("%lld", &zi);
		scanf("%1s", &cha);
		scanf("%lld", &mu);
		gc = gcd(zi, mu);
		zi = zi / gc;
		mu = mu / gc;
		if (mu & (mu - 1))
			printf("Case #%d: impossible\n", ++cc);
		else {
			result = digui(zi , mu);
			printf("Case #%d: %lld\n", ++cc, result);
		}

	}
	return 0;
}
