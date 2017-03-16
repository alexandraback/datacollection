#include <stdio.h>
#define MN 10000
struct DATA {
	int n, i;
	DATA(int _n = 0, int _i = 0) {n = _n; i = _i;}
};
long long r;
int E, R, N;
int v[MN];
int M[MN];
DATA qu[MN]; int qs, qe;
int main()
{
	freopen("input.txt","r",stdin);
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;

	scanf("%d",&T);
	for (t = 1; t <= T; t++) {
		printf("t = %d\n",t);
		fprintf(out,"Case #%d: ",t);
		scanf("%d%d%d",&E,&R,&N);
		for (i = 0; i < N; i++)
			scanf("%d",&v[i]);
		r = 0;
		if (R < E) {
			qs = qe = 0;
			qu[qe++] = DATA(E,0); k = E;
			for (i = 0; i < N; i++) {
				M[i] = v[i];
				for (j = i-1; j >= 0; j--) {
					M[j] = M[j+1];
					if (M[j] < v[j]) M[j] = v[j];
				}
				k += R;
				if (k > E) {
					for (; qs < qe; qs++) {
						if (k-E >= qu[qs].n) {
							r += (long long)qu[qs].n*M[qu[qs].i];
							k -= qu[qs].n;
						}
						else {
							r += (long long)(k-E)*M[qu[qs].i];
							qu[qs].n -= k-E;
							k = E;
							break;
						}
					}
				}
				if (i+1 < N)
					qu[qe++] = DATA(R,i+1);
			}
			for (; qs < qe; qs++)
				r += (long long)qu[qs].n*M[qu[qs].i];
		}
		else {
			for (i = 0; i < N; i++)
				r += (long long)E*v[i];
		}
		fprintf(out,"%lld\n",r);
	}
	fclose(out);
	return 0;
}