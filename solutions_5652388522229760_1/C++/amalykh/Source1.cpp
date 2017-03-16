#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:134217728")
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <ctime>

typedef long long ll;

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ZERO(x) memset((x), 0, sizeof(x))

using namespace std;

void markDigits(ll n, vector<char>& c)
{
	while (n > 0)
	{
		c[n % 10] = 1;
		n /= 10;
	}
}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//cout << 10000 << endl;
	//for (int i = 1e6; i > 1e6 - 10000; i--)
	//{
	//	cout << i << endl;
	//}
	//return 0;

	int t;
	scanf("%d", &t);
	for (int w = 0; w < t; w++)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", w + 1);
		if (n == 0)
		{
			printf("INSOMNIA\n");
			continue;
		}
		vector<char> was(10, 0);
		ll q = n;
		markDigits(q, was);
		while (*min_element(was.begin(), was.end()) != 1)
		{
			q += n;
			markDigits(q, was);
		}
		printf("%lld\n", q);
	}

	return 0;
}