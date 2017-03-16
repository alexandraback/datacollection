#include <stdio.h>
#include <string.h>

#define MAX 2000001

int main(int argc, char const *argv[])
{
	FILE *fin,*fout;
	int po,temp,len,j,t,a,b,i,count,sum,outcome;
	char st[16], v[MAX];

	fin = fopen("c.in", "r");
	fout = fopen("c.out", "w");
	fscanf(fin,"%d", &t);

	for (count = 1;count <= t;count++) {
		fscanf(fin,"%d%d", &a, &b);
		for (i=a;i<=b;i++) v[i] = 0;
		outcome = 0;
		for (i=a;i<=b;i++) 
			if (!v[i]) {
				sum = 0; temp = 0;
				sprintf(st, "%d", i);
				len = strlen(st); po = 1;
				for (j=1;j<len;j++) po *= 10;
				for (j=len;j<len+len;j++) st[j] = st[j-len];
				for (j=0;j<len;j++) temp = temp*10 + st[j]-'0';
				do {
					if (temp>=a && temp<=b && !v[temp]) {
						sum++;
						v[temp] = 1;
					}
					temp %= po;
					temp = temp*10 +st[j++]-'0';
				}while (j<len+len);
			outcome += sum*(sum-1)/2;
		}
		fprintf(fout,"Case #%d: %d\n", count, outcome);
	}
	fclose(fin);
	fclose(fout);

	return 0;
}