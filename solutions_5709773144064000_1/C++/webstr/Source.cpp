#include <fstream>
#include <iostream>
using namespace std;

int main(){
	ifstream fin;
	ofstream fout;
	int T;

	fin.open("input.txt");
	fout.open("output.txt");
	fin >> T;
	for (int k = 1; k <= T; k++){
		double C, F, X;
		fin >> C >> F >> X;
		double res = 0;
		int n = 0;
		while ((X / (2 + n * F)) >= (X / (2 + (n + 1) * F) + C / (2 + n * F))){
			res += C / (2 + n * F);
			n++;
		}

		res += X / (2 + n * F);
		fout.setf(ios::fixed);
		fout.precision(7);
		fout << "Case #" << k << ": " << res << endl;
	}

	fin.close();
	fout.close();
}