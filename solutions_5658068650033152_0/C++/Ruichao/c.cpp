#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int t;
int n,m,k;
int ans,cur;

struct Tf{
	int x,y;
};

Tf f[200][200];


int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&t);
	f[3][3].x = 4;
	f[3][3].y = 5;
	for ( int i = 4; i <= 20; ++ i){
		f[3][i].x = f[3][i-1].x + 2;
		f[3][i].y = f[3][i-1].y + 3;
	}
	for ( int i = 4; i <= 20; ++ i){
		f[i][3].x = f[3][i].x;
		f[i][3].y = f[3][i].y;
	}
	for ( int i = 4; i <= 20; ++ i)
		for ( int j = 4; j <= 20; ++ j){
			f[i][j].x = f[i][j-1].x + 2;
			f[i][j].y = f[i][j-1].y + i;
		}

	for ( int i = 1; i <= t; ++ i){
		printf("Case #%d: ",i);
		scanf("%d%d%d",&n,&m,&k);
		if (m < n) swap(m,n);
		ans = k;
		for ( int j = 3; j <= n; j = j + 2){
			int x = 2 * j - 2;
			int y = 0;
			for ( int si = 1; si <= j; si = si + 2)
				y = y + si;
			for ( int si = j-2; si >= 1; si = si - 2)
				y = y + si;
			int ty,tx;
			for ( int si = j; si <= n; ++ si){
				ty = y;
				tx = x;
				for ( int sj = j; sj <= m; ++ sj){
					if (ty <= k && tx + k-ty < ans) ans = tx + k-ty;
					//if (si == 3 && sj == 4) cout << tx << " " << ty << " " << k << endl;
					tx = tx + 2;
					ty = ty + si;
				}
				x = x + 2;
				y = y + j;
			}
		}
		printf("%d",ans);
		printf("\n");
	}

	return 0;
}
