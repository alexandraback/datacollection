#include <cstdio>
#include <cstring>

using namespace std;

char c[1000], c2[1000];
char t[1000];

int k, l, s;
int cnt, cnt2, cnt3;
int max = 0;

void recur(int p) {
	if (p == s) {
		cnt++;
		cnt2 = 0;
		for (int i=0; i<s-l+1; i++){
			for (int j=0; j<l; j++) {
				if (t[i+j] != c2[j]) break;
				if (j == l-1) cnt2++;
			}
		}
		cnt3 += cnt2;
		if (max < cnt2) max = cnt2;
		return;
	}
	for (int i=0; i<k; i++) {
		t[p] = c[i];
		recur(p+1);
	}
}

double run() {
	cnt = cnt3 =0;
	max = 0;
	scanf("%d %d %d", &k, &l, &s);
	scanf("%s %s", c, c2);
	recur(0);
	//printf("%d %d %d\n", max, cnt, cnt2);
	return (double)max - (double)cnt3/cnt;
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		printf("Case #%d: %.9lf\n", i, run());
	}
	return 0;
}
