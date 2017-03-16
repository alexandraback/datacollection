#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main(int argc, char** argv) {

	ifstream fin(argv[1]);
	int n;

	fin >> n;

	for(int i = 1; i <= n; i++) {
		int m;
		set<int> digits;
		int last = -1;
		
		fin >> m;
		
		for(int j = 1; j <= 100; j++) {
			int k = m * j;
			while(k > 0) {
				digits.insert(k % 10);
				k /= 10;
			}
			if(digits.size() == 10) {
				last = m * j;
				break;
			}
		}

		cout << "Case #" << i << ": ";
		if(last == -1) {
			cout << "INSOMNIA" << endl;
		} else {
			cout << last << endl;
		}
	}

	return 0;
}
