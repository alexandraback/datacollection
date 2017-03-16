#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]){
	string input="input.in";
	string output="output.out";	
	std::ifstream In(input.c_str()); //ifstream file	
	ofstream Out(output.c_str()); //output file
	int t;
	In>>t;
	for(int i=0;i<t;i++){
		int r,c,w;
		In>>r>>c>>w;
		int a=c/w;
		int min = a*r;
		if(c%w==0) min=min+w-1;
		else min=min+w;
		Out<<"Case #"<<i+1<<": "<<min<<"\n";
		
		
	}
	


	return 0;
}




