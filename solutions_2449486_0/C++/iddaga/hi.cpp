#include <stdio.h>
#define MN 100
int n, m;
int d[MN][MN], r[MN][MN];
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d%d",&n,&m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				fscanf(in,"%d",&d[i][j]);
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				r[i][j] = MN;
		}
		for (k = 1; k <= MN; k++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (d[i][j] > k) break;
				}
				if (j >= m) {
					for (j = 0; j < m; j++) {
						if (r[i][j] > k) r[i][j] = k;
					}
				}
			}
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					if (d[j][i] > k) break;
				}
				if (j >= n) {
					for (j = 0; j < n; j++) {
						if (r[j][i] > k) r[j][i] = k;
					}
				}
			}
		}
		k = 1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (d[i][j] != r[i][j]) k = 0;
			}
		}
		fprintf(out,"%s\n",k?"YES":"NO");
	}
	fclose(in);
	fclose(out);
	return 0;
}