#include <stdio.h>
#include <stdbool.h>

#define MAXC 110

void vyres(void)
{
	int K, C, S;
	scanf("%d %d %d", &K, &C, &S);
	if (C * S < K){
		printf(" IMPOSSIBLE\n");
		return;
	}

	long long mocniny[MAXC];
	mocniny[0] = 1;
	for (int i=1; i<C; i++)
		mocniny[i] = mocniny[i - 1] * K;

	long long max = mocniny[C - 1] * K;

	bool vypsano = false;
	long long cislo = 0;
	int i=0;
	for (; i<K; i++){
		int mod = i % C;
		long long nove = i * mocniny[C - mod - 1];
		if (cislo + nove >= max)
			break;

		cislo += nove;
		vypsano = false;
		if (mod == C - 1){
			printf(" %lld", cislo + 1);
			cislo = 0;
			vypsano = true;
		}
	}

	if (!vypsano)
		printf(" %lld", cislo + 1);
	printf("\n");
}


int main(void)
{
	int t;
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		printf("Case #%d:", i + 1);
		vyres();
	}
}
