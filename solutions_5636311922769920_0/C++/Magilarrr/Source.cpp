#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cstring>
#include <bitset>
using namespace std;
int k, c, s;
int main()
{
	int test;
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d\n", &test);
	for (int t = 1; t <= test; t++)
	{
		scanf("%d %d %d\n", &k, &c, &s);
		printf("Case #%d:", t);
		for (int i = 1; i <= k; i++)
			printf(" %d", i);
		printf("\n");

	}
	return 0;
}