#include <stdio.h>
#include <algorithm>

#define MaxN 100

int T, A, N;
int size[MaxN+1];

int main(void){
	int t;
	int i, p;
	int min, cnt;

	scanf("%d", &T);
	for (t=1; t<=T; t++){
		scanf("%d%d", &A, &N);
		for (i=0; i<N; i++) scanf("%d", &size[i]);

		std::sort(size, size+N);

		if (A==1){
			printf("Case #%d: %d\n", t, N);
			continue;
		}

		p = 0;
		while (p<N && A>size[p]) A += size[p++];

		min = N-p; cnt = 0;
		for (; p<N; p++){
			while (A<=size[p]){
				A += A-1;
				cnt ++;
			}
			A += size[p];
			if (min > cnt+N-p-1)
				min = cnt+N-p-1;
		}
		printf("Case #%d: %d\n", t, min);
	}
	return 0;
}

