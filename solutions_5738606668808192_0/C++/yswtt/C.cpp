#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

const long long PN = 110000000;
vector<long long> p;
bool seen[PN + 1];

void findP()
{
	for (int i = 2; i <= PN; ++i)
	{
		if (!seen[i])
			p.push_back(i);
		for (int j = 0; j < p.size(); ++j)
		{
			if (i * p[j] <= PN)
				seen[i * p[j]] = true;
			else
				break;
			if (i % p[j] == 0)
				break;
		}
	}
}

long long d[12];

long long convert(long long cur, int base)
{
	long long res = 0, t = 1;
	while (cur > 0)
	{
		if (cur % 2 == 1)
			res += t;
		cur /= 2;
		t *= base;
	}
	return res;
}

void print_binary(long long cur)
{
	vector<int> v;
	while (cur > 0)
	{
		v.push_back(cur % 2);
		cur /= 2;
	}
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
}

int main()
{
	findP();
	
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int n, j;
		cin >> n >> j;
		cout << "Case #" << t << ":" << endl;
		long long cur = (1 << (n - 1)) + 1;
		while (j > 0)
		{
			bool prime = false;
			for (int i = 2; i <= 10; ++i)
			{
				long long tmp = (i == 2) ? cur : convert(cur, i);
				if ((tmp <= PN) && (!seen[tmp]))
				{
					prime = true;
					break;
				}
				d[i] = -1;
				for (int k = 0; k < p.size(); ++k)
				{
					if (tmp % p[k] == 0)
					{
						d[i] = p[k];
						break;
					}
					else if (p[k] * p[k] > tmp)
					{
						prime = true;
						break;
					}
				}
				if (prime)
					break;
			}
			if (!prime)
			{
				j--;
				print_binary(cur);
				for (int i = 2; i <= 10; ++i)
					cout << " " << d[i];
				cout << endl;
			}
			cur += 2;
		}
	}

    return 0;
}
