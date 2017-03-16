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
const int maxn = 110;
char c[maxn];
void solve(int task)
{
	printf("Case #%d: ", task);
	scanf("%s", c);
	int n = strlen(c);
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		if (c[i] != c[i + 1])
			ans++;
	if (c[n - 1] == '-')
		ans++;
	printf("%d\n", ans);
}
int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
		solve(i);
}
