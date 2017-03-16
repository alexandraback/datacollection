#include <memory.h>
#include <stdio.h>

int n, s, p;
int sum[100];

bool poss[40][2][2];

int dynamic[110][110];

inline void renew(int &x, int y) { if (x==-1 || x<y) x=y; }

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &s, &p);
		for (i=0; i<n; i++) scanf("%d", &sum[i]);
		
		memset(poss, 0, sizeof(poss));
		int a, b, c;
		for (a=0; a<=10; a++) for (b=a; b<=10 && b<=a+2; b++) for (c=b; c<=10 && c<=a+2; c++) {
			poss[a+b+c][c==a+2][c>=p] = true;
		}

		memset(dynamic, -1, sizeof(dynamic));
		dynamic[0][0] = 0;
		for (i=0; i<n; i++) {
			for (j=0; j<=s; j++) if (dynamic[i][j]!=-1) {
				if (poss[sum[i]][0][0]) renew(dynamic[i+1][j], dynamic[i][j]);
				if (poss[sum[i]][0][1]) renew(dynamic[i+1][j], dynamic[i][j]+1);
				if (poss[sum[i]][1][0]) renew(dynamic[i+1][j+1], dynamic[i][j]);
				if (poss[sum[i]][1][1]) renew(dynamic[i+1][j+1], dynamic[i][j]+1);
			}
		}

		printf("Case #%d: %d\n", ++tt, dynamic[n][s]);
	}

	return 0;
}
