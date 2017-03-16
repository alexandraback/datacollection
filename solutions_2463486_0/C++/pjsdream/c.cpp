#include <string.h>
#include <stdio.h>

long long a, b;

bool isPalin(long long a)
{
	static char p[100];
	static char q[100];
	sprintf(p, "%lld", a);
	strcpy(q, p);
	strrev(q);
	return strcmp(p, q)==0;
}

long long getans(long long x)
{
	long long res=0;
	for (long long a=1; a*a<=x; a++) {
		if (isPalin(a) && isPalin(a*a))
			res++;
	}
	return res;
}

int main()
{
	FILE *ifp=fopen("c.in", "r");
	FILE *ofp=fopen("c.out", "w");

	int t, tt=0;
	fscanf(ifp, "%d", &t);
	while(t--) {
		fscanf(ifp, "%lld %lld", &a, &b);
		fprintf(ofp, "Case #%d: %lld\n", ++tt, getans(b) - getans(a-1));
	}

	return 0;
}
