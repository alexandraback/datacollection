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

int intToString(ull val,char string[128]){
	int len=0;

	while(val!=0){
		string[len++]=(val%10);
		val/=10;
	}
	return len;
}

int isPalindrome(char string[128],int len){
	int i=0,j=len-1;
	while(i<j){
		if(string[i]!=string[j]) return 0;
		i++;
		j--;
	}
	return 1;
}

int main(int argc,char **argv){
	FILE *fin,*fout,*fchk;
	int cases=0;
	int N=0,M=0;
	int i=0,j=0,k=0;
	clock_t t0;
	t0=clock();
	char tmp=0;
	char buf[1024],string[128];
	int len=0;
	ull A=0,B=0;
	ull start=0,end=0,t=0,v=0;
	ull num=0;

	/*
	fout=fopen("testLarge.in","wt");
	fprintf(fout,"100\n");
	for(i=1;i<=100;i++){
		fprintf(fout,"100 100\n");
		for(j=0;j<100;j++){
			for(k=0;k<100;k++){
				fprintf(fout,"%d ",(rand()%101));
			}
			fprintf(fout,"\n");
		}
	}
	fclose(fout);
	return 0;
	*/

	fin =fopen("C-small-attempt0.in","rt");
	fout=fopen("C-small-attempt0.out","wt");
	//fchk=fopen("check.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	for(i=1;i<=cases;i++){
		fprintf(fout,"Case #%d: ",i);

		//fscanf(fin,"%s",buf);
		//printf("%s ",buf);
		//fscanf(fin,"%s",buf);
		//printf("%s\n",buf);
		fscanf(fin,"%llu %llu",&A,&B);
		//printf("%llu %llu\n",A,B);

		start=(ull)(ceil(sqrt((double)A)));
		if((start-1)*(start-1)>A) start--;
		end=(ull)(floor(sqrt((double)B)));
		if((end+1)*(end+1)<B) end++;
		//printf("%llu %llu\n",start,end);
		//printf("%llu %llu\n",start*start,end*end);
		//printf("%llu %llu\n",(start-1)*(start-1),(end+1)*(end+1));

		num=0;
		for(t=start;t<=end;t++){
			if(t%10>3) continue;
			if(t%10==0) continue;

			len=intToString(t,string);
			if(isPalindrome(string,len)){
				v=t*t;
				len=intToString(v,string);
				if(isPalindrome(string,len)){
					num++;
					//fprintf(fchk,"%llu %llu\n",t,v);
				}
			}
		}
		fprintf(fout,"%llu\n",num);
	}
	
	
	fclose(fin);
	fclose(fout);
	//fclose(fchk);

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}