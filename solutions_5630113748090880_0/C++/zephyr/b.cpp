#include <iostream>
#include <string>
using namespace std;
int N;
#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	int T;
	cin >> T;
	FILE* fout = fopen("output", "w");
	for (int t = 1; t <= T; t++) {
		int h[2501];
		for (int i = 1; i <= 2500; i++) h[i] = 0;
		scanf("%d", &N);

		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = 0; j < N; j++) {
				int tmp;
				scanf("%d", &tmp);
				h[tmp]++;
			}
		}
		
		fprintf(fout, "Case #%d:", t);
		for (int i = 1; i <= 2500; i++) {
			if (h[i] > 0 && h[i] % 2 == 1)
				fprintf(fout, " %d", i);
		}
		fprintf(fout, "\n");
	}
	return 0;
}

