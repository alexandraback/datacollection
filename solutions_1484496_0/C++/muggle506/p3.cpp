#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
struct Cell{
	int sum;
	int v;
};
int main(){
	ifstream infile;
	char inname[50];
	cout<<"input input filename: ";
	cin>>inname;	
	infile.open(inname);
	FILE *outfile;
	outfile=fopen("p3Ans.txt","w");
	int T;
	infile>>T;
	string line;
	getline(infile,line);
	int I=1;
	cout<<T<<endl;
	cout<<"end of input T"<<endl;
	while(I<=T){
		cout<<I;//test
		cout<<" start to process case"<<endl;//test
		//input
		int n=-1;
		infile>>n;
		int *in=new int[n];
		for(int i=0;i<n;++i){
			infile>>in[i];
		}
		//calculate
		Cell* cell=new Cell[1048576];	
		int test;
		int pt;
		int p1=-1;
		int p2=-1;
		for(int N=1;N<1048576;++N){
			test=N;
			pt=0;
			cell[N].sum=0;
			cell[N].v=N;
			while(test!=0){
				if(test%2==1){
					cell[N].sum+=in[pt];
				}	
				test=test/2;
				pt++;
			}
			//check inside vector
			for(int j=1;j<N;++j){
				if(cell[N].sum==cell[j].sum){
					p1=N;
					p2=j;
					break;
				}	
			}
			if(p1>0) break;	
		}	
		//output	
		fprintf(outfile,"Case #%d:\n",I);
		if(p1>0){
			test=p1;
			pt=0;
			while(test!=0){
				if(test%2==1) 	
					fprintf(outfile,"%d ",in[pt]);
				test/=2;
				pt++;
			}
			fprintf(outfile,"\n");
			test=p2;
			pt=0;
			while(test!=0){
				if(test%2==1) fprintf(outfile,"%d ",in[pt]);
				test/=2;
				pt++;
			}
			fprintf(outfile,"\n");
		} else fprintf(outfile,"%s","Impossible");
		++I;
	}
	fclose(outfile);
return 0;}
