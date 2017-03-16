#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int record[10];
int nrec;

int main(){
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ttt++){
		fprintf(stderr, "case %d/%d\n", ttt, T);
		int A, B;
		scanf("%d%d", &A, &B);
		int res = 0;
		int percent_prev = 0;
		for (int n = A ; n <= B; n++){
			int percent = (int)(100.0f * (n-A) / (B-A));
			if (percent != percent_prev){
				fprintf(stderr, "%d%%\n", percent);
				percent_prev = percent;
			}
			nrec = 0;
			int l = n, r = 0, p = 1;
			int q = 10;
			while (q <= n) q *= 10;
			q /= 10;
			while (l > 10){
				r += l % 10 * p;
				p *= 10;
				l /= 10;
				int m = r * q + l;
				q /= 10;
				if (m <= B && n < m) {
					int flag = 0;
					for (int i = 0; i < nrec; ++i){
						if (record[i] == m){
							flag = 1;
							break;
						}
					}
					if (!flag)
						res++, record[nrec++] = m;
				}
			}
		}
		printf("Case #%d: %d\n", ttt, res);
	}
	return 0;
}