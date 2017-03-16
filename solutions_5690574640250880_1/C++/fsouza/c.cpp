#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXRC 50

typedef long long lint;

using namespace std;

char result[MAXRC][MAXRC];

int main(int argc, char ** argv)
{
#if 0
	for (int r = 3; r <= 50; r++)
		for (int c = r; c <= 50; c++)
			for (int x = 4; x < r*c; x++) {

				if (x == 5 || x == 7) continue;
				if (r == c && x == (r-1)*(r-1)+r) continue;

				bool ok = false;
				
				if (r > c) {
					for (int a = 2; a <= r; a++) {
						int b = (x+a-1)/a;
						if (1 < x/a && b <= c && x%a != 1)
							ok = true;
					}
				} else {
				
					for (int b = 2; b <= c; b++) {
						int a = (x+b-1)/b;
						if (1 < x/b && a <= r && x%b != 1)
							ok = true;
					}
				}

				if (!ok)
					printf("fail for %d %d %d\n", r, c, x);
			}

	return 0;
#endif
	int nt;

	scanf("%d", &nt);

	for (int t = 0; t < nt; t++) {
		int r, c, m;
		bool ok;

		scanf("%d %d %d", &r, &c, &m);
		int ndot = r*c - m;

		if (r == 1 || c == 1 || ndot == 1 || m == 0) {
			int id = 0;
			for (int y = 0; y < r; y++)
				for (int x = 0; x < c; x++) {
					if (id == 0) result[y][x] = 'c';
					else if (id < ndot) result[y][x] = '.';
					else result[y][x] = '*';
					id++;
				}
			ok = true;
		} else if (ndot == 2 || ndot == 3 || ndot == 5 || ndot == 7 || ((r == 2 || c == 2) && ndot%2 == 1))
			ok = false;
		else if (r == c && ndot == (r-1)*(r-1) + r) {
			const int s = r;

			for (int y = 0; y < s; y++)
				for (int x = 0; x < s; x++)
					result[y][x] = '*';
			
			for (int y = 0; y < s-1; y++)
				for (int x = 0; x < s-1; x++)
					result[y][x] = '.';
			
			for (int y = 0; y < r/2; y++) result[y][s-1] = '.';
			for (int x = 0; x < (r+1)/2; x++) result[s-1][x] = '.';
			
			result[0][0] = 'c';
			ok = true;
		} else {
			bool change = c < r;
			if (change) swap(r, c);

			for (int y = 0; y < r; y++)
				for (int x = 0; x < c; x++)
					result[y][x] = '*';

			for (int b = 2; b <= c; b++)
				if (1 < ndot/b && (ndot+b-1)/b <= r && ndot%b != 1) {
					int id = 0;
					for (int y = 0; y < r; y++)
						for (int x = 0; x < b; x++) {
							if (id == 0) result[y][x] = 'c';
							else if (id < ndot) result[y][x] = '.';
							id++;
						}
					break;
				}

			if (change) {
				for (int y = 0; y < max(r, c); y++)
					for (int x = 0; x < y; x++)
						swap(result[y][x], result[x][y]);
				swap(r, c);
			}
			ok = true;
		}

		printf("Case #%d:\n", t+1);

		if (ok) {
			for (int y = 0; y < r; y++) {
				for (int x = 0; x < c; x++)
					printf("%c", result[y][x]);
				printf("\n");
			}
		} else
			printf("Impossible\n");
	}

	return 0;
}
