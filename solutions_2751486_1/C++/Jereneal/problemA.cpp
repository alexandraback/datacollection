//
//  main.cpp
//  codeJam_QualificationRound
//
//  Created by Jereneal Kim on 13. 4. 13..
//  Copyright (c) 2013년 Jereneal Kim. All rights reserved.
//

#include <iostream>
using namespace std;

char arr[1000005]={0};
int main(int argc, const char **argv)
{
	FILE *fp,*inp;
	__int64_t n,T,i,j,nOfname;
	__int64_t countCon,countAll;
	__int64_t result;

	fp=fopen(argv[1],"w");
	inp=fopen(argv[2],"r");
	
	fscanf(inp,"%lld",&T);
	
	for(i=1;i<=T;i++){
		fscanf(inp,"%s",&arr[1]);
		fscanf(inp,"%lld",&n);
		for(nOfname=1;arr[nOfname]!='\0';nOfname++){}
		nOfname--;
		result=countCon=countAll=0;
		for(j=1;j<=nOfname;j++){
			if(arr[j]=='a'||arr[j]=='e'||arr[j]=='i'||arr[j]=='o'||arr[j]=='u'){
				countAll++;
				countCon=0;
			}else{
				countAll++;
				countCon++;
				if(countCon==n){
					result+=(countAll-n+1)*(nOfname-j+1);
					countCon--;
					countAll=countCon;
				}
			}
		}
		fprintf(fp,"Case #%lld: %lld\n",i,result);
		printf("Case #%lld: %lld\n",i,result);
	}
	
	
	return 0;
}

