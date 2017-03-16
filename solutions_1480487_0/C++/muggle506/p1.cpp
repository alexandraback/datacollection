#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main(){
	ifstream infile;
	char inname[50];
	cout<<"input input filename: ";
	cin>>inname;	
	infile.open(inname);
	FILE *outfile;
	outfile=fopen("p1Ans.txt","w");
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
		int N=-1;
		infile>>N;
		double *s=new double[N];
		bool *in=new bool[N];
		double *ans=new double[N];
		double x=0;
		for(int i=0;i<N;++i){
			infile>>s[i];
			x+=s[i];
			in[i]=true;
			ans[i]=0;
		}
		//calculate
		int test=0;
		double sum=x;
		int n=N;
		while(test<(N-1)){
			for(int i=0;i<N;++i){
				test=i;
				if (in[i]){
					if(((sum+x)/n-s[i])<0) {
						in[i]=false;
						n--;
						sum-=s[i];
						break;
					}
				}
			}
		}

		for(int i=0;i<N;++i){
			if(in[i]) ans[i]=((sum+x)/n-s[i])/x;
			ans[i]*=100;
		}	
		//output	
		fprintf(outfile,"Case #%d:",I);
		for(int i=0;i<N;++i){
		fprintf(outfile," %.6f",ans[i]);
		}
		fprintf(outfile,"\n");
		delete[]ans;
		delete[]s;
		++I;
	}
	fclose(outfile);
return 0;
}
