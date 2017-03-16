#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int repn;
	fin >> repn;
	for (int rep = 0; rep < repn; rep++) {
		string strin;
		int n, sum = 0, fri = 0;
		fin >> n >> strin;
		for (int i = 0; i < n+1; i++) {
			int num = strin[i] - '0';
			int addfri = 0;
			if (sum < i) {
				addfri = i - sum;
				fri += addfri;
			}
//			cout << "the " << i << "th is : " << num << endl;  
			sum += (num + addfri);
		}
		fout << "Case #" << rep+1 << ": " << fri << endl; 
	}
}