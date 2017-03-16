#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int flippancake(string pc){
	int n=pc.length();

	int up,down;
	if(pc[0]=='+'){
		up=0;
		down=1;
	}else{
		up=1;
		down=0;
	}

	for(int i=1;i<n;i++){
		if(pc[i]=='+'){
			down+=2;
		}else{
			up+=2;
		}
		if(down<up){
			up=down+1;
		}else{
			down=up+1;
		}
	}

	return up;
}

void main(){

	fstream infile,outfile;
	int testnum;
	string pc;
	infile.open("B-small-attempt0.in",ios::in);
	outfile.open("output.dat",ios::out);	
	infile>>testnum;
	getline(infile,pc);
	for(int i=1;i<=testnum;i++){
		getline(infile,pc);
		outfile<<"Case #"<<i<<": "<<flippancake(pc)<<'\n';
	}
}