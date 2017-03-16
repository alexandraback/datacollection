#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int f[1000005];
int T, N;
int main(int argc, char** argv) {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	f[1] = 1;
	for (int i=2; i<=1000000; i++) {
		f[i] = f[i-1] + 1;
		if (i%10) {
			int j = i, s = 0;
			for ( ; j>0; j /= 10) s = s*10 + j % 10;
			if (s < i && f[i] > f[s] +1) f[i] = f[s] + 1;
		}
	}
	
	scanf("%d", &T);
	for (int times=1; times<=T; times++) {
		scanf("%d", &N);
		printf("Case #%d: %d\n", times, f[N]);
	}
	/*
	for (int i=1; i < 1000000; i++) {
		printf("%d ", f[i]);
		if (i%5 == 0) printf("\n");
	}*/
	return 0;
}

