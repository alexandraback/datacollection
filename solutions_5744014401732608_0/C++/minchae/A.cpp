#include<stdio.h>
#include<string.h>

FILE *in = fopen("input.txt", "r");
FILE *out = fopen("output.txt", "w");

int A() 
{
	int B, M, i,j;
	long long limit = 1;
	fscanf(in,"%d%d", &B, &M);

	for (i = 1; i <= B - 2; i++)
		limit *= 2;

	if (M > limit) {
		fprintf(out,"IMPOSSIBLE\n");
		return 0;
	}
	else{
		fprintf(out, "POSSIBLE\n");
		if (M == limit) {
			for (i = 0; i < B; i++) {
				for (j = 0; j < B; j++) {
					if (i >= j)fprintf(out, "0");
					else fprintf(out, "1");
				}
				fprintf(out, "\n");
			}
		}
		else {

			int stack[100],top=0,temp=M;

			for (i = 0; i < B-2;i++) {
				stack[top++]= temp%2;
				temp /= 2;
			}

			fprintf(out,"0");
			for (i = B-3; i >=0; i--) {
				fprintf(out, "%d", stack[i]);
			}
			fprintf(out, "0\n");

			for (i = 1; i < B; i++) {
				for (j = 0; j < B; j++) {
					if (i >= j)fprintf(out, "0");
					else fprintf(out, "1");
				}
				fprintf(out, "\n");
			}
		}
	}

	return 0;
}

int main()
{
	int T,i=1; fscanf(in,"%d",&T);

	while (T--) {
		fprintf(out,"Case #%d: ",i++);
		A();
	}

	return 0;
}