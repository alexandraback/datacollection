#define _CRT_SECURE_NO_WARNINGS
#define N_MAX (100000000)

#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <bitset>

using namespace std;

int t, n;

long long convert(long long a, int base)
{
	long long q = 1;
	long long ans = 0;

	while (a)
	{
		ans += (a%2) * q;
		q *= base;
		a /= 2;
	}
	return ans;
}

bool test(long long k)
{
	bitset<40> bin(k);

	cout << endl;

	for (int h = 0; h < n / 16; h++)
	{
		bool is_skiped = true;

		for (int i = 0; i < 40; i++)
		{
			if (bin.at(39 - i))
			{
				is_skiped = false;
			}

			if (!is_skiped)
			{
				cout << (bin.at(39 - i) ? "1" : "0");
			}
		}
	}

	for (int i = 2; i <= 10; i++)
	{
		cout << " " << convert(k, i);
	}

	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ":";
		cin >> n;
		int count;
		cin >> count;

		long long cur = 1;
		cur <<= 15;
		cur += 1;
		
		for (int i = 0; i < count; i++)
		{
			test(cur);
			cur += 2;
		}
	}

	return 0;
}