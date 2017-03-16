#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
#define For(i,a,b) for (int i = (a); i <= (b); i++)
#define Cor(i,a,b) for (int i = (a); i >= (b); i--)
#define rep(i,a) for (int i = 0; i < a; i++)
#define Fill(a,b) memset(a,b,sizeof(a))
int a[10];
void split(LL x)
{
	while (x)
	{
		int d = x % 10;
		x = x / 10;
		a[d] = 1;
	}
}
void solve(int task)
{
	printf("Case #%d: ", task);
	LL n;
	scanf("%lld", &n);
	if (n == 0)
	{
		printf("INSOMNIA\n");
		return;
	}
	memset(a, 0, sizeof(a));
	LL temp = n;
	while (1)
	{
		split(temp);
		bool pd = 1;
		for (int i = 0; i < 10; i++)
			if (!a[i])
			{
				pd = 0;
				break;
			}
		if (pd)
			break;
		temp = n + temp;
	}
	printf("%lld\n", temp);
}
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
}
