#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

double key[100000];
double prob[100000];

int main() {
    ofstream fout ("1AA.out");
    ifstream fin ("1AA.in");
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		int A,B;
		fin >> A >> B;
		for (int i = 0; i < A; i++) {
			fin >> key[i];
			key[i];
		}
		prob[0] = key[0];
		for (int i = 1; i < A; i++) prob[i] = prob[i-1]*key[i];
		double ans = B+2;
		for (int i = 0; i < A; i++) {
			double guess = (B-A+1+2*i)*prob[A-1-i]+(2*B-A+2+2*i)*(1-prob[A-1-i]);
			ans = min(ans,guess);
		}
		fout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}