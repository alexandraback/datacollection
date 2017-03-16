#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int T;
int n;
double a[2000], b[2000];

void work()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &a[i]);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	
	int ans1 = 0, ans2 = n;
	int now1 = 0, now2 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > b[now1])
		{
			++ans1;
			++now1;
		}
		if (b[i] > a[now2])
		{
			--ans2;
			++now2;
		}
	}
	printf("%d %d\n", ans1, ans2);
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d: ", i + 1);
		work();
	}
}
