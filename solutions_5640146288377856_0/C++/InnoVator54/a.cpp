#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int calc(int x, int r)
{
	if(x <= r)
		return x;
	return max(calc(x - r, r), r) + 1;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	int ca = 0;
	scanf("%d", &T);
	while(T--)
	{
		int r, c, w;
		scanf("%d%d%d", &r, &c, &w);
		printf("Case #%d: %d\n", ++ca, calc(c, w));
	}
	return 0;
}