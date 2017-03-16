#include<cstdio>
#include<cassert>

bool check[200][200];
long long total, count;
int N, X, Y;

bool hasLeft(int x, int y) {
	return y == 0 ? true : check[x-1][y-1];
}

bool hasRight(int x, int y) {
	return y == 0 ? true : check[x+1][y-1];
}

bool hasUnder(int x, int y) {
	return y <= 1 ? true : check[x][y-2];
}

bool stop(int x, int y) {
	return hasLeft(x, y) && hasRight(x, y) && hasUnder(x, y);
}

void backtrack(int n, int x, int y) {
	assert(x >= 0); assert(x < 200); assert(y >= 0); assert(y < 200);
	if(n == N) {
		++total;
		if(check[X][Y]) ++count;
	} else {
		while(!hasUnder(x, y)) --y;
		if(stop(x, y)) {
			check[x][y] = true;
			backtrack(n+1, 35, 199);
			check[x][y] = false;
		} else {
			if(!hasLeft(x, y)) backtrack(n, x-1, y-1);
			if(!hasRight(x, y)) backtrack(n, x+1, y-1);
		}
	}
}

int main() {
	scanf("%d%d%d",&N,&X,&Y);
	total = count = 0; X += 35;
	if(X < 0 || X >= 200 || Y < 0 || Y >= 200) { printf("%.10lf\n", 0.0); return 0; }
	backtrack(0, 35, 0);
	printf("%.10lf\n", (double) count / total);
	return 0;
}
