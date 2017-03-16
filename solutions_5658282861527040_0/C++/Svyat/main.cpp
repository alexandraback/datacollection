#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
int a, b, k;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int id = 1; id <= t; ++id)
	{
		scanf("%d %d %d", &a, &b, &k);
		int res = 0;
		for (int i = 0; i < a; ++i)
			for (int j = 0; j < b; ++j)
				res += k > (i & j);
		printf("Case #%d: %d\n", id, res);
	}
	return 0;
}