#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count[1000];
int count2[1000];

char dic[26][100000][11];
int len[26][100000];
int size[26];

int valid[128][128];

const int R = 4;

int main() {
	char line[1000];
	FILE *fin = fopen("cdata.txt", "r");
	while (fscanf(fin, "%s", line) == 1) {
		int l = strlen(line);
		count[ line[0] ]++;
		count2[ line[0] ] += l+1;

		int t = line[0] - 'a';
		strcpy(dic[t][ size[t] ], line);
		len[t][ size[t] ] = l;
		size[t]++;
	}

	//for (int i = 0; i < 255; i++)
	//	printf("%3d%5d%9d%9d\n", i, i-97, count[i], count2[i]);

	for (int i = 'a'; i <= 'z'; i++)
		for (int j = 'a'; j <= 'z'; j++)
			valid[i][j] = -1;

	for (int i = 0; i < 26; i++) {
		for (int j = -R; j <= R; j++) {
			int a = i + 'a';
			int b = (i + j + 26) % 26 + 'a';
			valid[a][b] = 1;
		}
	}

	for (int i = 'a'; i <= 'z'; i++)
		valid[i][i] = 0;


	int ecase, ecount;
	int dp[4001];

	scanf("%d", &ecase);
	for (ecount = 1; ecount <= ecase; ecount++) {
		scanf("%s", line);
		int ll = strlen(line);
		for (int i = 0; i <= ll; i++)
			dp[i] = ll;
		dp[0] = 0;
		for (int i = 0; i < ll; i++) {
			int oa = line[i] - 'a';
			for (int j = -R; j < R; j++) {
				int b = (oa + j + 26) % 26;
				for (int k = 0; k < size[b]; k++) {
					if (i + len[b][k] <= ll) {
						int count = 0;
						int tl = len[b][k];
						int l;
						for (l = 0; l < tl; l++) {
							int t = valid[ line[i+l] ][ dic[b][k][l] ];
							if (t == -1)
								break;
							count += t;
						}
						if (l != len[b][k])
							continue;
						if (dp[i] + count < dp[i+tl])
							dp[i+tl] = dp[i] + count;
					}
				}
			}
		}
		printf("Case #%d: %d\n", ecount, dp[ll]);
	}

	return 0;
}
