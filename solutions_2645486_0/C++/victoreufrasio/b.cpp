#include <stdio.h>

#define MIN(a,b) (a<b?a:b)

int v[11], N;

int max(int i, int X, int E, int R){
	int j;

	int maximum = 0;
	int current = 0;

	if(i>=N) return 0;

	for(j=0; j<=X; j++){
		current = v[i]*j + max(i+1, MIN(X - j + R,E), E, R);
		if(current > maximum) maximum = current;
	}

	return maximum;
}

int main(){
	int T, test=0;
	int E,R;
	int i;

	scanf("%d",&T);

	while(T--){
		scanf("%d %d %d", &E, &R, &N);
		
		for(i=0; i<N; i++)
			scanf("%d", &v[i]);

		printf("Case #%d: %d\n", ++test, max(0,E,E,R));
	}
}