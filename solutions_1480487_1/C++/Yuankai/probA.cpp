#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int T;
int J[300];
int n, X;
double p[300];

int validate(int ind, double p){
	double s = J[ind] + p * X / 100.0;
	int i;
	double budget = 100.0 - p;
	for (i = 0; i < n; i++){
		if (i == ind) continue;
		double tmp = (s - J[i]) / X * 100.0;
		if (tmp < 0) continue;
		budget -= (tmp + 1e-10);
		if (budget < 0) return 1;
	}
	return 0;
}

void doit(){
	int i;
	for (i = 0; i < n; i++){
		double s = 0.0;
		double t = 100.0;
		while ( (t - s) > 1e-7 ){
			double tmp = (s + t) / 2;
			if (validate(i, tmp)) t = tmp;
			else s = tmp;
		}
		p[i] =  ( s + t ) / 2.0;
		if (p[i] < 0.0) p[i] = 0.0;
		if (p[i] > 100.0) p[i] = 100.0;
	}
}

void readInput(const char* filename){
	ifstream fin(filename);
	fin >> T;
	int i, j;
	for (i = 0; i < T; i++){
		fin >> n;
		X = 0;
		for (j = 0; j < n; j++) {
			fin >> J[j];
			X += J[j];
		}

		doit();

		cout << "Case #" << i + 1 << ": ";
		cout.precision(8);
		for (j = 0; j < n; j++) cout << p[j] << " ";
		cout << endl;
	}
	fin.close();
}

int main(){
	readInput("./A-large.in");
	return 0;
}
