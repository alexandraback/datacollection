#include <stdio.h>
#include <iostream>
#include <vector>
// #define TEST
int n = 32, j = 500;

using namespace std;
typedef unsigned long long uint64;
int * s;

using namespace std;

uint64 power(int, int);

void jam(int dist, int index)
{
	if (j == 0)
		return;

	if (index >= n - 1 - dist) {
		for (int i = 0; i < n; i++)
			cout << s[i];
		for (int i = 2; i <= 10; i++)
			cout << " " << power(i, dist) + 1;
		cout << endl;
		j--;
		return;
	}

	jam(dist, index + 1);

	if (s[index] == 0 && s[index + dist] == 0) {
		s[index] = s[index + dist] = 1;
		jam(dist, index + 1);
		s[index] = s[index + dist] = 0;
	}
	
}

uint64 power(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	uint64 result = power(base, exponent >> 1);
	result *= result;
	if (exponent % 2 == 1)
		result *= base;
	return result;
}

int main()
{
	#ifndef TEST
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	s = new int[n];
	s[0] = s[n - 1] = 1;

	cout << "Case #1: " << endl;
	for (int i = 1; i < n - 1; i++) {
		if (i == n - 1 - i) continue;
		for (int j = 1; j < n - 1; j++)
			s[j] = 0;
		s[i] = s[n - 1 - i] = 1;
		jam(i, 1);
		if (j == 0) break;
	}
}
