#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>
using namespace std;

long run(long r, long p){
	double ans;
	if(r % 2 == 0){
		double inner = r/2;
		double a = 2;
		double b = 3;
		double c = -2*inner*inner + inner + 1 - p;

		ans = (-b + sqrt(b*b - 4*a*c))/(2*a) - r/2 + 1;
	} else {
		double inner = r/2+1;

		double a = 2;
		double b = 1;
		double c = -2*inner*inner + 3*inner - 1 - p;

		ans = (-b + sqrt(b*b - 4*a*c))/(2*a) - r/2;
	}
	return long(floor(ans));
}

int main(){
	string input = "A-small-attempt1.in";
	string output = "A-small.out";
	ifstream fin;
	ofstream fout;
	fin.open(input.c_str());
	fout.open(output.c_str());
	int n;
	fin >> n;
	for(int i = 0; i < n; i++){
		long r, p;
		fin >> r >> p;
		fout << "Case #" << (i+1) << ": " << run(r, p) << endl;
	}

	fin.close();
	fout.close();

	return 0;
}
