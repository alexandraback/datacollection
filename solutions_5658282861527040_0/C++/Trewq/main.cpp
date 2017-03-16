#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<memory.h>
#include<ctime>
#include<unordered_set>
using namespace std;
char cc[100];
int countcc;
int cnt[100][100];
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for (int cs = 1; cs <= tc; cs++)
	{
		int a, b, k;
		int count = 0;
		scanf("%d %d %d", &a, &b, &k);
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				if ((i&j) < k)
					count++;
			}
		}
		printf("Case #%d: ", cs);
		printf("%d\n", count);
	}
	return 0;
}