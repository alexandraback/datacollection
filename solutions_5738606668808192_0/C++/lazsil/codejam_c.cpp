#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long int ConvertToBase(unsigned long long int value, int base)
{
	long long int rv{ 0 };
	int i = 0;
	do {
		long long int rem = value % 10;
		rv += rem *  static_cast<long long int>(pow(base, i));
		value /= 10;
		i++;
	} while (value > 0);

	return rv;
}

long long int Add(int n)
{
	long long int rv = 0;
	int i = 1;
	while (n > 0)
	{
		rv += i * (n & 1);
		i*=10;
		n >>= 1;
	}

	return rv*10;
}

int main()
{
	vector<long long int> prime{ 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97 };

	int num_of_testcases;
	cin >> num_of_testcases;
	for (int t = 1; t <= num_of_testcases; ++t){
		int len, num_of_jamcoins;
		cin >> len >> num_of_jamcoins;

		cout << "Case #" << t << ":\n";

		int cnt = 1;

		long long int cur{ 1 + static_cast<long long int>(pow(10, len-1)) };
		auto or = cur;
		while (num_of_jamcoins > 0)
		{
			vector<long long int> dividers(9);
			bool notprime = true;
			for (int i = 2; i <= 10; ++i)
			{
				auto vv = ConvertToBase(cur, i);
				bool isprime = true;
				for (int j = 0; j < prime.size(); ++j)
				{
					if ((vv%prime[j]) == 0)
					{
						dividers[i - 2] = prime[j];
						isprime = false;
						break;
					}
				}
				if (isprime)
				{
					notprime = false;
					break;
				}
			}

			if(notprime)
			{
				cout << cur << " ";
				for (auto v : dividers)
				{
					cout << v << " ";
				}
				cout << endl;
				--num_of_jamcoins;
			}


			cur = or+Add(cnt);
			cnt++;

		}
	}

    return 0;
}

