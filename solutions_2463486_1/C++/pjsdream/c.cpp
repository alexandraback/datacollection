#include <string.h>
#include <stdio.h>
#include <math.h>

long long a, b;
long long arr[10000000];

long long rev(long long a)
{
	long long res = 0;
	while (a) {
		res = res*10 + a%10;
		a/=10;
	}
	return res;
}

bool isPalin(long long a)
{
	return a==rev(a);
}

long long getans(long long x)
{
	return arr[(long long)sqrt((double)x)];
}

int main()
{
	FILE *ifp=fopen("c.in", "r");
	FILE *ofp=fopen("c.out", "w");

	for (long long a=1; a<=10000000; a++)
		arr[a] = arr[a-1] + (isPalin(a) && isPalin(a*a));

	int t, tt=0;
	fscanf(ifp, "%d", &t);
	while(t--) {
		fscanf(ifp, "%lld %lld", &a, &b);
		printf("%d\n", tt);
		fprintf(ofp, "Case #%d: %lld\n", ++tt, getans(b) - getans(a-1));
	}

	return 0;
}
