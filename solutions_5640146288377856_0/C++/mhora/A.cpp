// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("vstup.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	int r, c, w;
	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &r, &c, &w);
		int pocet = 0;
		int c1 = c;
		while (c1>w){
			pocet += r;
			c1 -= w;
		}
		if (c1 == w){ pocet += w + r - 1; }
		else{ pocet += w; }

		printf("Case #%d: %d\n", t, pocet);

	}
	return 0;
}

