#include <stdio.h>

FILE *in=fopen("B-small-attempt3.in", "r");
FILE *out=fopen("output.txt", "w");

int main()
{
	int t;
	fscanf(in, "%d", &t);
	for (int tt=1; tt<=t; tt++){
		int n;
		long long int m;
		fscanf(in, "%d %lld", &n, &m);
		fprintf(out, "Case #%d: ", tt);
		
		long long int a=1;
		for (int i=1; i<=n-2; i++) a*=2;
		if (a<m){
			fprintf(out, "IMPOSSIBLE\n");
			continue;
		}
		fprintf(out, "POSSIBLE\n");
		int A[52][52];
		for (int i=0; i<n; i++){
			for (int j=0; j<i; j++) A[i][j]=0;
			for (int j=i+1; j<n; j++) A[i][j]=1;
		}
		a-=m;
		for (int i=1; i<=n-2; i++){
			A[i][n-1]-=a%2;
			a/=2;
			if (a==0) break;
		}
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++) fprintf(out, "%d", A[i][j]);
			fprintf(out, "\n");
		}
	}
	return 0;
}
