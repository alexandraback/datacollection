#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 0x7FFFFFFF

FILE *fp, *fw;

int main() {
	fp = fopen("H:\\GCJ\\150510_R1C\\A-small-attempt1.in", "r");
	//fp = fopen("H:\\GCJ\\150510_R1C\\in.txt", "r");
	fw = fopen("H:\\GCJ\\150510_R1C\\outAs.txt", "wt");
	int cse, g = 1, r, c, w, t;
	fscanf(fp, "%d", &cse);
	while(cse--) {
		fscanf(fp, "%d %d %d", &r, &c, &w);
		t = (c + 1 - w) / w;
		if((c + 1 - w) % w) t++;
		t *= r;
		if(((c + 1 - w) % w) == 1 || w == 1) t--;
		t += w;
		fprintf(fw, "Case #%d: %d\n", g++, t);
	}
	fclose(fp);
	fclose(fw);
	system("PAUSE");
	return 0;
}