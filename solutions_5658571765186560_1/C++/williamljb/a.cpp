#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int x,r,c;
long long m;
char ch;
const char win[10] = "GABRIEL\n", lose[10] = "RICHARD\n";

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		scanf("%d%d%d", &x, &r, &c);
		if (r*c % x != 0 || x >= 7)
		{
			printf(lose);
			continue;
		}
		if (x <= 2)
		{
			printf(win);
			continue;
		}
		if (x == 3)
		{
			if (r == 1 || c == 1)
				printf(lose);
			else
				printf(win);
			continue;
		}
		if (x == 5)
		{
			if (r <= 2 || c <= 2)
				printf(lose);
			else
				printf(win);
			continue;
		}
		if (x == 4)
		{
			if (r <= 2 || c <= 2)
				printf(lose);
			else
				printf(win);
			continue;
		}
		if (r <= 3 || c <= 3)
			printf(lose);
		else
			if (r < 6 && c < 6)
				printf(lose);
			else
				printf(win);
	}
	return 0;
}