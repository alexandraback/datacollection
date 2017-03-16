#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin("bullseye.in", ios::in);

	int tstNum, tstCount;
	cin >> tstNum; tstCount = tstNum;
	while(tstCount--) {
		unsigned long long r, t;
		cin >> r >> t;
		unsigned long long d = 2 * r - 1;
		double dd = 2 * r - 1;
		unsigned long long n;
		n = (sqrt(dd + 8 * t / dd) - sqrt(dd)) / (4 / sqrt(dd));
		n += 100;
		while(2 * n + d > t / double(n)) n--;
		ofstream fout("bullseye.out", ios::app);
		cout << "Case #" << tstNum - tstCount << ": ";
		cout << n << endl;
		fout.close();
	}
	fin.close();
	return 0;
}
