#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;
long long divisors[9];
bitset<16> jamcoins[51];
int main()
{
	int n = 16;
	int j = 50;
	for (int base = 2; base <= 10; base++)
	{
		long long divisor = 1;
		for (int k = 0; k < (n/2); k++)
			divisor *= base;
		divisor += 1;
		divisors[base - 2] = divisor;
	}
	freopen("output1.txt", "w", stdout);
	long long temp = (1 << (n/2 - 1)) + 1;
	for (int k = 0; k < j; k++)
	{
		temp += 2;
		auto tempBitset = new bitset<16>(temp);
		jamcoins[k] = *tempBitset << (n/2);
		jamcoins[k] |= *tempBitset;
	}
	printf("Case #1:\n");
	for (int i = 0; i < j; i++)
	{
		cout << jamcoins[i];
		for (int k = 0; k < 9; k++)
			cout << " " << divisors[k];
		cout << endl;
	}
	return 0;
}