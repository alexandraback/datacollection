//#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <list>
#include<string>

#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORI(i, a, n) for(int i = (int)(a); i < (int)(n); i++)


int numLen;


long long convertFromBinary(char str[], int base)
{
	long long res = 0;

	FOR(i, numLen)
	{
		res *= base;
		res += str[i] - 48;
	}

	return res;
}


long long isPrimeFast(long long num)
{
	if (num % 2 == 0) return 2;
	if (num % 3 == 0) return 3;
	if (num % 5 == 0) return 5;
	if (num % 7 == 0) return 7;
	if (num % 11 == 0) return 11;
	if (num % 13 == 0) return 13;
	if (num % 17 == 0) return 17;
	return 0;
}


bool isNumOkay(char num[])
{
	FORI(i, 2, 11)
	{
		if (isPrimeFast(convertFromBinary(num, i)) == 0) return false;
	}
	return true;
}


std::vector<long long> getDivisors(char num[])
{
	std::vector<long long> divs;
	FORI(i, 2, 11)
	{
		divs.push_back(isPrimeFast(convertFromBinary(num, i)));
	}
	return divs;
}


void printNumWithDivisors(char num[], std::vector<long long> divisors)
{
	FOR(i, numLen)
	{
		std::cout << num[i];
	}
	FOR(i, 9) std::cout << " " << divisors[i];
	std::cout << std::endl;
}


void searchNums(int count)
{
	char num[32];
	FOR(i, 32) num[i] = '0';

	num[0] = '1';
	num[numLen - 1] = '1';

	int found = 0;

	int numOfOnes = 2;

	int k = 1;
	while (k > 0)
	{
		if (k == numLen - 2)
		{
			if (isNumOkay(num))
			{
				found++;
				if (found == count) break;
				printNumWithDivisors(num, getDivisors(num));
			}
		}
		
		if (k < numLen - 2)
		{
			k++;
			num[k] = '0';
		}
		else
		{
			if (num[k] == '0')
			{
				num[k] = '1';
				numOfOnes++;
			}
			else
			{
				k--;
				numOfOnes--;
				while (num[k] == '1' && k > 0)
				{
					k--;
					numOfOnes--;
				}
				num[k]++;
				numOfOnes++;
			}
		}
	}
}



int main()
{
	//freopen("C-large.in", "r", stdin);
	//freopen("C-large.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ":" << std::endl;

		int numOfResults;
		std::cin >> numLen >> numOfResults;

		searchNums(numOfResults + 1);
	}

	return 0;
}