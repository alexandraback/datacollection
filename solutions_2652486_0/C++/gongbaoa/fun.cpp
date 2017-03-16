#include <cstdio>
#include <algorithm>
using namespace std;
int a[7];
int count(int x)
{
	int ret = 0;
	for (int i = 0; i < 7; ++ i)
	{
		int num = 0;
		for (int j = a[i]; j % x == 0; j /= x)
			++ num;
		ret = max(ret, num);
	}
	return ret;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	puts("Case #1:");
	for (int i = 0; i < 5; ++ i)
		scanf("%*d");
	for (int R = 0; R < 100; ++ R)
	{
		for (int i = 0; i < 7; ++ i)
			scanf("%d", &a[i]);
		int a = count(2), b = count(3), c = count(5);
		int tot = 0;
		if (a & 1)
		{
			putchar('2');
			-- a;
			++ tot;
		}
		tot += a / 2;
		for (int i = 0; i < a; i += 2)
			putchar('4');
		tot += b;
		for (int i = 0; i < b; ++ i)
			putchar('3');
		tot += c;
		for (int i = 0; i < c; ++ i)
			putchar('5');
		for (int i = tot; i < 3; ++ i)
			putchar('2');
		puts("");
	}
	return 0;
}
