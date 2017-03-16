#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	int nTestCases;
	cin >> nTestCases;

	int maxHeight = 2500;
	for (int i = 0; i < nTestCases; ++i) {
		int N;
		cin >> N;

		int count[maxHeight];
		for (int h = 0; h < maxHeight; ++h) {
			count[h] = 0;
		}

		for (int num = 0; num < (2*N - 1)*N; ++num) {
			int height;
			cin >> height;
			
			count[height]++;
		}

		cout << "Case #" << i+1 << ": ";
		for (int h = 0; h < maxHeight; ++h) {
			if (count[h] % 2 == 1) {
				cout << h << " ";
			}

		} 

		cout << endl;	
	}

	return 0;
}