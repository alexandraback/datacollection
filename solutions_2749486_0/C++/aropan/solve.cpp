#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }


void move(int x, char l, char r)
{
	if (x < 0)
	{
		x = -x;
		swap(l, r);
	}

	while (x--)
	{
		printf("%c%c", l, r);
	}
}

int main()
{
	#ifdef MJUDGE
		assert(freopen("in", "r", stdin));
		assert(freopen("out", "w", stdout));
	#endif
	
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		int x, y;
		scanf("%d %d", &x, &y);
		move(x, 'W', 'E');
		move(y, 'S', 'N');
		printf("\n");
	}
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}
