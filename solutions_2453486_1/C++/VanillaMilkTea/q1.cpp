#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <map>

#define _USE_MATH_DEFINES

using namespace std;

typedef unsigned long long ull;

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int N=0;
	int i=0,j=0,k=0;
	clock_t t0;
	t0=clock();
	char tmp=0;
	int states[4][4];
	int check=0,hasEmpty=0;
	/*
	fout=fopen("testLarge.in","wt");
	fprintf(fout,"1000\n");
	for(i=1;i<=1000;i++){
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				tmp=rand()%3;
				if(tmp==0) fputc('.',fout);
				else if(tmp==1) fputc('X',fout);
				else fputc('O',fout);
			}
			fputc('\n',fout);
		}
		fputc('\n',fout);
	}
	fclose(fout);
	return 0;
	*/
	fin =fopen("A-large.in","rt");
	fout=fopen("A-large.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	//printf("cases = %d\n",cases);
	for(i=1;i<=cases;i++){
		//printf("i = %d\n",i);
		hasEmpty=0;
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				tmp=fgetc(fin);
				//printf("tmp = %c\n",tmp);
				if(tmp=='.'){
					states[j][k]=0;
					hasEmpty=1;
				}
				else if(tmp=='X')
					states[j][k]=1;
				else if(tmp=='O')
					states[j][k]=-1;
				else
					states[j][k]=1000;
			}
			tmp=fgetc(fin);
		}
		tmp=fgetc(fin);
		/*
		for(j=0;j<4;j++){
			for(k=0;k<4;k++)
				printf("%d",states[j][k]);
			printf("\n");
		}
		printf("\n");
		*/

		fprintf(fout,"Case #%d: ",i);
		for(j=0;j<4;j++){
			check=states[j][0]+states[j][1]+states[j][2]+states[j][3];
			if(check==4){
				fprintf(fout,"X won\n");
				break;
			}
			else if(check==-4){
				fprintf(fout,"O won\n");
				break;
			}
			else if(check==1003){
				fprintf(fout,"X won\n");
				break;
			}
			else if(check==997){
				fprintf(fout,"O won\n");
				break;
			}
			else 
				check=10000;
		}
		
		if(check==10000){
		for(j=0;j<4;j++){
			check=states[0][j]+states[1][j]+states[2][j]+states[3][j];
			if(check==4){
				fprintf(fout,"X won\n");
				break;
			}
			else if(check==-4){
				fprintf(fout,"O won\n");
				break;
			}
			else if(check==1003){
				fprintf(fout,"X won\n");
				break;
			}
			else if(check==997){
				fprintf(fout,"O won\n");
				break;
			}
			else 
				check=10000;
		}
		}
		//
		if(check==10000){
		check=states[0][0]+states[1][1]+states[2][2]+states[3][3];
			if(check==4)
				fprintf(fout,"X won\n");
			else if(check==-4)
				fprintf(fout,"O won\n");
			else if(check==1003)
				fprintf(fout,"X won\n");
			else if(check==997)
				fprintf(fout,"O won\n");
			else 
				check=10000;
		}
		if(check==10000){
		check=states[0][3]+states[1][2]+states[2][1]+states[3][0];
			if(check==4)
				fprintf(fout,"X won\n");
			else if(check==-4)
				fprintf(fout,"O won\n");
			else if(check==1003)
				fprintf(fout,"X won\n");
			else if(check==997)
				fprintf(fout,"O won\n");
			else 
				check=10000;
		}
		if(check==10000){
			if(hasEmpty)
				fprintf(fout,"Game has not completed\n");
			else
				fprintf(fout,"Draw\n");
		}
		//
	}
	
	
	fclose(fin);
	fclose(fout);

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}