#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
void solutionA(string A, int n) {
	int s = A.length();
	//Case #1: CAB
	if (s == 1 || s == 0) {
		cout << "Case #" << n << ": " << A << endl;
		return;
	}
	string result;
	result += A[0];
	for (int i = 1; i < s; i++) {
		if (A[i] >= result[0])
			result = A[i] + result;
		else
			result = result + A[i];
	}
	cout << "Case #" << n << ": " << result << endl;
}
int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	int n = 1;
	string A;
	while (cin >> A) {
		solutionA(A, n);
		n++;
	}
	return 1;
}
