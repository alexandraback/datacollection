#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

struct M {
	char s[9];
}res[2000010], bkp[2000010];

bool cmp(M a, M b) {
	return strcmp(a.s, b.s) < 0;
}

int Minrep(char *s, int l) {
	int i = 0, j = 1, k = 0, t;
	while(i < l && j < l && k < l) {
		t = s[(i + k) % l] - s[(j + k) % l];
		if(!t) ++k;
		else {
			if(t > 0) {
				i += k + 1;
			}
			else {
				j += k + 1;
			}
			if(i == j) ++j;
			k = 0;
		}
	}
	return min(i, j);
}

int main() {
	freopen("C-large.in", "r", stdin);
	fw = fopen("C_l.txt", "w");
	int i, j, k, h, tp, g = 1, cse, st, s1, s2, cnt;
	long long ans;
	char tps[50];
	for(i = 1; i <= 2000000; ++i) {
		tp = i, j = 0;
		while(tp > 0) {
			tps[j++] = (tp % 10) + '0';
			tp /= 10;
		}
		tps[j] = '\0';
		for(k = 0; k < (j >> 1); ++k) {
			swap(tps[k], tps[j - k - 1]);
		}
//		puts(tps);
		st = Minrep(tps, j);
//		printf("st=%d\n", st);
		for(k = st, h = 0; tps[k]; ++k) res[i].s[h++] = tps[k];
		for(k = 0; k < st; ++k) res[i].s[h++] = tps[k];
//		puts(res[i].s);
	}
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d %d", &s1, &s2);
		cnt = 0;
		ans = 0;
//		printf("0=%s\n", res[0].s);
		for(i = s1; i <= s2; ++i) {
//			printf("i=%d\n", i);
			bkp[cnt++] = res[i];
//			printf("~%s\n", bkp[cnt - 1].s);
		}
//		printf("cnt=%d\n", cnt);
		sort(bkp, bkp + cnt, cmp);
//		for(i = 0; i < cnt; ++i) printf("~%s\n", bkp[i].s);
//		puts("");
		tp = 1;
		for(i = 1; i < cnt; ++i) {
			if(!strcmp(bkp[i].s, bkp[i - 1].s)) {
				tp++;
			}
			else {
				ans += tp * (tp - 1) / 2;
				tp = 1;
			}
		}
		ans += tp * (tp - 1) / 2;
		fprintf(fw, "Case #%d: %lld\n", g++, ans);
	}
	fclose(fw);
	return 0;
}
