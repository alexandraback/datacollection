#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>

using namespace std;
int test, res, a, b, k;

void mofile(), input(), solve(), output(int t);

void mofile()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d\n", &test);
}

int main()
{
	mofile();
	for (int i = 1; i <= test; i++)
	{
		res = 0;
		input(); solve(); output(i);
	}
}

void input()
{
	scanf("%d%d%d\n", &a, &b, &k);
}

void solve()
{
	int t;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			t = i&j;
			if ((t >= 0) && (t <= k-1))
			{
				res++;
			}
		}
	}
}

void output(int t)
{
	printf("Case #%d: %d\n", t, res);
}