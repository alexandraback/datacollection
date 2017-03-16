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

vector<char> prime(N_MAX + 1, true);
vector<long long> p;

void build()
{
	prime[0] = prime[1] = false;
	for (int i = 2; i <= N_MAX; ++i)
		if (prime[i])
		{
			p.push_back(i);
			if (i * 1ll * i <= N_MAX)
				for (int j = i*i; j <= N_MAX; j += i)
					prime[j] = false;
		}
}

long long is_not_prime(long long k)
{
	for (vector<long long>::iterator i = p.begin(); i != p.end(); i++)
	{
		if (k % (*i) == 0)
		{
			if (k == (*i))
			{
				return 0;
			}
			else
			{
				return *i;
			}
		}
	}

	p.push_back(k);
	return 0;
}

bool test(long long k)
{
	long long d[11];
	for (int base = 2; base <= 10; base++)
	{
		long long ans = convert(k, base);
		d[base] = is_not_prime(ans);
		if (!d[base])
		{
			return false;
		}
	}

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
		cout << " " << d[i];
	}

	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	build();

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
		int cur_count = 0;

		while (cur_count < count)
		{
			if (test(cur))
			{
				cur_count++;
			}
			cur+=2;
		}
		
	}

	return 0;
}