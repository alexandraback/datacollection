#include<iostream>
using namespace std;

char field[64][64];

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={0,-1,1,-1,1,-1,0,1};
bool done[64][64];
int mines[64][64];


void rec(int n, int m, int x, int y) {
	done[x][y] = true;
	int cnt = 0;
	for(int d=0;d<8;d++) {
		int xx = x + dx[d];
		int yy = y + dy[d];
		if (xx>=0 && yy>=0 && xx<n && yy<m && field[xx][yy]=='*') {
			cnt++;
		}
	}
	mines[x][y] = cnt;
	if (!cnt) {
		for(int d=0;d<8;d++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (xx>=0 && yy>=0 && xx<n && yy<m && field[xx][yy]=='.' && !done[xx][yy]) {
				rec(n, m, xx, yy);
			}
		}
	}
}

bool check(int n, int m, int x, int y) {
	memset(done, 0, sizeof(done));
	rec(n, m, x, y);
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if (field[i][j]=='.' && !done[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int bitcount(int n) {
	if (n==0)return 0;
	return (n&1) + bitcount(n>>1);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tcs;
	cin >> tcs;
	int tc=0;
	while (tcs--) {
		tc++;
		int n, m, k;
		cin >> n >> m >> k;
		printf("Case #%d:\n", tc);
		memset(field, 0, sizeof(field));
		bool ok = false;
		for(int msk=0;msk<(1<<(n*m));msk++) {
			if (bitcount(msk)!=k) {
				continue;
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					int idx = i*m+j;
					if (msk&(1<<idx)) {
						field[i][j] = '*';
					} else {
						field[i][j] = '.';
					}
				}
			}
			for(int i=0;i<n;i++) {
				for(int j=0;j<m;j++) {
					if (field[i][j]=='*')continue;
					if (check(n, m, i, j)) {
						field[i][j] = 'c';
						ok = true;
						goto l1;
					}
				}
			}
l1:;
			if (!ok) {
				continue;
			} else {
				goto l2;
			}
		}
		l2:;
		if (ok) {
			int x=-1,y=-1;
			for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(field[i][j]=='c'){ 
				x=i;
				y=j;
			}
			for(int i=0;i<n;i++) {
				printf("%s\n", field[i]);
			}
			fflush(stdout);
			check(n, m, x, y);
		} else {
			printf("Impossible\n");
		}
	}


	return 0;
}