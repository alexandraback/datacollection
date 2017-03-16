#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

const int IT = 200;
int used[10];
char buf[100];

void setUsed(ll x)
{
	sprintf(buf, "%lld", x);
	int len = strlen(buf);
	for (int i = 0; i < len; i++)
		used[buf[i] - '0'] = 1;
}

ll solve(ll x)
{
	memset(used, 0, sizeof(used));
	for (int i = 1; i < IT; i++)
	{
		setUsed(x * i);
		bool ok = true;
		for (int s = 0; s < 10; s++)
		{
			if (!used[s])
				ok = false;
		}
		if (ok)
			return x * i;
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		ll x;
		scanf("%lld", &x);
		ll res = solve(x);
		printf("Case #%d: ", i + 1);
		if (res == -1)
			puts("INSOMNIA");
		else
			printf("%lld\n", res);
	}
	return 0;
}
