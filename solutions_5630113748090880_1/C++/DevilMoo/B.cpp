#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int numberFlip(string);

int main() {
	ofstream myfile("B-large.txt");
	ifstream target("B-large.in");
	int T;
	target >> T;
	for (int i = 0; i < T; i++) {
		int N;
		target >> N;
		int numElements = N * (2 * N - 1);
		int row[numElements];
		int result[N];
		int numOfResult = 0;
		for (int j = 0; j < numElements; j++) {
			target >> row[j];
		}
		sort(row, row + numElements);
		int prev = row[0];
		int count = 1;
		for (int j = 1; j < numElements; j++) {
			if (row[j] == prev)
				count += 1;
			else {
				if (count % 2 != 0) {
					result[numOfResult] = prev;
					numOfResult += 1;
				}
				count = 1;
				prev = row[j];
			}
		}
		if (count == 1)
			result[N - 1] = row[numElements - 1];
		sort(result, result + N);
		myfile << "Case #" << i + 1 << ": ";
		for (int j = 0; j < N - 1; j++) {
			myfile << result[j] << ' ';
		}
		myfile << result[N-1] << endl;
	}
	return 0;
}

