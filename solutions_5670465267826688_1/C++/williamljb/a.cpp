#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int op[8][8] =
{
	{0,1,2,3,4,5,6,7},
	{1,4,3,6,5,0,7,2},
	{2,7,4,1,6,3,0,5},
	{3,2,5,4,7,6,1,0},
	{4,5,6,7,0,1,2,3},
	{5,0,7,2,1,4,3,6},
	{6,3,0,5,2,7,4,1},
	{7,6,1,0,3,2,5,4}
};
int n, ans, sum, a[10010];
long long m;
char ch;

int find(int k, int pos)
{
	int sum = 0;
	for (int i = 0; i < 8*n; ++i)
	{
		sum = op[sum][a[i%n]];
		if (sum == k && i > pos)
			return i;
	}
	return -1;
}

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int times;
	scanf("%d", &times);
	for (int i = 1; i <= times; ++i)
	{
		printf("Case #%d: ", i);
		cin >> n >> m;
		scanf("%c", &ch);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%c", &ch);
			//printf("%c", ch);
			a[i] = ch - 'i' + 1;
			sum = op[sum][a[i]];
		}
		int tmp = 0;
		for (int i = 0; i < m % 4; ++i)
			tmp = op[tmp][sum];
		if (tmp != 4)
		{
			printf("NO\n");
			continue;
		}
		int pos = find(1, -1);
		if (pos == -1)
		{
			printf("NO\n");
			continue;
		}
		pos = find(3, pos);
		if (pos == -1)
		{
			printf("NO\n");
			continue;
		}
		if (pos > (long long)n * m)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}