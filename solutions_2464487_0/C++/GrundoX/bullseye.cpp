#include <cstdio>

int round;

int main(){
	scanf("%d", &round);
	for(int x = 1; x <= round; x++){
		int r, t;
		scanf("%d %d", &r, &t);
		int rings = 0;
		int at = r+1;
		int val = at*at-((at-1)*(at-1));
		while(val <= t){
			rings++;
			t -= val;
			at += 2;
			val = at*at-((at-1)*(at-1));
		}
		printf("Case #%d: %d\n", x, rings);
	}
	return 0;
}	

