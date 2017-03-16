#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

typedef long long lint;
typedef unsigned long long ull;

#define pb push_back
#define mp make_pair

void solve(int testNumber)
{
	lint n;
	scanf("%lld", &n);
	if (n == 0)
	{
		printf("INSOMNIA\n");
		return;
	}

	bool used[10];
	fill(used, used + 10, 0);

	lint ans = 0;
	while (true)
	{
		bool ok = true;
		for (int i = 0; i < 10 && ok; i++)
			ok = ok && used[i];
		if (ok)
			break;

		ans++;
		lint val = ans * n;
		while (val)
		{
			used[val % 10] = true;
			val /= 10;
		}
	}

	printf("%lld\n", n * ans);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tn;
	scanf("%d", &tn);
	for (int i = 0; i < tn; i++)
	{
		printf("Case #%d: ", i + 1);
		solve(i + 1);
	}
}
