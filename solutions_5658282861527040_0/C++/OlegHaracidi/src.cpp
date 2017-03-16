#include <fstream>

using namespace std;

int main() {
	ifstream fin("B-small-attempt0.in");
	ofstream fout("out.txt");

	int T;
	fin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int a, b, c;
		fin >> a >> b >> c;
		int k = 0;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				k += ((i & j) < c);
			}
		}
		fout << "Case #" << test_case << ": " << k << endl;
	}

	return 0;
}