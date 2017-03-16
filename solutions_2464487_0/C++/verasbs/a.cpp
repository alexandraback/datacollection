#include <stdio.h>

long long doit(long long r, long long t) {
	long long ini = 0, fim = 100000000000;
	while(ini < fim) {
		long long meio = (ini+fim)/2;
		if((2*r + 1) + 2*meio <= t/(meio+1))
			ini = meio+1;
		else fim = meio;
	}
	return ini;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++) {
		long long r, t;
		scanf("%lld %lld", &r, &t);
		printf("Case #%d: %lld\n", ca, doit(r,t));
	}
	return 0;
}
