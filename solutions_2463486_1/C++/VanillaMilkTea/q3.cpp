#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <map>

#define _USE_MATH_DEFINES
#define NUM_ARR 39

using namespace std;

typedef unsigned long long ull;

ull arr[NUM_ARR]={
	1,4,9,121,484,
	10201,12321,14641,40804,44944,
	1002001,1234321,4008004,100020001,102030201,
	104060401,121242121,123454321,125686521,400080004,
	404090404,10000200001,10221412201,12102420121,12345654321,
	40000800004,1000002000001,1002003002001,1004006004001,1020304030201,
	1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,
	1232346432321,1234567654321,4000008000004,4004009004004
};

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
	fprintf(fout,"10000\n");
	for(i=1;i<=10000;i++){
		fprintf(fout,"1 100000000000000\n");
	}
	fclose(fout);
	return 0;
	*/

	fin =fopen("C-large-1.in","rt");
	fout=fopen("C-large-1.out","wt");
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

		num=0;
		for(j=0;j<NUM_ARR;j++){
			if((A<=arr[j])&&(arr[j]<=B))
				num++;
		}
		fprintf(fout,"%llu\n",num);
		/*
		j=0;
		while(arr[j]<A) {
			j++;
			if(j==NUM_ARR) break;
		}
		if(j==NUM_ARR) {
			fprintf(fout,"0\n");
			continue;
		}
		num=0;
		while(arr[j]<B){
			num++;
			j++;
			if(j==NUM_ARR) break;
		}
		*/
		/*
		start=(ull)(ceil(sqrt((double)A)));
		if((start-1)*(start-1)>A) start--;
		end=(ull)(floor(sqrt((double)B)));
		if((end+1)*(end+1)<B) end++;
		//printf("%llu %llu\n",start,end);
		//printf("%llu %llu\n",start*start,end*end);
		//printf("%llu %llu\n",(start-1)*(start-1),(end+1)*(end+1));

		num=0;
		start=1;end=10000000;
		for(t=start;t<=end;t++){
			if(t%10>3) continue;
			if(t%10==0) continue;

			len=intToString(t,string);
			if(isPalindrome(string,len)){
				v=t*t;
				len=intToString(v,string);
				if(isPalindrome(string,len)){
					num++;
					fprintf(fchk,"%llu\n",v);
				}
			}
		}
		*/
		//fprintf(fout,"%llu\n",num);
	}
	
	
	fclose(fin);
	fclose(fout);
	//fclose(fchk);

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}