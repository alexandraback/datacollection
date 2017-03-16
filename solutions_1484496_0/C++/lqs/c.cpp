#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;
set<int> flag[2000000];

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		printf("Case #%d:\n", ca);
		int N;
		scanf("%d", &N);
		
		int a[N];
		for (int i = 0; i < N; i++)
			scanf("%d", &a[i]);
		
		
		for (int i = 0; i < 2000000; i++)
			flag[i].clear();
		
		int to = 1 << N;
		for (int bits = 1; bits < to; bits++) {
			int sum = 0;
			for (int i = 0; i < N; i++)
				if (bits & (1 << i))
					sum += a[i];
			for (set<int>::iterator it = flag[sum].begin(); it != flag[sum].end(); it++) {
				if ((bits & *it) == 0) {
					//printf("%d %d %d\n", bits, *it, sum);
					//printf("found!!!\n");
					
					for (int i = 0; i < N; i++)
						if (bits & (1 << i))
							printf("%d ", a[i]);
					putchar(10);
					
					for (int i = 0; i < N; i++)
						if (*it & (1 << i))
							printf("%d ", a[i]);
					putchar(10);
					
					
					goto done;
				}
			}
			flag[sum].insert(bits);
		}
		printf("Impossible\n");
done:;
	}
	
	
}
