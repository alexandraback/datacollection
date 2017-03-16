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
	
//	srand(time(NULL));
	
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		int x, y;
		scanf("%d %d", &x, &y);
//		x = ((rand() << 15) ^ rand()) % 1000000 - 2000000;
//		y = ((rand() << 15) ^ rand()) % 1000000 - 2000000;
		int ans = 1;
		do
		{
			int s = ans * (ans + 1) / 2;
			if ((s & 1) == ((x + y) & 1) && s >= (abs(x) + abs(y)))
				break;
		} while (++ans);
		
		string s;
		s.reserve(ans);
		for (int i = ans; i >= 1; i--)
		{
			if (abs(x) > abs(y))
			{
				if (x < 0) s += 'W', x += i;
				else s += 'E', x -= i;
			} else {
				if (y < 0) s += 'S', y += i;
				else s += 'N', y -= i;
			}
		}
		
		assert(x == 0 && y == 0);
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
	fprintf(stderr, "Time execute: %.3lfs\n", clock() / (double)CLOCKS_PER_SEC);
	return 0;
}
