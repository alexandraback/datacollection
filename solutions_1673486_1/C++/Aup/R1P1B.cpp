
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

std::ifstream file;
std::ofstream ofile;

int a,b;
double prob[100000];


double problem(){
	file >> a >> b;

	prob[0] = 1;
	for( int i=1;i<=a;i++ ){
		file >> prob[i];
		prob[i] *= prob[i-1];
	}
	double minExp = 10000000; // now

	for( int i=0;i<=a;i++){
		int idx = a-i;
		double exp = prob[idx] * (b-a+1+i*2) + (1-prob[idx]) * (b - a + 1 + b + 1 + i*2);
		if( exp < minExp )
			minExp = exp;
	}
	if( (b + 2) < minExp )
		minExp = b+2;

	return minExp;
}


int main(){
	std::string filename = "A-large.in";
	std::string fileoutput = filename + ".out.txt";
	file.open(filename.c_str());
	ofile.open(fileoutput.c_str());
	if( file.fail() || ofile.fail() )
		return 0;

	int n = 0;
	file >> n;

	for( int i=0;i<n;i++ ){
		ofile << "Case #" << i+1 << ": " ;//<< problem() << std::endl;
		char tmp[100];
		sprintf( tmp , "%.6f" , problem() );
		ofile << tmp << std::endl;
		std::cout << tmp << std::endl;
	}

	return 0;
}

