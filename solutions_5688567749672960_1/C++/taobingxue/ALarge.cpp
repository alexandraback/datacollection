#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1000005];
int T;
long long N;

long long get(long long n) {
	if (n <= 1000000) return f[n];
	int len = 0;
	int a[20];
	long long num = n;
	for (; n > 0; len ++) {
		a[len] = n%10;
		n/=10;
	}
	
	int numlen = len >> 1;
	int reslen = len - numlen;
	bool check = true;
	for (int i=0; i<reslen; i++)
		if (a[i]) { check = false; break;}
	if (check) {
		int nowp = reslen;
		while (a[nowp] == 0) {
			a[nowp] = 9;
			nowp += 1;
		}
		a[nowp] -= 1;
		if (nowp == len-1 && a[nowp] == 0 && numlen != reslen) {
			a[reslen-1] = 9;
			len -= 1;
			reslen -= 1;
		}
	}
	
	check = true;
	for (int i=reslen; i < len-1; i++) {
		if (a[i]) {check = false;
			break;
		}
	}
	if (check && a[len-1] == 1) {
		a[len-1] = 0;
		len -= 1;
		if (reslen == numlen) numlen -= 1;
		else reslen -= 1;
		for (int i=reslen; i<len; i++) a[i] = 9;
	}
	
	long long newnum = 0;
	for (int i=0; i<numlen; i++) newnum = newnum * 10 + a[len-1-i];
	for (int i=0; i<reslen; i++) newnum *= 10;
	newnum += 1;
	long long resnum = 0, newnumc = newnum;
	while (newnumc > 0) {
		resnum = resnum * 10 + newnumc%10;
		newnumc /= 10;
	}
	//printf("%I64d ", resnum);
	return get(resnum) + 1 + num - newnum;
}
int main(int argc, char** argv) {
	freopen("aL.in", "r", stdin);
	freopen("aL.out", "w", stdout);
	f[1] = 1;
	for (int i=2; i<=1000000; i++) {
		f[i] = f[i-1] + 1;
		if (i%10) {
			int j = i, s = 0;
			for ( ; j>0; j /= 10) s = s*10 + j % 10;
			if (s < i && f[i] > f[s] +1) {
				f[i] = f[s] + 1;
				// printf("%d\n", i);
			}
		}
	}
	
	scanf("%d", &T);
	for (int times=1; times<=T; times++) {
		scanf("%lld", &N);
		long long result = get(N);
		printf("Case #%d: %lld\n", times, result);
		// if (result != f[N]) printf("QAQ");
	}
	/*
	for (int i=1; i < 1000000; i++) {
		printf("%d ", f[i]);
		if (i%5 == 0) printf("\n");
	}*/
	return 0;
}

