// Qualification Round
// Problem C-small

#include <stdio.h>

int pals[5] = {1, 4, 9, 121, 484};
int main(){
	int T,t,A,B, i,j, r;
	FILE *fi = fopen("../Google/cs.in","r"),
		*fo = fopen("../Google/cs.out","w");
	fscanf(fi,"%d\n",&T);
	for(t = 1; t <= T; t++){
		fprintf(fo,"Case #%d: ",t);
		fscanf(fi,"%d %d\n",&A,&B);
		r = 0;
		for(i = A; i <= B; i++)
			for(j = 0; j < 5; j++)
				if(i == pals[j])
					r++;
		fprintf(fo,"%d\n",r);
	}
	fclose(fi); fclose(fo);
	return 0;
}
