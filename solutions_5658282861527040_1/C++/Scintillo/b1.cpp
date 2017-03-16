#include <cstdint>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

struct Input
{
	unsigned int a, b, k;

	bool operator<(Input const& i) const
	{
		if(a < i.a) return true;
		if(a > i.a) return false;

		if(b < i.b) return true;
		if(b > i.b) return false;

		if(k < i.k) return true;
		if(k > i.k) return false;

		return false;
	}
};

uint64_t poss(unsigned int a, unsigned int b, unsigned int k, unsigned int bitCount)
{
	static map<Input, uint64_t> cache;

	Input input{ a, b, k };
	if(cache.count(input) != 0)
		return cache[input];

	if(bitCount == 0) return 1;

	unsigned int mask = 1 << (bitCount - 1);
	unsigned int maskLeft = mask - 1;

	//cout << mask << endl;

	if((a & mask) == 0 && (b & mask) == 0 && (k & mask) == 0)
		return poss(a, b, k, bitCount - 1);


	uint64_t total = 0;

	// Both zero
	unsigned int nA = min(a, maskLeft);
	unsigned int nB = min(b, maskLeft);
	unsigned int nK = min(k, maskLeft);
	total += poss(nA, nB, nK, bitCount - 1);

	// A zero, B one
	if(b & mask)
	{
		nA = min(a, maskLeft);
		nB = b & maskLeft;
		nK = min(k, maskLeft);
		total += poss(nA, nB, nK, bitCount - 1);
	}

	// A one, B zero
	if(a & mask)
	{
		nA = a & maskLeft;
		nB = min(b, maskLeft);
		nK = min(k, maskLeft);
		total += poss(nA, nB, nK, bitCount - 1);
	}

	// Both one
	if((a & mask) && (b & mask) && (k & mask))
	{
		nA = a & maskLeft;
		nB = b & maskLeft;
		nK = k & maskLeft;
		total += poss(nA, nB, nK, bitCount - 1);
	}

	return cache[input] = total;
}

uint64_t solveCase()
{
	unsigned int a, b, k;
	cin >> a >> b >> k;
	a--;
	b--;
	k--;

	return poss(a, b, k, 32);
}

int main()
{
	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		uint64_t res = solveCase();

		cout << "Case #" << i << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}