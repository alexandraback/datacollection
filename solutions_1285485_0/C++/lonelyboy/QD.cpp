#include <stdio.h>
#include <map>
using namespace std;

int h, w, d;
char in[50][50];
int s[4][2], x, y;

map<int, map<int, int> > mark;

int gcd(int x, int y) {
	int c;
	
	if(x == 0) return y;
	if(y == 0) return x;
	
	while(c = x % y) {
		x = y;
		y = c;
	}
	return y;
}

int abs(int x) {
	if(x < 0) x = -x;
	return x;
}

int isOK() {
	int a = x - s[0][0], b = y - s[0][1];
	if(a == 0 && b == 0) return 0;
	int dis = a * a + b * b;
	if(dis <= 4 * d * d) {
		int c = gcd(abs(a), abs(b));
		a /= c;
		b /= c;
		if(mark[a][b] == 0) {
			//printf("%d %d %d\n", x, y, dis);
			mark[a][b] = 1;
			return 1;
		} else {
			return 0;
		}
		
	}
	return 0;
}


int f() {
	int ret = 0;
	for(int i = -50; i <= 50; ++i) {
		for(int j = -50; j <= 50; ++j) {
			for(int l = 0; l < 4; ++l) {
				x = s[l][0] + i * (h - 2) * 4;
				y = s[l][1] + j * (w - 2) * 4;
				ret += isOK();
			}
		}
	}
	return ret;
}

int solve() {
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < w; ++j) {
			if(in[i][j] == 'X') {
				s[0][0] = i * 2 - 1;
				s[0][1] = j * 2 - 1;
				
				s[1][0] = -s[0][0];
				s[1][1] = s[0][1];
				
				s[2][0] = s[0][0];
				s[2][1] = -s[0][1];
				
				s[3][0] = -s[0][0];
				s[3][1] = -s[0][1];
				mark.clear();
				return f();
			}
		}
	}
	return 0;
}

int main() {
	int t;
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		scanf("%d %d %d", &h, &w, &d);
		gets(in[0]);
		for(int i = 0; i < h; ++i) {
			gets(in[i]);
		}
		
		printf("Case #%d: %d\n", i + 1, solve());
	}
	scanf("%d");
	return 0;
}
