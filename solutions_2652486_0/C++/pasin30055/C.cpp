#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>

#define PA pair<lld, lld>

#define MAX_N 100000

using namespace std;

typedef long long lld;

int tests;
int dig[MAX_N];
int prod[MAX_N];
int cou[MAX_N];
int answer[MAX_N];
int r, m, n, k, l;
long double prob, probtmp;

int main() {
	scanf("%d", &tests);
	scanf("%d %d %d %d", &r, &n, &m, &k);
	for (int test = 0 ; test < tests ; test ++) {
		printf("Case #%d: \n", test + 1);
		for (int ttt = 0 ; ttt < r ; ttt ++) {
			for (int i = 0 ; i < k ; i ++) scanf("%d", &prod[i]);
			prob = 0.0;
			l = n - 1;
			for (int j = 0 ; j < n ; j ++) {
				dig[j] = 2;
			}
			dig[n - 1] = 1;
			while (1) {
				while (l >= 0 and dig[l] == m) l --;
				if (l < 0) {
					break;
				} else {
					dig[l] ++;
					for (int j = l + 1 ; j < n ; j ++) dig[j] = dig[l];
					l = n - 1;
				}
				for (int j = 0 ; j < n - 1 ; j ++) {
					if (dig[j] > dig[j + 1]) continue;
				}
				for (int o = 0 ; o < k ; o ++) cou[o] = 0;
				for (int j = 0 ; j < (1 << n) ; j ++) {
					int pro = 1;
					//printf("%dT", l);
					for (int o = 0 ; o < n ; o ++) {
						//printf("%d", dig[o]);
						if (((1 << o)&j) != 0) pro *= dig[o];
					}
					//printf("\n");
					for (int o = 0 ; o < k ; o ++) {
						if (pro == prod[o]) cou[o] ++;
					}
				}
				probtmp = 1.0;
				for (int o = 0 ; o < k ; o ++) probtmp *= cou[o];
				//for (int o = 0 ; o < k ; o ++) probtmp += cou[o];
				if (probtmp > prob) {
					prob = probtmp;
					for (int o = 0 ; o < n ; o ++) answer[o] = dig[o];
				}
			}
			for (int i = 0 ; i < n ; i ++) printf("%d", answer[i]);
			printf("\n");
		}
	}
	return 0;
}