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
bitset<32> jamcoins[510];
int main()
{
	int n = 32;
	int j = 500;
	for (int base = 2; base <= 10; base++)
	{
		long long divisor = 1;
		for (int k = 0; k < (n/2); k++)
			divisor *= base;
		divisor += 1;
		divisors[base - 2] = divisor;
	}
	freopen("output2.txt", "w", stdout);
	long long temp = (1 << (n/2 - 1)) + 1;
	for (int k = 0; k < j; k++)
	{
		temp += 2;
		auto tempBitset = new bitset<32>(temp);
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