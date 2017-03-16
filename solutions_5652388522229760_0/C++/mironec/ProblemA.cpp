#include "stdafx.h"
#include <iostream>
#include "ProblemA.h"

using namespace std;

void countThings(int num, int * seen) {
	while (num > 0) {
		seen[num % 10] = 1;
		num /= 10;
	}
}

void doSheep(int N, int numCase) {
	int ret = N;
	int seen[] = { 0,0,0,0,0,0,0,0,0,0 };
	int allSeen = 0;

	if (N == 0) { cout << "Case #" << numCase << ": INSOMNIA" << endl; return; }

	countThings(ret, seen);
	allSeen = 1;
	for (int i = 0; i < 10; i++) { if (seen[i] == 0) allSeen = 0; }

	while (!allSeen) {
		ret += N;
		countThings(ret, seen);

		allSeen = 1;
		for (int i = 0; i < 10; i++) { if (seen[i] == 0) allSeen = 0; }
	}

	cout << "Case #" << numCase << ": " << ret << endl;
}

int runProblemA() {
	int T;

	cin >> T;

	int sum = 0;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		doSheep(N, i+1);
	}

	return 0;
}

/*int main() {
	return runProblemA();
}*/

