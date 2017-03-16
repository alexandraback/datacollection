#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

const int maxHt=1001;

int solve(int ht,int max, int cnt[maxHt]){
	int i,j;
	int parts,time;

	if(ht>=max) return max;

	time=0;

	for(i=ht+1;i<=max;i++){
		if(cnt[i]==0) continue;

		if(i%ht==0)
			parts=i/ht-1;
		else
			parts=i/ht;

		time+= cnt[i]*parts;
	}
	return time+ht;
};

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int D,best,time,max,p;
	int P[1101];
	int cnt[maxHt];
//	int s[10]={0,0,1,1,1,2,4,5,5,5};
//	int r[10]={0,1,1,2,2,2,2,2,2,3};
	FILE *fin,*fout;

	fin=fopen("B-large.in","rt");
	fout=fopen("B-large1.out","wt");
	//fin=fopen("test.txt","rt");
	//fout=fopen("result.out","wt");
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d",&D);
		
		max=0;
		for(i=1;i<=maxHt;i++) cnt[i]=0;

		for(i=1;i<=D;i++){
			fscanf(fin,"%d",&p);
			cnt[p]++;
			if(p>max) max=p;
		}

		if(max<= 3){
			fprintf(fout,"Case #%d: %d\n",caseno,max);
			continue;
		}

		best=max;
		//printf("D = %d\n",D);
		//printf("max = %d\n",max);
		//for(i=1;i<=max;i++){
//			printf("cnt[%d] = %d\n",i,cnt[i]);
		//}
		//printf("\n");

		for(i=2;i<max;i++){
			time=solve(i,max,cnt);
			//printf("time %d : %d\n",i,time);
			if(time < best)
				best=time;
		}
		
//		sort(P, P + D);

		 //for(i=0;i<n;i++) printf("%d ",D[i]);
		 //printf("\n");

		
		
		fprintf(fout,"Case #%d: %d\n",caseno,best);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}