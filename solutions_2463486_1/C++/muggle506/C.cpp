#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
using namespace std;
int T;
int ca=0;
long long A,B;
int q,h;

int main(){
	vector<long long> myvector;
	FILE * data=fopen("data.in","r");
	long long ll;
	FILE * input=fopen("C.in","r");
	ofstream output;
	output.open("C.output");

	while(fscanf(data,"%lld",&ll)!=EOF){
	 myvector.push_back(ll);
	}
	fclose(data);
	fscanf(input,"%i",&T);
	while(ca++<T){
		fscanf(input,"%lld",&A);
		fscanf(input,"%lld",&B);
		output<<"Case #"<<ca<<": ";
		int i=0;	
		q=0;h=0;
		for(;i<myvector.size();i++){
			if(A<=myvector[i]) break;
		}			
		q=i;h=i;
		for(;i<myvector.size();i++){
			if(B<myvector[i]) break;
		}
		h=i;
		output<<h-q<<endl;
   	} 
	fclose(input);
	output.close();
}
