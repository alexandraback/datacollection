#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int sum[20][21];
int v[20][21];
int xl[21], yl[21];
int n, cnt;
void dfs(int left, int x, int y, int dx){
	if(left == 0){
		for(int i = 1; i <= n; i++){
			sum[yl[i]][xl[i]]++;
		}
		cnt++;
	}else{
		while(y > 0){
			if(dx != 0){
				if(v[y-1][x+dx]){
					if(v[y-1][x-1] && v[y-1][x+1])
						break;
					else if(!v[y-1][x-dx]){
						dx = -dx;
					}
				}
				y--;
				x+=dx;
			}else{
				if(v[y-1][x-1] && !v[y-1][x+1]){
					//->
					dx = 1;
					y--;
					x++;
				}else if(!v[y-1][x-1] && v[y-1][x+1]){
					//<-
					y--;
					x--;
					dx = -1;
				}else if(v[y-1][x-1] && v[y-1][x+1]){
					break;
				}else if(v[y-2][x] != 0){
					//(!v[y-1][x-1] && !v[y-1][x+1])
					dfs(left, x-1, y-1, -1);
					dfs(left, x+1, y-1, 1);
					return;
				}else{
					y--;
				}
			}
		}
		v[y][x] = 1;
		xl[left] = x;
		yl[left] = y;
		dfs(left-1, 10, 19, 0);
		v[y][x] = 0;
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int TT=1;TT<=T;TT++){
		int x, y;
		scanf("%d%d%d", &n, &x, &y);
		x+=10;
		memset(v, 0, sizeof(v));
		memset(sum, 0, sizeof(sum));
		cnt = 0;
		dfs(n, 10, 19, 0);

		double ret;
		if(x < 0 || x>=21 || y > 19)
			ret = 0;
		else
			ret = 1.0*sum[y][x]/cnt;
		printf("Case #%d: %.16lf\n", TT, ret);
	}
}

