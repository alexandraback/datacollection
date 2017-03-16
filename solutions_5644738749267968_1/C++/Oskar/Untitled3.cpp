#include <cstdio>
#include <algorithm>

int t, n;
double l[2][2002];

int main(){
	freopen("gg.txt", "w", stdout);
	freopen("D-large.in", "r", stdin);
	scanf("%d", &t);
	for(int z = 1; z <= t; z++){
		int x = 0, y = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%lf", &l[0][i]);
		for(int i = 0; i < n; i++) scanf("%lf", &l[1][i]);
		std::sort(l[0], l[0] + n);
		std::sort(l[1], l[1] + n);
		int i = 0, j = 0;
		while(i < n){
			if(l[0][i] > l[1][y]) y++;
			i++;
		}
		i = 0;
		while(j < n){
			if(l[0][i] > l[1][j++]) x++;
			else i++;
		}
		printf("Case #%d: %d %d\n", z,  y, x);
	}
	
	scanf("\n");
}
