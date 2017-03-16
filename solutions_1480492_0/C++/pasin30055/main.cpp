#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define INF 1000000000
#define PA pair<int, int>
#define PA2 pair<PA, int>
#define MAX_N 8

using namespace std;

int tests;
char in[MAX_N][100];
int n,i,j,ent;
int posst;
double answer;
double s[MAX_N], p[MAX_N];
bool dp[MAX_N * MAX_N][1<<MAX_N];
double t[MAX_N * MAX_N];
int le[MAX_N];

bool inter(double s1, double e1, double s2, double e2) {
	return max(s1, s2) < min(e1, e2);
}

double eq(double xx, double yy) {
	return (xx - yy < 1e-8) and (yy - xx < 1e-8);
}

bool isvalid(double time) {
	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < n ; j ++) {
			if (i != j and le[i] == le[j]) {
				if (inter(p[i] + s[i] * time - 5, p[i] + s[i] * time, p[j] + s[j] * time - 5, p[j] + s[j] * time)) {
					return false;
				}
			}
		}
	}
	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < n ; j ++) {
			if (le[i] == le[j] and eq(p[i] + s[i] * time, p[j] + s[j] * time - 5) and s[i] > s[j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	freopen("C-small-attempt1.in", "r", stdin);
	//freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &tests);
	for (int test = 1; test <= tests ; test ++) {
		printf("Case #%d: ", test);
		scanf("%d", &n);
		posst = 0;
		for (int i = 0 ; i < n ; i ++) {
			scanf("%s %lf %lf", in[i], &s[i], &p[i]);
			posst += ((in[i][0] == 'R') * (1 << i));
		}
		t[0] = 0.0;
		ent = 1;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				if (p[i] - 5 >= p[j] and s[i] < s[j]) {
					t[ent] = (p[i] - 5 - p[j]) / (s[j] - s[i]);
					ent ++;
				} else if (p[j] - 5 >= p[i] and s[j] < s[i]) {
					t[ent] = (p[j] - 5 - p[i]) / (s[i] - s[j]);
					ent ++;
				}
			}
		}
		for (int ti = 0 ; ti < ent ; ti ++) {
			for (int pos = 0 ; pos < (1 << n) ; pos ++) {
				dp[ti][pos] = false;
			}
		}
		dp[0][posst] = true;
		sort(t, t + ent);
		answer = 0.0;
		int ti;
		for (ti = 0 ; ti < ent ; ti ++) {
			//printf("LL %d %lf\n", ti, t[ti]);
			if (ti > 0) {
				// get value from last time
				for (int pos = 0 ; pos < (1 << n) ; pos ++) {
					for (int i = 0 ; i < n ; i ++) {
						le[i] = ((pos & (1 << i)) == 0);
					}
					if (dp[ti - 1][pos] and isvalid(t[ti])) {
						//printf("XXXX\n");
						// okay
						dp[ti][pos] = true;
					}
				}
			}
			// try
			//printf("TTT1 %d %lf\n", ti, t[ti]);
			//for (int round = 0 ; round < 10 * n ; round ++) {
				for (int pos = 0 ; pos < (1 << n) ; pos ++) {
					if (dp[ti][pos]) {
					for (int i = 0 ; i < n ; i ++) {
						le[i] = ((pos & (1 << i)) == 0);
					}
					int j;
					for (j = 0 ; j < n ; j ++) {
						le[j]^=1;
						if (isvalid(t[ti])) {
							int posnew = 0;
							for (int i = 0 ; i < n ; i ++) {
								posnew += (le[i] == 1) * (1 << i);
							}
							dp[ti][posnew] = true;
							//break;
						}
						le[j]^=1;
					}
						for (int k = 0 ; k < (1 << n) ; k ++) {
							for (j = 0 ; j < (1 << n) ; j ++) {
								if ((j & (1 << k)) != 0) le[j]^=1;
							}
							if (isvalid(t[ti])) {
								int posnew = 0;
								for (int i = 0 ; i < n ; i ++) {
									posnew += (le[i] == 1) * (1 << i);
								}
								dp[ti][posnew] = true;
								//break;
							}
							for (j = 0 ; j < (1 << n) ; j ++) {
								if ((j & (1 << k)) != 0) le[j]^=1;
							}
							
						}
						/*
						int k;
						for (j = 0 ; j < n ; j ++) {
							for (k = j + 1 ; k < n ; k ++) {
								if (!inter(p[j] + s[j] * t[ti] - 5, p[j] + s[j] * t[ti], p[k] + s[k] * t[ti] - 5, p[k] + s[k] * t[ti])) {
							le[j]^=1;
								le[k]^=1;
							if (isvalid(t[ti])) {
								int posnew = 0;
								for (int i = 0 ; i < n ; i ++) {
									posnew += (le[i] == 1) * (1 << j);
								}
								dp[ti][posnew] = true;
								//break;
							}
							le[j]^=1;
								le[k]^=1;
								}
							}
						}
						 */
					//if (j != n) break;
					}
				}
			//}
			//printf("TTT2 %lf %lf\n", answer, t[ti]);
			bool chk = false;
			for (int pos = 0 ; pos < (1 << n ) ; pos ++) {
				if (dp[ti][pos]) {
					chk = true;
					//printf("DEBUG %d %d\n", ti, pos);
				}
			}
			if (!chk) break;
			answer = t[ti];
			//printf("TTT %lf %lf\n", answer, t[ti]);
		}
		if (ti == ent) {
			printf("Possible\n");
		} else {
			printf("%lf\n", t[ti]);
		}
	}
	return 0;
}