#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct	NODE
{
	int x, y;
}	A[1005];
int N;
bool	flag1[1005], flag2[1005];

inline int	read()
{
	char ch = getchar(); int x = 0; bool flag = 0;
	for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar());
	if (ch == '-') 	{	flag = 1;	ch = getchar();	}
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	if (flag) return - x; return x;
}

bool	cmp(const NODE A, const NODE B)
{	return A.y > B.y;	}

inline void	Main()
{
	N = read();
	for (int i = 1; i <= N; ++ i)
	{
		A[i].x = read(); A[i].y = read();
		flag1[i] = flag2[i] = 0;
	}
	sort(A + 1, A + N + 1, cmp);
	int now = 0, ans = 0;
	for (int i = 1; i <= N; ++ i)
	{
		bool	Rampage = 0;
		for (int j = 1; j <= N; ++ j)
			if (!flag2[j] && A[j].y <= now)
			{
				Rampage = 1; now ++;
				if (!flag1[j]) now ++;
				flag2[j] = 1; flag1[j] = 1;
				ans ++;
				break;
			}
		if (!Rampage)
		{
			-- i;
			for (int j = 1; j <= N; ++ j)
				if (!flag1[j] && A[j].x <= now)
				{
					Rampage = 1;
					now ++;
					flag1[j] = 1;
					ans ++;
					break;
				}
			if (!Rampage)
			{
				printf("Too Bad\n");
				return;
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int T = read();
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		Main();
	}
	return 0;
}
