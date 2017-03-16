#include<iostream>
#include<string>
using namespace std;

typedef struct stu{
	int like;
	bool proc;
} stu;
stu st[1000];

int mt, maxt, N;

void findlong(int s, int p) {
	mt++;
	if (mt > maxt)maxt = mt;
	for (int i = 0; i < N; i++) {
		if (st[i].like == p&&i != s) {
			st[i].proc = true;
			findlong(p, i);
		}
	}
	mt--;
}

int main() {
	FILE *fpi, *fpo;
	fpi = fopen("C-large.in", "r");
	fpo = fopen("largeC.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	for (int co = 1; co <= re; co++) {
		fscanf(fpi, "%d", &N);
		for (int i = 0; i < N; i++) {
			fscanf(fpi, "%d", &st[i].like);
			st[i].like--;
			st[i].proc = false;
		}
		int a[1000], t=0;
		int maxcir = 0, maxlink = 0;
		for (int i = 0; i < N;i++) {
			int s = i; t = 0;
			if (st[s].proc)continue;
			while (1) {
				a[t++] = s;
				st[s].proc = true;
				int p = st[s].like;
				if (st[p].proc) {
					int j;
					for (j = 0; j < t; j++) {
						if (a[j] == p) {
							break;
						}
					}
					if (j<t&&st[a[j]].like==s) {
						mt = maxt = 0;
						findlong(s, p);
						int mt1 = maxt;
						mt = maxt = 0;
						findlong(p, s);
						int mt2 = maxt;
						maxlink += mt1 + mt2;
					}
					else if (j < t) {
						int cir = t - j;
						if (cir > maxcir)maxcir = cir;
					}
					break;
				}
				else{
					s = p;
				}
			}
		}
		fprintf(fpo, "Case #%d: %d\n", co, maxcir>maxlink?maxcir:maxlink);

	}
	fclose(fpi);
	fclose(fpo);
}