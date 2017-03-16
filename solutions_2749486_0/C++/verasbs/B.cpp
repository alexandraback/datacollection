#include <stdio.h>
#include <string.h>

#define MAXS 100000

char dir[] = {'W', 'E', 'N', 'S'};

int sol[MAXS], fx, fy;

void pf(int v) {
	if(v < 2) { if(fx) v = 1-v; }
	else { if(fy) v = 5-v; }
	printf("%c", dir[v]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int ca = 1; ca <= T; ca++) {
		memset(sol, 0, sizeof sol);
		int x, y, st;
		fx = 0; fy = 0;
		scanf("%d%d", &x, &y);
		if(x < 0) { x = -x; fx = 1; }
		if(y < 0) { y = -y; fy = 1; }

		int acc = 0;
		for(st = 0; acc < x+y || acc%2 != (x+y)%2; st++)
			acc += st+1;
		
		//printf("%d %d\n", st, acc);
		int pt = (acc - x - y)/2;

		int accy = 0;
		for(int i = st; i; i--) {
			if(y-accy-i < 0) continue;
			if(i == pt) continue;
			accy += i;
			sol[i] = 2;
		}
		sol[pt] = 1;
		printf("Case #%d: ", ca);
		for(int i = 1; i <= st; i++)
			pf(sol[i]);
		printf("\n");
	}
	return 0;
}
