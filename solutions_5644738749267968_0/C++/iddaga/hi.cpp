#include <stdio.h>
#include <algorithm>
#define MN 1000
using namespace std;
int N;
double a[MN], b[MN];
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k, r;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("%d / %d\n",t,T);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d",&N);
		for (i = 0; i < N; i++)
			fscanf(in,"%lf",&a[i]);
		for (i = 0; i < N; i++)
			fscanf(in,"%lf",&b[i]);
		sort(a,a+N); sort(b,b+N);
		i = 0; j = N-1; r = 0;
		for (k = N-1; k >= 0; k--) {
			if (b[k] < a[j]) {
				j--; r++;
			}
			else i++;
		}
		fprintf(out,"%d ",r);
		i = 0; j = N-1; r = 0;
		for (k = N-1; k >= 0; k--) {
			if (a[k] > b[j]) {
				i++; r++;
			}
			else j--;
		}
		fprintf(out,"%d\n",r);
	}
	fclose(in);
	fclose(out);
	return 0;
}