#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NMAX 128

int main(void) {
	int i,j,k,
		T,N,S,P,t[NMAX];
	FILE *fin=fopen("B-small-attempt0.in","r"),*fout=fopen("out.txt","w");

	fscanf(fin,"%d\n",&T);
	//printf("T: %d\n",T);
	for(i=0;k=0,i<T;i++) {
		//printf("i: %d\n",i);
		fscanf(fin,"%d\n%d\n%d\n",&N,&S,&P);
		//printf("N: %d, S: %d, P: %d\n",N,S,P);
		for(j=0;j<N;j++) {
			fscanf(fin,"%d\n",&t[j]);
			switch(t[j]%3) {
				case 0:
					if(t[j]/3>=P) k++;
					else if(S>0 && t[j]/3>0 && t[j]/3<10 && t[j]/3+1>=P) S--,k++;
					break;
				case 1:
					if(t[j]/3+1>=P) k++;
					break;
				case 2:
					if(t[j]/3+1>=P) k++;
					else if(S>0 &&t[j]/3<9 && t[j]/3+2>=P) S--,k++;
					break;
			}
		}
		fprintf(fout,"Case #%d: %d\n",i+1,k);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
