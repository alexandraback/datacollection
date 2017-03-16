#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int A, B;

bool isFair(int cur)
{
	int another = 0;
	int now = cur;
	while (now)
	{
		another *= 10;
		another += (now % 10);
		now /= 10;
	}
	return another == cur;
}

bool isSquare(int cur)
{
	for (int i = 1; i * i <= cur; i++)
	{
		if (i * i == cur)
			return isFair(i);
	}
	return false;
}
void _main()
{
	scanf("%d%d", &A, &B);
	int count = 0;
	for (int cur = A; cur <= B; cur++)
	{
		if (isFair(cur) && isSquare(cur))
			count++;
	}
	printf("%d\n", count);
}
int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		printf("Case #%d: ", i);
		_main();
	}

}