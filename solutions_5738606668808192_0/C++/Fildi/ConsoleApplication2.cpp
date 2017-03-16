// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int primeNumbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 };
int primeCount = sizeof(primeNumbers) / sizeof(int);

void print(int *number, int *res, int n) {
	for (int i = 0; i < n; i++) {
		cout << (char)(number[i] + '0');
	}
	cout << " ";
	for (int i = 2; i <= 10; i++) {
		cout << res[i];
		if (i == 10)
			cout << endl;
		else
			cout << " ";
	}
}
int checkNumber2(__int64 num){
	for (int d = 2; d < primeCount; d++)
		if (num % primeNumbers[d] == 0 && num != primeNumbers[d])
			return primeNumbers[d];
	return 0;
}
void solve2(int n, int j) {
	int *number = new int[n];
	memset(number, 0, sizeof(int) * n);
	number[0] = 1;
	number[n - 1] = 1;
	int count = 0;
	while (count < j) {
		int res[11];
		int q = 0;
		for (int k = 2; k <= 10; k++) {
			__int64 num = 0;
			for (int i = 0; i < n; i++)
				num = num * k + number[i];
			int val = checkNumber2(num);
			if (val > 0) {
				res[k] = val;
				q++;
			}
			else
				break;
		}
		if (q == 9) {
			print(number, res, n);
			count++;
		}
		int k = n - 2;
		while (number[k] == 1) {
			number[k] = 0;
			k--;
		}
		number[k] = 1;
	}
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int j, n;
		cin >> n >> j;
		cout << "Case #" << i + 1 << ":" << endl;
		solve2(n, j);
	}
	return 0;
}

