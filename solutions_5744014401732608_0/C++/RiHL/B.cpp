#include <stdio.h>

#define ll long long

void vyres(void)
{
	int b;
	ll m;
	scanf("%d %lld", &b, &m);
	ll max=1;
	for (int i=3; i<=b && max <= 1e18 + 1; i++)
		max *= 2;

	if (max < m){
		printf("IMPOSSIBLE\n");
		return;
	}

	printf("POSSIBLE\n");

	if (max == m){
		for (int i=0; i<b; i++){
			for (int j=0; j<b; j++)
				printf("%d", (int)(j > i));

			printf("\n");
		}
	} else {
		for (int i=0; i<b; i++){
			printf("%d", (int)(i != 0 && i != b - 1));
		}
		
		printf("\n");
		for (int i=1; i<b; i++){
			for (int j=0; j<b-1; j++){
				printf("%d", (int)(j > i));
			}

			printf("%d", (int)(m % 2));
			printf("\n");
			m /= 2;
		}
	}
}

int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d: ", i + 1);
		vyres();
	}
}
