#include <stdio.h>

#define R 60

char str[R][R];
int pass[R][R];
int t,r,c,m;
int di[8][2] = {{1,1},{1,0},{1,-1},{0,-1},{0,1},{-1,1},{-1,0},{-1,-1}};
bool f;

int val(int a,int b) {
	if(a < 0 || b < 0 || a >= r || b >= c || pass[a][b] || str[a][b] == '*') {
		return 0;
	}
	pass[a][b] = 1;
	int ans = 1;
	for(int i=0;i<8;i++) {
		int na = a + di[i][0],nb = b + di[i][1];
		if(na < 0 || nb < 0 || na >= r || nb >= c) {
			continue;
		}
		if(str[na][nb] == '*') {
			return 1;
		}
	}
	for(int i=0;i<8;i++) {
		int na = a + di[i][0],nb = b + di[i][1];
		ans += val(na,nb);
	}
	return ans;
}
void dfs(int a,int b,int k,int ci,int cj) {
	if(a >= r) {
		if(ci == -1) return;
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				pass[i][j] = 0;
			}
		}
		if(val(ci,cj) == r*c-m) {
			f = true;	
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					printf("%c",str[i][j]);
				}
				printf("\n");
			}
		}
		return;
	}
	if(f) return;
	if(k < r*c-m) {
		str[a][b] = '.';
		dfs(a + (b == c-1),b == c-1?0:b+1,k+1,ci,cj);
		if(ci == -1) {
			str[a][b] = 'c';
			dfs(a + (b == c-1),b == c-1?0:b+1,k+1,a,b);
		}
	}
	str[a][b] = '*';
	dfs(a + (b == c-1),b == c-1?0:b+1,k,ci,cj);
}
int main() {
	scanf("%d",&t);
	for(int Case = 1; Case <= t;Case++) {
		scanf("%d%d%d",&r,&c,&m);
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				str[i][j] = '*';
				pass[i][j] = 0;
			}
		}
		f = false;
		printf("Case #%d:\n",Case);
		dfs(0,0,0,-1,-1);
		if(f == false) {
			printf("Impossible\n");
		}
	}
	return 0;
}
