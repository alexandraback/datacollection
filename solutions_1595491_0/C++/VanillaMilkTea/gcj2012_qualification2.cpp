#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char **argv){
	FILE *fin,*fout;
	int i=0,j=0,cases=0;
	int num=0,s=0,p=0;
	int safeScore=0,maybeSurprise=0;
	int scores[128];
	int maybeIndex=0;
	int passes=0;

	fin =fopen("B-small-attempt2.in","rt");
	fout=fopen("B-small-attempt2.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	
	for(i=0;i<cases;i++){
		fscanf(fin,"%d %d %d",&num,&s,&p);
		for(j=0;j<num;j++){
			fscanf(fin,"%d",&(scores[j]));
		}
		passes=0;
		if(p==0){
			fprintf(fout,"Case #%d: %d\n",i+1,num);
			continue;
		}
		else {
			if(p==1){
				for(j=0;j<num;j++){
					if(scores[j])passes++;
				}
				fprintf(fout,"Case #%d: %d\n",i+1,passes);
				continue;
			}
			else{
				safeScore=3*p-2;
				maybeSurprise=3*p-4;
			}
		}

		sort(scores,scores+num);

		if(scores[0]>=safeScore){
			fprintf(fout,"Case #%d: %d\n",i+1,num);
			continue;
		}
		if(scores[num-1]<maybeSurprise){
			fprintf(fout,"Case #%d: 0\n",i+1);
			continue;
		}

		for(j=0;scores[j]<maybeSurprise;j++){}
		maybeIndex=j;
		while(scores[j]<safeScore){
			j++;
			if(j==num)
				break;
		}
		if(j<num) passes=num-j;
		if(j-maybeIndex<s)
			fprintf(fout,"Case #%d: %d\n",i+1,passes+(j-maybeIndex));
		else
			fprintf(fout,"Case #%d: %d\n",i+1,passes+s);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}