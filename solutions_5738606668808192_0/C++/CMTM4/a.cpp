#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

#define LL long long
void nextInt(int &x)
{
	scanf("%d", &x);
}
void nextInt(int &x, int &y)
{
	scanf("%d%d", &x, &y);
}

int n, j;
LL qz;

void init()
{
	nextInt(n, j);
	qz = 1;
	qz |= (1 << (n - 1));
}


int f[2000];
int output[1000];

bool check(long long arg)
{
	bitset<60> a = arg;
	for (int jinzhi = 2; jinzhi <= 10; ++ jinzhi)
	{
		memset(f, 0, sizeof(f));
		for (int i = n - 1; i >= 0; -- i)
		{
			for (int j = 2; j <= 1000; ++ j)
			{
				if (a[i] == 0)
				{
					f[j] = (f[j] * jinzhi) % j;
				}
				else 
				{
					f[j] = (f[j] * jinzhi + 1) % j;
				}
			}
		}
		for (int i = 2; i <= 1000; ++ i)
			if (f[i] == 0)
			{
				output[jinzhi] = i;
				goto here;
			}
		//没有执行到break?
		return false;//arg在jinzhi的进制下，是素数
		here:;
	}
	for (int i = n - 1; i >= 0; -- i)	printf("%d", a[i] == 1);
	printf(" ");
	for (int i = 2; i <= 9; ++ i)	printf("%d ", output[i]);
	printf("%d\n", output[10]);
	return true;
}

void doit()
{
	int ans = 0;
	for (LL i = 0; i < (1 << (n - 2)); ++ i)
	{
		if (check((i << 1LL) | qz))	++ ans;
		if (ans == j)	break;
	}
}


int main()
{
	//freopen("a.in","r",stdin);
	freopen("a.txt","w",stdout);
	LL sb;
	scanf("%lld", &sb);
	for (int i = 1; i <= sb; ++ i)
	{
		printf("Case #%d:\n", i);
		init();
		doit();
	}
	return 0;
}
