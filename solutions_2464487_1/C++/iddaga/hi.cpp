#include <stdio.h>
int main()
{
	freopen("input.txt","r",stdin);
	FILE *out=fopen("output.txt","w");
	int t, T;
	long long r, k, s, e, m, a;

	scanf("%d",&T);
	for (t = 1; t <= T; t++) {
		printf("t = %d\n",t);
		fprintf(out,"Case #%d: ",t);
		scanf("%lld%lld",&r,&k);
		for (s = 1, e = k; s <= e;) {
			m = (s+e)/2;
			a = k;
			a /= m;
			a /= 2*m+2*r-1;
			if (a >= 1) s = m+1;
			else e = m-1;
		}
		fprintf(out,"%lld\n",s-1);
	}
	fclose(out);
	return 0;
}