#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static bool seen[10];


int solve(int nn){
	int n=(nn>0)?nn:(-nn), val, digit, remain;
	bool someUnseen=true;
	for(int i=0; i<10; i++)
		seen[i]=false;
	val=0;
	while(someUnseen){
		val+=n;
		remain=val;
		digit=remain%10;
		do{
			seen[digit]=true;
			remain=remain/10;
			digit=remain%10;
		}while(remain>0);
		//update someUnseen
		someUnseen=false;
		for(int i=0; i<10; i++)
			if(!seen[i])
				someUnseen=true;
	}
	return val;
}


int main(){
	cout<<"launching function main"<<endl;
	ifstream file("A-small-attempt0.in");
	ofstream outputfile("myoutput.txt");
	int T, N, number;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>N;
		//solve
		if(N !=0)
			number=solve(N);
		//write output
		if(N!=0)
			outputfile<<"Case #"<<(t+1)<<": "<<number<<endl;
		else
			outputfile<<"Case #"<<(t+1)<<": INSOMNIA"<<endl;
			
	}
	file.close();
	outputfile.close();
}

