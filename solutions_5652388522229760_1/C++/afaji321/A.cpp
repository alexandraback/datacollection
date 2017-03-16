#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
bool seen[99];
int ct = 0;
int T;

void count_dig(long long X) {
	while (X > 0) {
		int d = X % 10;
		if (seen[d] == 0)
			ct++;
		seen[d] = 1;
		X /= 10;
	}
}

int main() {

	scanf("%d",&T);
	for (int tt = 1 ;tt <= T;tt++) {
		memset(seen,0,sizeof seen);
		ct = 0;

		printf("Case #%d: ",tt);

		long long N, S;
		scanf("%lld",&N);
		if (N == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		S = 0;
		while (ct < 10) {
			S += N;
			count_dig(S);
		}
		printf("%lld\n",S);

	}

}