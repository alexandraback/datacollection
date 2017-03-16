#include <cstdio>

int T, t;
int k, c, s;
long long A[110];

inline long long min ( int a, int b )
{
	if ( a > b ) return b;
	return a;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i, j;
	long long ans, mul;

	scanf("%d", &T);
	for(t=1; t<=T; t++){
		printf("Case #%d: ", t);

		scanf("%d%d%d", &k, &c, &s);

		if ( c*s < k ){ printf("IMPOSSIBLE\n"); continue; }

		for(i=1; i<=s; i++){
			for(j=1; j<=c; j++) A[j] = min ( (i-1)*c+j, k );

			ans = 1, mul = 1;
			for(j=1; j<c; j++) mul *= k;

			for(j=1; j<=c; j++){
				ans += mul * (A[j]-1);
				mul /= k;
			}
			
			printf("%lld ", ans);
			if ( i*c >= k ) break;
		} printf("\n");
	}

	return 0;
}