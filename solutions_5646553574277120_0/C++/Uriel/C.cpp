#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 0x7FFFFFFF

FILE *fp, *fw;

int fg[100];

int main() {
	fp = fopen("H:\\GCJ\\150510_R1C\\C-small-attempt1.in", "r");
	//fp = fopen("H:\\GCJ\\150510_R1C\\in.txt", "r");
	fw = fopen("H:\\GCJ\\150510_R1C\\outCs.txt", "wt");
	int cse, g = 1, i, j, c, d, v, t, a[10], cnt, res, k[30];
	fscanf(fp, "%d", &cse);
	while(cse--) {
		fscanf(fp, "%d %d %d", &c, &d, &v);
		memset(fg, 0, sizeof(fg));
		fg[0] = 1;
		for(i = 0; i < d; ++i) {
			fscanf(fp, "%d", &a[i]);
			for(j = v - 1; j >= 0; --j) {
				if(fg[j]) fg[j + a[i]] = 1;
			}
		}
		cnt = 0;
		for(j = 1; j <= v; ++j) {
			if(!fg[j]) {
				cnt++;
			}
		}
		res = 0;
		for(j = 1; j <= v; ++j) {
			if(fg[j]) continue;
			res++;
			for(i = v; i >= j; --i) {
				if(!fg[i] && fg[i - j]) {
					fg[i] = 1;
				}
			}
		}
		fprintf(fw, "Case #%d: %d\n", g++, res);
	}
	fclose(fp);
	fclose(fw);
	system("PAUSE");
	return 0;
}