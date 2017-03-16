#include "stdafx.h"

bool isP(long long v)
{
	int digits[20];
	int pos = 0;
	while (v > 0)
	{
		digits[pos++] = v % 10;
		v /= 10;
	}
	for (int i = 0; i < pos / 2; i++)
		if (digits[i] != digits[pos - i - 1])
			return false;
	return true;
}

int main()
{
	for (long long i = 0; i < 1000000000; i++)
	{
		if (isP(i) && isP(i * i)) printf("%lld square: %lld is p\n", i, i * i);
	}
	return 0;
}