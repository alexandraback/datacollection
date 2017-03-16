#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		int X, R, C;
		scanf("%d %d %d", &X, &R, &C);
		if (R > C) swap(R, C);
		
		if (X == 1) { puts("GABRIEL"); continue; }
		if (X == 2)
		{
			if (R * C % 2 == 0) puts("GABRIEL"); else puts("RICHARD");
			continue;
		}
		if (X == 3)
		{
			if (R >= 2 && R * C % 3 == 0) puts("GABRIEL"); else puts("RICHARD");
			continue;
		}
		if (R >= 3 && C >= 4 && R * C % 4 == 0) puts("GABRIEL"); else puts("RICHARD");
	}
	return 0;
}