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

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int levels=0;
	int i=0,j=0,k=0;
	int diff[1000][2];
	int done[1000][2];
	int stars=0;
	int tries=0,prevTotal=0,totalDone=0;
	int max=0,pos=0,type=0,next=0;
	int cont=0;
	clock_t t0;
	t0=clock();

	fin =fopen("B-small-attempt5.in","rt");
	fout=fopen("B-small-attempt5.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	printf("cases = %d\n",cases);
	for(i=1;i<=cases;i++){
		printf("case %d\n",i);
		fscanf(fin,"%d",&levels);
		totalDone=0;stars=0;tries=0;
		
		for(j=0;j<levels;j++){
			fscanf(fin,"%d %d",&diff[j][0],&diff[j][1]);
			done[j][0]=0;done[j][1]=0;
		}

		if(levels==1){
			if(diff[0][1]==0){
				fprintf(fout,"Case #%d: 1\n",i);
			}
			else if((diff[0][0]==0)&&(diff[0][1]==1)){
				fprintf(fout,"Case #%d: 2\n",i);
			}
			else
				fprintf(fout,"Case #%d: Too Bad\n",i);
		}
		else{
			do{
				//prevTotal=totalDone;
				cont=0;
				max=0;pos=0;next=0;
				for(j=0;j<levels;j++){
					if(done[j][1])continue;

					if(stars>=diff[j][1]){
						if(done[j][0]){
							max=1;pos=j;type=2;
							//printf("max = %d, pos = %d, type = %d\n",max,pos,type);
							break;
						}
						else {
							max=2;pos=j;type=2;
							//printf("max = %d, pos = %d, type = %d\n",max,pos,type);
							break;
						}
					}

					if(done[j][0])continue;

					if(stars>=diff[j][0]){
						if(diff[j][1]>next){
							max=1;pos=j;type=1;
							next=diff[j][1];
						}
						//printf("max = %d, pos = %d, type = %d\n",max,pos,type);
					}
				}
				//printf("final max = %d, pos = %d, type = %d\n",max,pos,type);getchar();
				if(max!=0){
					stars+=max;
					if(type==2){
						done[pos][1]=1;
						totalDone++;
					}
					else{
						done[pos][0]=1;
					}
						
					cont=1;
				}
				tries++;
				//printf("stars = %d\n",stars);getchar();
			}while(cont && (totalDone!=levels));
			//printf("totalDone = %d\n",totalDone);getchar();
		//(prevTotal!=totalDone)
			if(totalDone==levels)
				fprintf(fout,"Case #%d: %d\n",i,tries);
			else
				fprintf(fout,"Case #%d: Too Bad\n",i);
	}
	}
	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}