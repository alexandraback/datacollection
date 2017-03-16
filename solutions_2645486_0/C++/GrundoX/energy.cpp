#include <cstdio>

#define min(x,y)(((x)<(y))?(x):(y))
#define max(x,y)(((x)>(y))?(x):(y))

int e, r, n, ls[15], best;

void calc(int pos, int val, int en){
	if(pos == n-1){
//		printf("HERE %d %d\n", best, val+en*ls[pos]);
		best = max(best, val+en*ls[pos]);
	}
	else{
		for(int i = 0; i <= en; i++){
			calc(pos+1, val+(i*ls[pos]), min(en-i+r, e));
		}
	}
}

int main(){
	int rounds;
	scanf("%d", &rounds);
	for(int x = 1; x <= rounds; x++){
		best = -1;
		scanf("%d %d %d", &e, &r, &n);
		for(int i = 0; i < n; i++) scanf("%d", &ls[i]);
		calc(0, 0, e);
		printf("Case #%d: %d\n", x, best);
	}
	return 0;
}

