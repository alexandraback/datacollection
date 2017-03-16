#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Times, N;
int f[3000], num[3000], a;

int main() {

	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	scanf("%d", &Times);
	for (int times = 1; times <= Times; ++times) {
		printf("Case #%d: ", times);
		scanf("%d", &N);
		int s = (N << 1 ) - 1;
		memset(f, 0, sizeof(f));
		for (int i = 0; i < s; ++i)
			for (int j = 0; j < N; ++j) {
				scanf("%d", &a);
				f[a]++;
			}
			
		int p = 0;
		for (int i = 0; i < 2555; ++i)
			if (f[i] % 2) num[p++] = i;
		
		sort(num, num + N);
		for (int i = 0; i < N; ++i) printf("%d ", num[i]);
		printf("\n");
			
	}
	
	return 0;
}
