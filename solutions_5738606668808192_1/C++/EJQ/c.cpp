#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> prime;
long long an[500][10];
bool is_prime[100000000];
char tr[128];
__int128 make_number(int k, int d)
{
	__int128 ret = 0;
	__int128 tr = 1;
	for (int i = 0; i < 32; i++)
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
	for (long long i = (1ll << 31) + 1; i < (1ll << 32); i += 2)
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
			printf("Find ans %lld, total %d !", i, ans);
		}
		if (ans >= 500)
			break;
	}
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 32; j++)
			if (an[i][0] & (1ll << j))
				tr[31 - j] = '1';
			else
				tr[31 - j] = '0';
		tr[32] = 0;
		printf("%s", tr);
		for (int j = 1; j < 10; j++)
			printf(" %lld", an[i][j]);
		printf("\n");
	}
	return 0;
}
