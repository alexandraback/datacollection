#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

int sol[4][4][4]={};

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int X,R,C,pass;

	FILE *fin,*fout;

	fin=fopen("D-large.in","rt");
	fout=fopen("D-large.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d %d",&X,&R,&C);

		pass=1;

		//R <= C
		if(R>C){
			i=R; R=C; C=i;
		}

		//Not possible
		if((R*C)%X!=0){
			fprintf(fout,"Case #%d: RICHARD\n",caseno);
			continue;
		}


		//Cannot fit row-wise
		if(X>=(R+R+1)){
			fprintf(fout,"Case #%d: RICHARD\n",caseno);
			continue;
		}

		//Can fit row-wise, but not column-wise
		if(X>=(C+1)){
			fprintf(fout,"Case #%d: RICHARD\n",caseno);
			continue;
		}

		if(X>=4){
			switch(X){
			case 4:
				if(R==2) pass=0;
				break;
			case 5:
				if((R==3)&&(C==5)) pass=0;
				break;
			case 6:
				if(R==3) pass=0;
				break;
			case 7:
				if((R==4)&&(C==7)) pass=0;
				break;
			default :
				pass=0;
			}
		}
			

		if(pass){
			fprintf(fout,"Case #%d: GABRIEL\n",caseno);
		}
		else {
			fprintf(fout,"Case #%d: RICHARD\n",caseno);
		}
	}
	fclose(fout);
	fclose(fin);

	return 0;
}