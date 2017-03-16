#include <stdio.h>
int R, N, M, K;
int d[7];
int main()
{
	freopen("input.txt","r",stdin);
	FILE *out=fopen("output.txt","w");
	int i, j, a, b, c, r;

	scanf("%d",&i);
	fprintf(out,"Case #1:\n");
	scanf("%d%d%d%d",&R,&N,&M,&K);
	for (i = 0; i < R; i++) {
		for (j = 0; j < 7; j++)
			scanf("%d",&d[j]);
		for (a = 2; a <= 5; a++) {
			for (b = a; b <= 5; b++) {
				for (c = b; c <= 5; c++) {
					for (j = 0; j < 7; j++) {
						if (d[j] == 1 || d[j] == a || d[j] == b || d[j] == c
						|| d[j] == a*b || d[j] == b*c || d[j] == c*a || d[j] == a*b*c) ;
						else break;
					}
					if (j >= 7)
						r = 100*a + 10*b + c;
				}
			}
		}
		fprintf(out,"%d\n",r);
	}
	fclose(out);
	return 0;
}