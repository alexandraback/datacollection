#include <iostream>
#include <fstream>
using namespace std;

bool check(int n);

int main(int argc, char *argv[]) {
	ifstream fin("fair.in", ios::in);

	int tstNum, tstCount;
	fin >> tstNum; tstCount = tstNum;
	while(tstCount--) {
		int a, b;
		fin >> a >> b;
		int res = 0;
		for(int i = 1; i < 33; i++) {
			if(check(i)) {
				int tmp = i * i;
				if(check(tmp)) {
					if(a <= tmp && tmp <= b) ++res;
				}
			}
		}
		ofstream fout("fair.out", ios::app);
		fout << "Case #" << tstNum - tstCount << ": ";
		fout << res << endl;
		fout.close();
	}
	fin.close();
	return 0;
}

bool check(int a) {
	int b = 0, tmp = a;
	while(tmp) {
		b *= 10;
		b += tmp % 10;
		tmp /= 10;
	}
	return b == a;
}
