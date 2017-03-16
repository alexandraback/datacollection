#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
	FILE* fp = fopen("A-large.in.txt", "r");
	char inputbuf[4096];
	fgets(inputbuf, sizeof(inputbuf), fp);
	int nCases = atoi(inputbuf);

	for (int caseNo = 1; caseNo <= nCases; ++caseNo) {
		cout << "Case #" << caseNo << ":";

		fgets(inputbuf, sizeof(inputbuf), fp);
		char* ptr = strtok(inputbuf, " ");
		int N = atoi(ptr);
		vector<int> s(N);
		vector<bool> exceed(N);

		double total = 0;
		for (int i = 0; i < N; ++i) {
			ptr = strtok(NULL, " ");
			s[i] = atoi(ptr);
			total += s[i];
		}

		double avg = total / N;

		int nEx = 0;
		double totalEx = 0;
		for (int i = 0; i < N; ++i) {
			if (2 * avg <= s[i]) {
				totalEx += s[i];
				exceed[i] = true;
				++nEx;
			} else {
				exceed[i] = false;
			}
		}

		double avgEx = (2 * total - totalEx) / (N - nEx);

		for (int i = 0; i < N; ++i) {
			if (exceed[i]) {
				printf(" 0.0");
			} else {
				if (totalEx > 0) {
					double res = (avgEx - s[i]) / total * 100.0;
					printf(" %.6f", res);
				} else {
					double res = (avg * 2 - s[i]) / total * 100.0;
					printf(" %.6f", res);
				}
			}
		}

		cout << endl;

	}

	fclose(fp);
	return 0;
}
