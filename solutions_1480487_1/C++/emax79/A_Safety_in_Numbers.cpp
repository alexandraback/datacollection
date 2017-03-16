#include <stdio.h>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;


int GO(  FILE* FIn, FILE* FOut , unsigned uCase);

int Test(int argc, char* argv[]);



int main(int argc, char* argv[])
{

	Test(argc,argv);
	
	return 0;
}



char sInFile[FILENAME_MAX] = 
	//"A-sample.in";
	//"A-small-attempt0.in";
	"A-large.in";

char sOutFile[FILENAME_MAX] = 
	//"A-sample.out";
	//"A-small.out";
	"A-large.out";

int Test(int argc, char* argv[])
{
	FILE* FIn = fopen(sInFile, "r");
	FILE* FOut = fopen(sOutFile, "w");
	
	if( !FIn ){
		cerr<<"Cannot open input"<<endl;
		return -1;
	}
	if( !FOut ){
		cerr<<"Cannot open output"<<endl;
		fclose( FIn);
		return -1;
	}
	unsigned N;
	fscanf(FIn,"%d\n",&N);
	int iErr = 0;
	for(unsigned uCase=0 ; uCase < N ; ++uCase){
		cout <<"case:"<<uCase+1<<endl;
		int iInErr = GO( FIn, FOut, uCase+1 );
		if( iInErr != 0 ){
			iErr = iInErr;
			cerr << "Something wrong for case "<<uCase+1;
		}
	}

	fclose(FOut);
	fclose(FIn);

	return iErr;
}

int s[201];
int sorted[201];

int __cdecl intcmp(const void*p1, const void*p2){
	return ((int)(*(int*)p1))-(int)(*(int*)p2);
}


int GO(  FILE* FIn, FILE* FOut , unsigned uCase)
{
	int N;
	fscanf(FIn,"%d",&N);

	int X=0;
	for(int i=0;i<N;++i){

		fscanf(FIn,"%d",&(s[i]));
		X+= s[i];
	}


	memcpy( sorted, s, N*sizeof(int));
	qsort( sorted,N,sizeof(int),intcmp);
	

	
	fprintf(FOut, "Case #%d:",uCase);
	for( int i=0;i<N;++i){
		double ymin = 0.0;
		bool bme=false;
		int n = 1;
		double yUsed=0;
		bool bFound = false;
		for(int x=0;x<N-1;++x){
			int d = sorted[x+1]-sorted[x];
			double ydeltasingle = (double)d/X;
			double ydelta = n*ydeltasingle;
			if( sorted[x] < s[i] ){
				yUsed += ydelta;
				if(yUsed > 1.0){
					bFound = true;
					fprintf(FOut, " %f",ymin*100);
					break;
				}
			}
			else{
				if( yUsed+ydelta >=1.0){
					ymin += (1.0-yUsed)/n;
					fprintf(FOut, " %f",ymin*100);
					bFound = true;
					break;
				}
				else{
					ymin+= ydeltasingle;
					yUsed += ydelta;
				}
			}
			n++;
		}
		if(!bFound){
			ymin += (1.0-yUsed)/N;
			fprintf(FOut, " %f",ymin*100);
		}

	}
		fprintf(FOut, "\n");


	//fprintf(FOut, "Case #%d: %s",uCase,sInLine);
	return 0;
}


