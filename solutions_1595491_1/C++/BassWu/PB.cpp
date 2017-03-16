#include<stdio.h>
int main()
{
	int N, S, P;
	int V;
	int T;
	scanf("%d", &T);
	for ( int t = 1 ; t <= T ; t++ ) {
		scanf("%d%d%d", &N, &S, &P);
		int count = 0;
		for ( int i = 0 ; i < N ; i++ ) {
			scanf("%d", &V);
			if ( (V+2)/3 >= P )
				count++;
			else if ( S && (V+4)/3 >= P && V >= P ) {
				S--;
				count++;
			}
		}
		printf("Case #%d: %d\n", t, count);
	}
	return 0;
}