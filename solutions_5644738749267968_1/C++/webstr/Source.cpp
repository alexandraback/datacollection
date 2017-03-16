#include <fstream>
#include <algorithm>
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
		int n;
		fin >> n;
		double *mas1 = new double [n];
		double *mas2 = new double [n];

		for (int i = 0; i < n; i++){
			fin >> mas1[i];
		}
		for (int i = 0; i < n; i++){
			fin >> mas2[i];
		}

		sort(&mas1[0], &mas1[n]);
		sort(&mas2[0], &mas2[n]);

		int k1 = 0; int k2 = 0;
		int s1 = 0;
		while (k1 < n){
			if (mas1[k1] > mas2[k2]){
				s1++;
				k1++;
				k2++;
			} else {
				k1++;
			}
		}

		int s2 = 0;
		k1 = n - 1;
		k2 = n - 1;

		while (k1 >= 0){
			if (mas1[k1] > mas2[k2]){
				s2++;
				k1--;
			} else {
				k1--;
				k2--;
			}
		}
		fout << "Case #" << k << ": " << s1 << " " << s2 << endl;
	}
}