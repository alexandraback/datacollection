#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:268435456")

#include <cstdio>
#include <iostream>
using namespace std;

int p[12];

int a, b;
int len;

int cnt[2000010];
int xxx[2000010];

void process(int x)
{
	int y = x;
	for (int shift = 1; shift < len; shift++)
	{
		int digit = y % 10;
		y /= 10;
		y += digit * p[len-1];
		if (digit != 0)
		{
			if (a <= y && y <= b && x < y && xxx[y] != x)
			{
				cnt[x]++;
				xxx[y] = x;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	p[0] = 1;
	for (int i = 1; i <= 9; i++)
		p[i] = p[i-1] * 10;

	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; test++)
	{
		cin >> a >> b;
		len = 0;
		for (int i = a; i > 0; i /= 10)
			len++;
		memset(cnt, 0, sizeof(cnt));
		memset(xxx, 0, sizeof(xxx));
		for (int i = a; i <= b; i++)
			process(i);
		long long ans = 0;
		for (int i = a; i <= b; i++)
			ans += cnt[i];
		printf("Case #%d: %I64d\n", test, ans);
	}

	return 0;
}