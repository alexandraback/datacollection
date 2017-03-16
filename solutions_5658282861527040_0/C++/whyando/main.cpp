#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <string>

using namespace std;

int main() {
	ofstream fout("lottery2.out");
	ifstream fin("lottery2.in");

	int t;
	fin >> t;

	for (int caseNo = 1; caseNo <= t; caseNo++){
		int count = 0;
		int a, b, k;
		fin >> a >> b >> k;
		for (int i = 0; i < a; i++){
			for (int j = 0; j < b; j++){
				if ((i&j) < k)
					count++;
			}
		}

		fout << "Case #" << caseNo << ": " << count << endl;
	}
	return 0;
}