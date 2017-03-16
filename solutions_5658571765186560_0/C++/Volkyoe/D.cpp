#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
#include"set";
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
int t, T, R, C;
int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
set<VVI> S[10];
void print(bool ans) {
	printf("Case #%d: %s\n", ++t, ans? "GABRIEL": "RICHARD");
}
void show(int Size) {
	printf("-- SHOW FIG SIZE = %d --\n", Size);
	for (const VVI& f: S[Size]) {
		printf("[%d, %d]\n", f.size(), f[0].size());
		for (int i = 0; i < f.size(); i++, printf("\n"))
			for (int j = 0; j < f[i].size(); j++)
				printf("%d", f[i][j]);
		printf("\n");
	}
	printf("----- TOTAL = %3d -----\n", S[Size].size());
}
bool isOK(int i, int j, int R, int C) {
	return 0 <= i && i < R && 0 <= j && j < C;
}
bool isAdj(const VVI& f, int i, int j) {
	int R = f.size(), C = f[0].size();
	int adj = 0;
	for (int k = 0; k < 4; k++) {
		int nI = i + di[k], nJ = j + dj[k];
		if (isOK(nI, nJ, R, C))
			adj += f[nI][nJ];
	}
	return adj > 0 && !(isOK(i, j, R, C) && f[i][j] == 1);
}
VVI normalize(const VVI& f, int x, int y) {
	int R = f.size(), C = f[0].size();
	int dR = (x == -1), dC = (y == -1);
	if (x == -1 || x == R) R++;
	if (y == -1 || y == C) C++;
	VVI g(R, VI(C, 0));
	for (int i = 0; i < f.size(); i++)
		for (int j = 0; j < f[i].size(); j++)
			g[i+dR][j+dC] = f[i][j];
	g[x+dR][y+dC] = 1;
	return g;
}
VVI rotate(const VVI& g) {
	int R = g.size(), C = g[0].size();
	VVI f(C, VI(R, 0));
	for (int i = 0; i < C; i++)
		for (int j = 0; j < R; j++)
			f[i][j] = g[R-j-1][i];
	return f;
}
void check(const VVI& g, int Size, int x, int y) {
	int R = g.size(), C = g[0].size(), count = 0;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			count += g[i][j];
	if (count != Size) printf("BUG %d [%d %d]\n", Size, x, y);
}
void generate(int Size) {
	if (Size < 1) return;
	if (Size == 1) {
		S[1].insert(VVI(1, VI(1, 1)));
		//show(1);
		return;
	}
	generate(Size-1);
	for (const VVI& f: S[Size-1]) {
		for (int i = -1; i < R + 1; i++) {
			for (int j = -1; j < C + 1; j++) {
				if (!isAdj(f, i, j)) continue;
				//check(f, Size-1, i, j);
				VVI g = normalize(f, i, j);
				//check(g, Size, i, j);
				for (int k = 0; k < 4; k++) {
					S[Size].insert(g);
					g = rotate(g);
				}
			}
		}
	}
	//show(Size);
}
int main() {
	//generate(6);
	//show(6);
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.txt", "w", stdout);
	scanf("%d", &T);
	while (t < T) {
		int X;
		scanf("%d%d%d", &X, &R, &C);
		if (X > max(R, C) || X > min(R, C) * 2 || R * C % X != 0 || X >= 7)
			print(0);
		else if (R == 1 || C == 1 || X < min(R, C) * 2 - 1)
			print(1);
		else
			print(X % 2);
	}
}
