#include <stdio.h>
#include <memory.h>
#define MN 30
using namespace std;
long long c[MN][2][2][2]; bool _c[MN][2][2][2];
int A[MN], B[MN], K[MN];
long long C(int p, int ea, int eb, int ek)
{
	if (p < 0) return !ea && !eb && !ek;
	if (_c[p][ea][eb][ek]) return c[p][ea][eb][ek];
	_c[p][ea][eb][ek] = 1; c[p][ea][eb][ek] = 0;
	int na, nb, i, j;
	
	if (ea) na = A[p];
	else na = 1;
	if (eb) nb = B[p];
	else nb = 1;
	for (i = 0; i <= na; i++) {
		for (j = 0; j <= nb; j++) {
			if (ek && (i&j) > K[p]) continue;
			c[p][ea][eb][ek] += C(p-1,ea&(i==A[p]),eb&(j==B[p]),ek&((i&j)==K[p]));
		}
	}
	return c[p][ea][eb][ek];
}
int main()
{
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("output.txt","w");
	int t, T, i, j, k, a, b;
	
	fscanf(in,"%d",&T);
	for (t = 1; t <= T; t++) {
		printf("Case #%d:\n",t);
		fprintf(out,"Case #%d: ",t);
		fscanf(in,"%d%d%d",&a,&b,&k);
		for (i = 0; i < MN; i++) {
			A[i] = (a&(1<<i))>0;
			B[i] = (b&(1<<i))>0;
			K[i] = (k&(1<<i))>0;
		}
		memset(_c,0,sizeof(_c));
		fprintf(out,"%lld\n",C(MN-1,1,1,1));
	}
	fclose(in);
	fclose(out);
	return 0;
}