#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

FILE* fw;

int main() {
//	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-large.in", "r", stdin);
	fw = fopen("B_l.txt", "w");
	int cse, i, g = 1, n, s, p, ans, cnt1, cnt2, cnt3;
	int a[110];
	scanf("%d", &cse);
	while(cse--) {
		scanf("%d %d %d", &n, &s, &p);
		for(i = 0; i < n; ++i) scanf("%d", &a[i]);
		sort(a, a + n);
		cnt1 = 0;
		for(i = 0; i < n; ++i) {
			if(a[i] >= 2) cnt1++;
		}
		if(cnt1 < s) {
			fprintf(fw, "Case #%d: 0\n", g++);
			continue;
		}
		if(!p) {
			fprintf(fw, "Case #%d: %d\n", g++, n);
			continue;
		}
		cnt1 = cnt2 = cnt3 = 0;
		for(i = 0; i < n; ++i) {
			if(a[i] >= 3 * p - 2) cnt1++;
			else {
				int tp = max(p - 2, 0);
				if(2 * tp + p > a[i]) cnt3++; //CNNOUT REACH
				else if(2 * tp + p <= a[i]) cnt2++;
			}
		}
//		printf("%d %d %d\n", cnt1, cnt2, cnt3);
		if(cnt2 < s) ans = cnt1 + cnt2;
		else
			ans = cnt1 + s;
		fprintf(fw, "Case #%d: %d\n", g++, ans);
	}
	fclose(fw);
	return 0;
}
