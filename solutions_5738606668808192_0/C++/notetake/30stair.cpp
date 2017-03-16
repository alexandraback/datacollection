#include <cstdio>

int T, t;
int N, J;

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);

	int i, j, ii;

	scanf("%d", &T);
	for(t=1; t<=T; t++){
		printf("Case #%d:\n", t);

		scanf("%d%d", &N, &J);

		if ( N == 16 ){
			for(i=0; i<50; i++){
				printf("1");
				for(ii=i, j=0; j<7; j++){
					printf("%d%d", ii&1, ii&1);
					ii = ii >> 1;
				}
				printf("1 ");

				for(j=2; j<=10; j++) printf("%d ", j+1);
				printf("\n");
			}
		} else if ( N == 32 ){
			for(i=0; i<500; i++){
				printf("1");
				for(ii=i, j=0; j<15; j++){
					printf("%d%d", ii&1, ii&1);
					ii = ii >> 1;
				}
				printf("1 ");

				for(j=2; j<=10; j++) printf("%d ", j+1);
				printf("\n");
			}
		}
	}

	return 0;
}