#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool pt[200][100];
double prob[21][200][100];
void precalc(int n, double p)
{
	if (n == 21) return;
	int xx, yy;
	int x, y;
	for (y = 0; ; y += 2) if (!pt[100][y]) break;
	yy = y;

	if (yy) {
		bool left = pt[100-1][yy-1], right = pt[100+1][yy-1];
		if (left && right) {
			pt[100][yy] = true;
			prob[n][100][yy] += p;
			precalc(n+1, p);
			pt[100][yy] = false;
		} else if (left) {
			int nx = 100, ny = yy;
			while (ny && !pt[nx+1][ny-1]) nx++, ny--;
			pt[nx][ny] = true;
			prob[n][nx][ny] += p;
			precalc(n+1, p);
			pt[nx][ny] = false;
		} else if (right) {
			int nx = 100, ny = yy;
			while (ny && !pt[nx-1][ny-1]) nx--, ny--;
			pt[nx][ny] = true;
			prob[n][nx][ny] += p;
			precalc(n+1, p);
			pt[nx][ny] = false;
		} else {
			int nx = 100, ny = yy;
			while (ny && !pt[nx+1][ny-1]) nx++, ny--;
			pt[nx][ny] = true;
			prob[n][nx][ny] += p*0.5;
			precalc(n+1, p*0.5);
			pt[nx][ny] = false;

			nx = 100, ny = yy;
			while (ny && !pt[nx-1][ny-1]) nx--, ny--;
			pt[nx][ny] = true;
			prob[n][nx][ny] += p*0.5;
			precalc(n+1, p*0.5);
			pt[nx][ny] = false;
		}
	} else {
		pt[100][yy] = true;
		prob[n][100][yy] += p;
		precalc(n+1, p);
		pt[100][yy] = false;
	}
}
int main()
{
	int tests;
	cin>>tests;
	precalc(1, 1.0);
	for (int n = 1; n <= 20; n++)
		for (int x = -100; x < 100; x++)
			for (int y = 0; y < 100; y++) prob[n][x+100][y] += prob[n-1][x+100][y];
	for (int test = 1; test <= tests; test++) {
		int n, x, y;
		cin>>n>>x>>y;
		if (x >= -100 && x < 100 && y < 100)
			printf ("Case #%d: %.12lf\n", test, prob[n][x+100][y]);
		else
			printf ("Case #%d: %.12lf\n", test, 0.0);
	}
	return 0;
}