#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXR 64

#define forn(i,n) for(int i = 0; i < n; i++)
#define forn1(i,n) for(int i = 1; i <= n; i++)

#define mp make_pair
using namespace std;
typedef pair<int, int> pii;
char map[MAXR][MAXR];
int rows, cols, mines;
int T, R, C, M;

bool reduce(int r, int c, int m){
	int mn = min(r,c);
	if(m < mn){
		int l = max(mn-2,0);
		if(m > 0 && (r==2 || c==2)) return false;
		int a = max((l*(l+1))/2, max(r,c)-2);
		if(a >= m) {
			rows = r; cols = c; mines = m;
			return true;
		}
		return false;
	}
	
	if(r > c){
		if(r==2) return false;
		return reduce(r-1, c, m - c);
	} else {
		if(c==2) return false;
		return reduce(r, c-1, m - r);
	}
		
}
void print(){
	forn(i,R){
			forn(j,C)
				printf("%c", map[i][j]);
			printf("\n");
		}
}
	
void d(int mines, int r, int c){
	if(r > c){
		while(mines){
			int aux = r;
			while(mines && aux >= 2){
				map[aux--][c] = '*';
				mines--;
			}
			c--;
		}
		return;
	}
	while(mines){
			int aux = c;
			while(mines && aux >= 2){
				map[r][aux--] = '*';
				mines--;
			}
			r--;
		}
}
int main(){
	scanf("%d",&T);
	forn1(t,T){
		memset(map,'*',sizeof(map));
		
		scanf("%d%d%d", &R, &C, &M);
		printf("Case #%d:\n",t);
		if(M == (R * C) - 1){
			map[0][0] = 'c';
			print();
			continue;
		}
		if(!reduce(R,C,M)){
			printf("Impossible\n");
			continue;
		}
		forn(i,rows)
			forn(j,cols)
				map[i][j] = '.';
		int n = 0;
		d(mines,rows-1,cols-1);
		map[0][0] = 'c';
		print();
		
		
		
	}
	
	return 0;
}

