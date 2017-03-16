//GCJ Round1A 2014-04-26 B
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

int main() {
//	freopen("in", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	fw = fopen("A-s.txt", "w");
	int cse, g = 1, a, b, gen, tp;
	bool ok;
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d/%d", &a, &b);
		ok = true;
		tp = b;
		while(tp > 1) {
			if(tp & 1) {
				ok = false;
				break;
			}
			tp = tp / 2;
		}
		if(!ok) {
			fprintf(fw, "Case #%d: impossible\n", g++);
		}
		else {
			gen = 1;
			while(a * 2 < b) {
				a = a * 2;
				gen++;
//				printf("gen=%d\n", gen);
			}
			fprintf(fw, "Case #%d: %d\n", g++, gen);
		}
	}
	fclose(fw);
	return 0;
}



