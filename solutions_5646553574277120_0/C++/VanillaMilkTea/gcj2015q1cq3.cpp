#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;


int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int C,D,V,m,N;
	int a[111],t[51];
	int *p;

	FILE *fin,*fout;

	fin=fopen("C-small-attempt1.in","rt");
	fout=fopen("C-small-attempt1.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d %d",&C,&D,&V);

		for(i=0;i<D;i++){
			fscanf(fin,"%d",&(a[i]));
		}
		for(i=0;i<51;i++) t[i]=0;

		j=1;
		for(i=0;i<D;i++){
			j*=2;
		}

		//for(i=0;i<D;i++) printf("a[%02d] = %d\n",i,a[i]);
		
		for(i=0;i<j;i++){
			m=0;
			for(k=0;k<D;k++){
				if((i>>k)&1) m+=a[k];
			}
			if(m<=V)
				t[m]=1;
		}

		//for(i=1;i<=V;i++)printf("t[%02d] = %d\n",i,t[i]);

		N=0;
		for(i=1;i<=V;i++){
			if(t[i]) continue;
			//printf("add: %d\n",i);

			N++;
			for(j=V;j>0;j--){
				if((t[j]==0)&&(j>i)){
					if(t[j-i]) {
						t[j]=1;
						//printf("new: %d\n",j);
					}
				}
			}
			t[i]=1;
		}

		fprintf(fout,"Case #%d: %d\n",caseno,N);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}