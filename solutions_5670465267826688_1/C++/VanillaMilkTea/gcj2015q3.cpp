#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int L;
	long long X,x2;
	int s[100001],sym=0,pm=1,sym2,pm2,c;
	int max,found;
	int mul2[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
	int sgn[4][4]={{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

	FILE *fin,*fout;
	char x,y;

	fin=fopen("C-large.in","rt");
	fout=fopen("C-large.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %lld",&L,&X);
		fgetc(fin);
		
		sym=0;pm=1;
		for(i=0;i<L;i++){
			fscanf(fin,"%c",&c);

			switch(c){
			case 'i':
				s[i]=1;
				break;
			case 'j':
				s[i]=2;
				break;
			default :
				s[i]=3;
			}
			pm*=sgn[sym][s[i]];
			sym=mul2[sym][s[i]];
		}

		x2=X%4;
		pm2=pm;sym2=sym;
		for(i=2;i<=((int)x2);i++){
			pm2*=pm*sgn[sym2][sym];
			sym2=mul2[sym2][sym];
		}

		if((pm2!=-1)||(sym2!=0)){
			fprintf(fout,"Case #%d: NO\n",caseno);
			continue;
		}


		if(X<10ll){
			for(i=1;i<((int)X);i++){
				for(j=0;j<L;j++){
					s[i*L+j]=s[j];
				}
			}
			max=L*((int)X);
		}
		else {
			for(i=1;i<10;i++){
				for(j=0;j<L;j++){
					s[i*L+j]=s[j];
				}
			}
			max=L*10;
		}


		pm=1;sym=0;found=0;
		for(i=0;i<max;i++){
			pm*=sgn[sym][s[i]];
			sym=mul2[sym][s[i]];
			if((pm==1)&&(sym==1)){
				found++;
				j=i+1;
				break;
			}
		}
		pm=1;sym=0;
		for(j;j<max;j++){
			pm*=sgn[sym][s[j]];
			sym=mul2[sym][s[j]];
			if((pm==1)&&(sym==2)){
				found++;
				break;
			}
		}

		if(found==2){
			fprintf(fout,"Case #%d: YES\n",caseno);
		}
		else{
			fprintf(fout,"Case #%d: No\n",caseno);
		}
	}
	fclose(fout);
	fclose(fin);

	return 0;
}