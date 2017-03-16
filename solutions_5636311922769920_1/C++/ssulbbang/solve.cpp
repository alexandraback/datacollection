#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

	ifstream fin(argv[1]);
	int t;

	fin >> t;

	for(int i = 1; i <= t; i++) {
		int k, c, s;
		vector<int> positions;
		fin >> k >> c >> s;


		if(c == 1 && k == s) {
			for(int j = 1; j <= k; j++) {
				positions.push_back(j);
			}
		} 
		else if(c > 1 && (k + 1) / 2 <= s) {
			for(int j = 1; j <= k; j += 2) {
				if(j < k) {
					positions.push_back((j - 1) * k + j + 1);
				}
				else {
					positions.push_back((j - 1) * k + j);
				}
			}
		}


		cout << "Case #" << i << ": ";
		if(positions.size() == 0) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			for(int j = 0; j < positions.size(); j++) {
				cout << positions[j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}