#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <functional>
#include <cmath>

using namespace std;

#define INT_INF 987654321
#define LL_INF 987654321987654321

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef queue<int> qi;
typedef stack<int> si;


int T, ans;

int main(void)
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		printf("Case #%d: ", test, ans);
		ll B, M;
		scanf("%lld%lld", &B, &M);
		if ((1LL << (B - 2)) < M)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		if ((1LL << (B-2))  == M)
		{
			putchar('0');
			for (int i = 1; i < B; i++)
				putchar('1');
			putchar('\n');
		}
		else
		{
			putchar('0');
			long long tmp = M;
			long long div = (1LL << (B - 3));
			while (div)
			{
				if (tmp & div){
					putchar('1');
					tmp -= div;
				}
				else{
					putchar('0');
				}
				div = div >> 1;
			}
			putchar('0');
			putchar('\n');
		}

		for (int i = 1; i < B; i++)
		{
			for (int j = 0; j <= i; j++)
				putchar('0');
			for (int j = 0; j < B - i - 1; j++)
				putchar('1');
			putchar('\n');
		}
	}
}