// 2011_2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <functional>
#include <vector>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <math.h>
#include <intrin.h>
#include <bitset>


#pragma intrinsic(_mul128)

using namespace std;

FILE * in, *out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

#define LL long long

int ri() { int a; fscanf(in, "%d", &a); return a; }
double rf() { double a; fscanf(in, "%lf", &a); return a; }
char sbuf[100005];
string rstr()
{
	//fscanf(in, "%lf", sbuf); 
	char c;
	char * b = sbuf;
	while (c = fgetc(in))
	{
		if (c == '\n' || c == 255) break;
		*b++ = c;
	}
	*b = 0;
	return sbuf;
}


int nod(int a, int b)
{
	if (a == 1 || b == 1) return 1;
	if (a == 0) return b;
	if (b == 0) return a;

	return nod(b%a, a);
}

vector<int> primes;
void calculatePrimes()
{
	primes.push_back(2);
	for (int i = 3; i < (1<<15); i += 2)
	{
		bool bFound = false;
		int m = sqrt(i);
		for (int j = 1; j < primes.size() && !bFound && primes[j] <= m; j++)
			bFound = ((i%primes[j]) == 0);
		if (!bFound)
			primes.push_back(i);
	}
}

void fillPrimePower(int n, int num, vector<int>& toppower)
{
	toppower.resize(primes.size());
	for (int i = 0; i < primes.size(); i++)
		toppower[i] = 1;

	fj(num)
	for (int i = 0; i < primes.size(); i++)
		toppower[i] = (toppower[i]*n)%primes[i];
}

void fillPower(int n, vector<long long>& toppower)
{
	long long p = 1;
	fi(19)
	{
		toppower.push_back(p);
		p *= n;
	}
}

int main()
{
	long long n, t, num; 
	string s;
	
	calculatePrimes();
	cin >> t;

	fk(t)
	{
		cin >> n >> num;
		vector<int> toppower[11];
		vector<long long> pow[11];
		for (int i = 2; i <= 10; i++)
		{
			fillPrimePower(i, n-1, toppower[i]);
			fillPower(i, pow[i]);
		}

		long start = 1;
		cout << "Case #1: " << endl;
		while (num)
		{
			vector<long long> numbers(11);
			fj(18)
			{
				if ((1 << j) > start) break;

				if ((1 << j) & start)
				{
					for (int i = 2; i <= 10; i++)
						numbers[i] += pow[i][j];
				}
			}

			bool bFound = true;
			for (int i = 2; i <= 10 && bFound; i++)
			{
				bFound = false;
				for (int j = 0; j < primes.size() && !bFound; j++)
					bFound = ((toppower[i][j] + numbers[i]) % primes[j] == 0);
			}
			if (bFound)
			{
				num--;
				if (n == 16)
				{
					std::bitset<16> x(start + (1 << (n - 1)));
					std::cout << x << " ";
				}
				if (n == 32)
				{
					std::bitset<32> x(start + (1 << (n - 1)));
					std::cout << x << " ";
				}
				if (n == 6)
				{
					std::bitset<6> x(start + (1 << (n - 1)));
					std::cout << x << " ";
				}
				for (int i = 2; i <= 10 && bFound; i++)
				{
					bFound = false;
					for (int j = 0; j < primes.size() && !bFound; j++)
					{
						bFound = ((toppower[i][j] + numbers[i]) % primes[j] == 0);
						if (bFound)
						{
							cout << primes[j] << " ";
							long long number = 1;
							fk(n - 1) number *= i;
							number = number + numbers[i];
							if (number % primes[j] != 0)
								primes[j] = primes[j];
						}
					}
				}
				cout << endl;
			}

			start += 2;
		}
	}

	return 0;
}

