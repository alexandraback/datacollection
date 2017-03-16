#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE *fin,*fout;
	int score,i,t,n,s,p,temp,count;

	fin = fopen("b.in", "r");
	fout = fopen("b.out", "w");
	fscanf(fin,"%d", &t);

	for (count = 1;count <= t; count++) {
		fscanf(fin,"%d%d%d", &n, &s, &p);
		score = 0;
		for (i=0;i<n;i++) {
			fscanf(fin,"%d", &temp);
			if (temp>=3*p || (temp>=3*p-2 && p>0)) score++;
			else if (s>0 && (temp==3*p-3 || temp == 3*p-4) && p>1) {
				score++;
				s--;
			}
		}
		fprintf(fout,"Case #%d: %d\n", count, score);
	}
	fclose(fin);
	fclose(fout);

	return 0;
}