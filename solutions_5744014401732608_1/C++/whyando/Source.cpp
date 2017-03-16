#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

ofstream fout("out.txt");
ifstream fin("in.txt");

int B;
cpp_int M;

void function1(const int test_no) {
	fin >> B;
	fin >> M;
	//B = 5;
	//M = 4;

	vector<cpp_int> max(B, 0);
	max[0] = 1;
	max[1] = 1;
	int n = -1;

	for (int i = 1; i < B; i++) {
		if (i == 1)
			max[i] = 1;
		else
			max[i] = max[i - 1] * 2;
		if (M <= max[i]) {
			n = i;
			break;
		}
	}
	if (n == -1) {
		fout << "Case #" << test_no << ": " << "IMPOSSIBLE" << endl;
		return;
	}
	fout << "Case #" << test_no << ": " << "POSSIBLE" << endl;
	//now:
	//let all foward connections be present for nodes 0 to n-1
	
	cpp_int req = M;
	vector<int> fin(B, 0);
	
	for (int i = n - 1; i >= 0; i--) {
		if (max[i] <= req) {
			fin[i] = 1;
			req -= max[i];
		}
	}
	if (req != 0) {
		cout << "error :L" << endl;
		exit(-1);
	}

	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B-1; j++) {
			if (i >= j)
				fout << "0";
			else if (j <= n - 1)
				fout << "1";
			else
				fout << "0";

		}
		//for final node i->B-1
		fout << fin[i];
		fout << endl;
	}
}

int main() {
	int T;
	fin >> T;
	//T = 1;
	for (int t = 1; t <= T; t++) {
		function1(t);
	}

	return 0;
}