#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 64;

int n, m, d;
int sx, sy;
char matr[SIZE][SIZE];

int k;
int cx, cy;
int px, py, dx, dy;

int gcd(int a, int b) { return (b ? gcd(b, a%b) : abs(a)); }
int sign(int x) { return int(x>0) - int(x<0); }

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {

		scanf("%d%d%d", &n, &m, &d);
		for (int i = 0; i<n; i++) {
			scanf("%s", matr[i]);
			for (int j = 0; j<m; j++)
				if (matr[i][j] == 'X') {
					sx = i;
					sy = j;
				}
		}

		int ans = 0;

		for (int dx0 = -d; dx0<=d; dx0++)
			for (int dy0 = -d; dy0<=d; dy0++) {
				if (dx0 * dx0 + dy0 * dy0 > d * d) continue;
				if (dx0 == 0 && dy0 == 0) continue;
				if (gcd(dx0, dy0) > 1) continue;

                k = 2 * (dx0 ? abs(dx0) : 1) * (dy0 ? abs(dy0) : 1);
				dx = dx0;  dy = dy0;
				cx = sx;  cy = sy;
				px = k/2;  py = k/2;

				int tmax = int(d * k / sqrt(dx * dx + dy * dy + 0.0) + 1e-9);


				for (int t = 0; t<tmax; t++) {
					px += dx;
					py += dy;
					bool xbrd = (px == 0 || px == k);
					bool ybrd = (py == 0 || py == k);

					if (!xbrd && !ybrd);
					else if (xbrd && !ybrd) {
						if (matr[cx + sign(dx)][cy] == '#')
							dx = -dx;
						else {
							cx += sign(dx);
							px -= sign(dx) * k;
						}
					}
					else if (ybrd && !xbrd) {
						if (matr[cx][cy + sign(dy)] == '#')
							dy = -dy;
						else {
							cy += sign(dy);
							py -= sign(dy) * k;
						}
					}
                    else if (xbrd && ybrd) {
                    	bool passx, passy;
						if (matr[cx + sign(dx)][cy + sign(dy)] != '#') {
							passx = true;
							passy = true;
						}
						else {
							bool mirrx = (matr[cx + sign(dx)][cy] == '#');
							bool mirry = (matr[cx][cy + sign(dy)] == '#');
							if (!mirrx && !mirry)
								break;

							passx = !mirrx;
							passy = !mirry;
						}

						if (passx) {
							cx += sign(dx);
							px -= sign(dx) * k;
						}
						else dx = -dx;

						if (passy) {
							cy += sign(dy);
							py -= sign(dy) * k;
						}
						else dy = -dy;
					}

					if (cx == sx && cy == sy && px == k/2 && py == k/2) {
//						printf("Hit: (%d; %d) in D = %0.5lf\n", dx0, dy0, (t+1) * sqrt(dx*dx + dy*dy + 0.0) / k);
						ans++;
						break;
					}
                }
			}

		printf("Case #%d: %d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
