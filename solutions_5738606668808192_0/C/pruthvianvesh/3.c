#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long long int powCustom(long long int base, long long int power){
	long long int result = 1, i;
	for (i = 0; i < power; ++i)
	{
		result *= base;
	}
	return result;
}

long long int decToBin(long long int dec){
	long long int bin = 0, mul = 1;
	while(dec != 0){
		bin += (dec%2)*mul;
		mul *= 10;
		dec /= 2;
	}
	return bin;
}

void print(long long int combination, long long int factorOfBase[]){
	int base;
	printf("%lld", combination);
	for (base = 2; base <= 10; ++base)
	{
		printf(" %lld", factorOfBase[base]);
	}
	printf("\n");
}

long long int convertFromBase(long long int combination, int n, long long int base){
	long long int number = 0, power = 0;
	while(combination != 0){
		number += (combination%10)*powCustom(base, power);
		combination /= 10;
		power++;
	}
	return number;
}

long long int getFactor(long long int number){
	long long int i;
	for (i = 2; i <= (long long int)floor(sqrt(number)); ++i)
		if (number%i == 0)
			return i;
	return 0;
}

bool checkIfJamCoin(long long int combination, int n){
	long long int factorOfBase[11], base;
	for (base = 2; base <= 10; ++base)
	{
		long long int number = convertFromBase(combination, n, base);
		long long int factor = getFactor(number);
		if (factor == 0)
			break;
		else
			factorOfBase[base] = factor;
	}
	if (base == 11)
	{
		print(combination, factorOfBase);
		return true;
	}
	return false;
}

int main()
{
	//freopen("input3.txt", "r", stdin);
	//freopen("output3.txt", "w", stdout);
	int totalCases, caseNo;		scanf("%d", &totalCases);
	for (caseNo = 1; caseNo <= totalCases; ++caseNo)
	{
		int n, j;		scanf("%d%d", &n, &j);
		long long int i;
		printf("Case #%d:\n", caseNo);
		for (i = powCustom(2, n-2); i < powCustom(2, n-1); ++i)
		{
			long long int combination = decToBin(i)*10 + 1;
			if (checkIfJamCoin(combination, n))
				j--;
			if (j == 0)
				break;
		}
	}
	return 0;
}
