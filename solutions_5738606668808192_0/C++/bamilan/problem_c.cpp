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


long long isPrime(long long num)
{
	if (num <= 3)
	{
		if (num < 2) return 0;
		else return 0;
	}
	else if (num % 2 == 0 || num % 3 == 0)
	{
		if (num % 2 == 0) return 2;
		else return 3;
	}
	else 
	{
		for (long long i = 5; i * i <= num; i += 6)
		{
			if (num % i == 0 || num % (i + 2) == 0)
			{
				if (num % i == 0) return i;
				else return (i + 2);
			}
		}
		return 0;
	}
}


bool isNumOkay(char num[])
{
	FORI(i, 2, 11)
	{
		if (isPrime(convertFromBinary(num, i)) == 0) return false;
	}
	return true;
}


std::vector<long long> getDivisors(char num[])
{
	std::vector<long long> divs;
	FORI(i, 2, 11)
	{
		divs.push_back(isPrime(convertFromBinary(num, i)));
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
			if (num[k] == '0') num[k] = '1';
			else
			{
				k--;
				while (num[k] == '1' && k > 0) k--;
				num[k]++;
			}
		}
	}
}



int main()
{
	//freopen("C-small-attempt2.in", "r", stdin);
	//freopen("C-small-attempt2.out", "wb", stdout);

	int numOfTestcases;
	std::cin >> numOfTestcases;

	FOR(i, numOfTestcases)
	{
		std::cout << "Case #" << (i + 1) << ":" << std::endl;

		int numOfResults;
		std::cin >> numLen >> numOfResults;

		searchNums(numOfResults + 1);
	}

	if (numOfTestcases == 0)
	{
		;
	}

	return 0;
}