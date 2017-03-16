#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int N,M;
int m[100][100];
int maxium[100][100];
int T;

int main(){
	FILE * input=fopen("B.in","r");
	ofstream output;
	output.open("B.output");
	fscanf(input,"%i",&T);
	int ca=0;
	int ma;
	bool done=false;
	while(ca++<T){
		fscanf(input,"%i",&N);
		fscanf(input,"%i",&M);
		output<<"Case #"<<ca<<": ";
		memset(m,0,sizeof(m));
		memset(maxium,0,sizeof(maxium));
		//input
		for(int i=0;i<N;i++){
		 for(int j=0;j<M;j++){
			fscanf(input,"%i",&m[i][j]);
		 }
		}
	 	//check:For every point, either colum or row must be max
		//mark row maxium
		for(int i=0;i<N;i++){
			ma=m[i][0];
			for(int j=1;j<M;j++){
				if(ma<m[i][j])ma=m[i][j];
			}	
			for(int j=0;j<M;j++){
				if(ma==m[i][j])++maxium[i][j];
			}
		}
		done=false;
		for(int j=0;j<M;j++){
			ma=m[0][j];
			for(int i=1;i<N;i++){
				if(ma<m[i][j])ma=m[i][j];
			}
			for(int i=0;i<N;++i){
				if(ma!=m[i][j]&&maxium[i][j]==0){
					output<<"NO"<<endl;
					done=true;
					break;
				}
			}
			if(done) break;
		}
		if(!done) output<<"YES"<<endl; 
   	} 
	fclose(input);
	output.close();

}
