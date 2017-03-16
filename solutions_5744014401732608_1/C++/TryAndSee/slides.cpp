#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static int isslide[50][50];

void solve(int B, long long int M){
	long long int m=M-1;
	isslide[0][B-1]=1;
	for(int pos=0; pos<(B-2); pos++){
		if(m % 2 ==1){
			isslide[0][B-pos-2]=1;
		}else{
			isslide[0][B-pos-2]=0;
		}
		m/=2;
	}
}

int main(){
	cout<<"launching function main"<<endl;
	//initialize isslide
	for(int i=0; i<49; i++){
		for(int j=0; j<=i; j++)
			isslide[i][j]=0;
		for(int j=(i+1); j<50; j++)
			isslide[i][j]=1;
	}
//	ifstream file("B-small-attempt0.in");
	ifstream file("B-large.in");
	ofstream outputfile("myoutput.txt");
	int T, B;
	long long int M, int1;
	bool possible;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>B>>M;
		//solve
		int1=1;
		for(int i=2; i<B; i++)
			int1*=2;
		possible=(int1>=M);//possible iff M<=2^(B-2)
		if(possible)
			solve(B,M);
		//write output
		outputfile<<"Case #"<<(t+1)<<": ";
		if(!possible)
			outputfile<<"IM";
		outputfile<<"POSSIBLE"<<endl;
		if(possible){
			for(int i=0; i<B; i++){
				for(int j=0; j<B; j++)
					outputfile<<isslide[i][j];
				outputfile<<endl;
			}
		}
		
	}
	file.close();
	outputfile.close();
}

