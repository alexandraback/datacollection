#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> prime;
int an[500][10];
bool is_prime[100000000];
__int128 make_number(int k, int d)
{
	__int128 ret = 0;
	__int128 tr = 1;
	for (int i = 0; i < 16; i++)
	{
		if (k & (1 << i))
			ret += tr;
		tr *= d;
	}
	return ret;
}
int main()
{
	memset(is_prime, -1, sizeof(is_prime));
	for (int i = 2; i < (10000); i++)
		if (is_prime[i])
		{
			prime.push_back(i);
			for (int j = i + i; j < (10000); j+=i)
				is_prime[i] = false;
		}
	cerr << "Prime table finished!\n";
	int ans = 0;
	for (int i = (1 << 15) + 1; i < (1 << 16); i += 2)
	{
		bool flag = 1;
		an[ans][0] = i;
		an[ans][1] = 0;
//		if ((((i >> 8) << 8) | 1) == i)
//		{
			cerr << "Current " << i << endl;
//		}
		for (int v : prime)
		{
			if (v >= i)
			{
				flag = false;
				break;
			}
			if (i % v == 0)
			{
				an[ans][1] = v;
				break;
			}
		}
		if (an[ans][1] == 0) flag = false;
		for (int j = 3; j <= 10; j++)
		{
			if (!flag) break;
			__int128 num = make_number(i, j);
			int tp = 0;
			for (int v : prime)
			{
				if (v >= num)
				{
					flag = false;
					break;
				}
				if (num % v == 0)
				{
					tp = v;
					break;
				}
			}
			if (!tp) flag = false;
			an[ans][j - 1] = tp;
		}
		if (flag)
		{
			ans++;
			printf("Find ans %d, total %d !", i, ans);
		}
		if (ans >= 50)
			break;
	}
	for (int i = 0; i < 50; i++)
	{
		printf("%lld", (long long)make_number(an[i][0], 10));
		for (int j = 1; j < 10; j++)
			printf(" %d", an[i][j]);
		printf("\n");
	}
	return 0;
}
