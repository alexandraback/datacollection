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

__int64 A, B;
vector<__int64> targets;

bool isFair(__int64 cur)
{
	__int64 num = cur, reverse = 0;
	while (num)
	{
		reverse = reverse * 10 + (num % 10);
		num /= 10;
	}
	return reverse == cur;
}

void reBuild()
{
	
	for (__int64 i = 1; i <= 10000000; i++)
	{
		if (isFair(i) && isFair(i * i))
			targets.push_back(i * i);
	}
}

void _main()
{
	scanf("%I64d%I64d", &A, &B);
	int count = 0;
	for (int i = 0; i < targets.size(); i++)
	{
		if (targets[i] >= A && targets[i] <= B)
			count++;
	}
	
	printf("%d\n", count);
}


int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("C.out", "w", stdout);

	reBuild();

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		printf("Case #%d: ", i);
		_main();
	}

}