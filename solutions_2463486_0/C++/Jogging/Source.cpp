#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

FILE *in, *out;
long long a, b, k[10004];
int cnt, s[104];

bool palin(long long x) {
	int c = 0;
	while (x) {
		s[c++] = x%10;
		x /= 10;
	}
	int i=0;
	int mid = c/2;
	for (i=0; i <= mid; i++) {
		if (s[i]!=s[c-1-i]) break;
	}
	if (i == mid+1) return true;
	return false;
}

void preprocess() {
	cnt = 0;
	int s[104];
	for (long long i=1; i < 10000000; i++) {
		if (!palin(i)) continue;
		long long tmp = i*i;
		if (palin(tmp)) {
			k[cnt++] = i;
		}
	}
	k[cnt]=k[cnt+1];
}

int bins(int x, int y, long long val) {
	while (y > x) {
		int mid = (x+y)/2;
		if (k[mid]*k[mid]<val) x=mid+1;
		else y = mid;
	}
	return x;
}

int main()
{
	preprocess();
	//printf("k[%d]: %lld\n", cnt-1, k[cnt-1]);
	in = fopen("jam.in", "r");
	out = fopen("jam.out", "w");
	int T;
	fscanf(in, "%d", &T);
	for (int cc=1; cc <= T; cc++) {
		fprintf(out, "Case #%d: ", cc);
		fscanf(in, "%lld%lld", &a, &b);
		int s = bins(0, cnt, a);
		int t = bins(0, cnt, b);
		if (k[t]*k[t]==b) t++;
		fprintf(out, "%d\n", t-s);
	}
	return 0;
}
