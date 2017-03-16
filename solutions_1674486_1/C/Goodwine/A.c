/*
 * A.c
 *
 *  Created on: May 6, 2012
 *      Author: goodwine
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int m[1005][1005];
int v[1005];

int diamond(int n, int x){
	int i, y;
	v[x] = 1;
	for (i = 1; i <= n; i++) {
		if(i == x)
			continue;
		if(m[x][i] == 1) {
			if(v[i] == 1)
				return 1;
			else {
				v[i] = 1;
				y = diamond(n,i);
				if(y == 1)
					return 1;
			}
		}
	}
	return 0;
};

int main() {
	int t,_,n,i,j,x,y;
	scanf("%d", &t);
	for(_ = 1; _ <= t; _++){
		scanf("%d", &n);
		memset(m,0,sizeof(m));
		memset(v,0,sizeof(v));
		for(i = 0; i < n;i++){
			scanf("%i",&x);
			for(j = 0; j < x;j++){
				scanf("%i",&y);
				m[y][i+1] = 1;
			}
		}
		x = 0;
		for(i = 1; i <= n;i++){
			memset(v,0,sizeof(v));
			if(diamond(n,i) == 1){
				x = 1;
				break;
			}
		}
		if(x == 1)
			printf("Case #%d: Yes\n", _);
		else
			printf("Case #%d: No\n", _);
	}
	return 0;
}
