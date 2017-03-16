#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int gcd(int a, int b) {
	while (b != 0) {
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	char a[32][32];
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		set<pair<int, int> > s;
		int H, W, D;
		scanf("%d %d %d", &H, &W, &D);
		//printf("H=%d W=%d D=%d\n", H, W, D);
		for (int y = 0; y < H; y++)
			scanf("%s", a[y]);
		int px = 0, py = 0;
		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				if (a[y][x] == 'X') {
					px = x;
					py = y;
				}
			}
		}
		int h = H-2;
		int w = W-2;
		int my = D/h+2;
		int mx = D/w+2;
		int c = 0;
		for (int y = -my; y <= my; y++) {
			for (int x = -mx; x <= mx; x++) {
				if (x == 0 && y == 0)
					continue;
				int dx, dy;
				if (x%2 == 0) dx = x*w;
				else dx = (x+1)*w - (2*px-1);
				if (y%2 == 0) dy = y*h;
				else dy = (y+1)*h - (2*py-1);
				//printf("(%d,%d) %d %d\n", x, y, dx, dy);
				if (dx*dx+dy*dy <= D*D) {
					if (dx == 0)
						dy = dy/abs(dy);
					else if (dy == 0)
						dx = dx/abs(dx);
					else {
						int g = gcd(abs(dx), abs(dy));
						dx = dx/g;
						dy = dy/g;
					}
					pair<int, int> k = make_pair(dx, dy);
					if (s.count(k) == 0) {
						//printf("%d %d\n", dx, dy);
						c++;
						s.insert(k);
					}
				}
			}
		}
		printf("Case #%d: %d\n", i+1, c);
	}
}
