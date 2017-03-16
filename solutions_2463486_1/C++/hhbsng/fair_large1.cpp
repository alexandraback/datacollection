#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool check(long long n);

int main(int argc, char *argv[]) {
	ifstream fin("fair.in", ios::in);
	
	vector<long long> fairnum;
	for(long long i = 1; i < 10000000; ++i) {
		if(check(i)) {
			long long tmp = i * i;
			if(check(tmp)) {
				fairnum.push_back(tmp);
			}
		}
	}

	int tstNum, tstCount;
	fin >> tstNum; tstCount = tstNum;
	while(tstCount--) {
		long long a, b;
		fin >> a >> b;
		long long res = 0;
		vector<long long>::const_iterator it = fairnum.begin();
		while(it != fairnum.end()) {
			if(a <= *it && *it <= b) ++res;
			++it;
		}

		ofstream fout("fair.out", ios::app);
		fout << "Case #" << tstNum - tstCount << ": ";
		fout << res << endl;
		fout.close();
	}
	fin.close();
	return 0;
}

bool check(long long a) {
	long long b = 0, tmp = a;
	while(tmp) {
		b *= 10;
		b += tmp % 10;
		tmp /= 10;
	}
	return b == a;
}
