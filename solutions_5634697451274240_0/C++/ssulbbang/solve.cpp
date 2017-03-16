#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

	ifstream fin(argv[1]);
	int n;

	fin >> n;

	for(int i = 1; i <= n; i++) {
		string p;
		fin >> p;

		int up[101];
		int down[101];

		up[0] = down[0] = 0;

		for(int j = 1; j <= p.size(); j++) {
			if(p[j - 1] == '+') {
				up[j] = up[j - 1];
				down[j] = up[j - 1] + 1;
			} else {
				up[j] = down[j - 1] + 1;
				down[j] = down[j - 1];
			}
		}

		cout << "Case #" << i << ": " << up[p.size()] << endl;
	}

	return 0;
}