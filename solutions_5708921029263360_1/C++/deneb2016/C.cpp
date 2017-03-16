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
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int test = 1; test <= T; test++)
	{
		printf("Case #%d: ", test);
		int J, P, K, S;
		scanf("%d%d%d%d", &J, &P, &S, &K);
		int m = min(S, K);
		printf("%d\n", m*J*P);
		int s = 1;
		for (int i = 1; i <= J; i++)
		{
			s = i;
			for (int p = 1; p <= P; p++)
			{
				for (int y = 1; y <= m; y++)
				{
					printf("%d %d %d\n", i, p, s);
					if (s + 1 > S)
						s = 1;
					else
						s++;
				}
			}
		}
	}
}