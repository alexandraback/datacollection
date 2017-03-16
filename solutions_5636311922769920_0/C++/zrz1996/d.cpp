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
LL a[200];
LL calc(LL K, LL C)
{
	LL ret = 0;
	LL d = 1;
	for (int i = 0; i < C; i++)
	{
		ret = ret + a[i] * d;
		d = d * K;
	}
	return ret + 1;
}
void solve(int task)
{
	printf("Case #%d: ", task);
	LL K, C, S;
	scanf("%lld%lld%lld", &K, &C, &S);
	if (C * S < K)
	{
		printf("IMPOSSIBLE\n");
		return;
	}
	int d = 0;
	set<LL> s;
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < C; j++)
		{
			a[j] = d;
			d = (d + 1) % K;
		}
		LL pos = calc(K, C);
		s.insert(pos);
	}
	for (auto i : s)
		printf(" %lld", i);
	puts("");
}
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
}
