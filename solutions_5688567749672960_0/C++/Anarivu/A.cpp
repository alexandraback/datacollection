#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;


int flip(int n)
{
	int res = 0;
	while (n > 0)
	{
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return res;
}

int a[20000005];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for (int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T+1);
		int n;
		scanf("%d", &n);
		queue<int> q;
		memset(a, -1, sizeof(a));
		a[1] = 1;
		q.push(1);
		while (!q.empty())
		{
			int c = q.front();
			q.pop();
			if (c == n)
				break;
			if (a[c + 1] == -1)
			{
				a[c + 1] = a[c] + 1;
				q.push(c+1);
			}
			int rev = flip(c);
			if (a[rev] == -1)
			{
				a[rev] = a[c] + 1;
				q.push(rev);
			}
		}
		printf("%d\n", a[n]);
	}

	return 0;
}