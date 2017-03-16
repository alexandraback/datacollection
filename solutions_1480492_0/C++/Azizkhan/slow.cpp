#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std; 

#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define forit(it,S) for(__typeof(S.begin()) it = S.begin(); it != S.end(); ++it)

typedef pair <int, int> pi;
typedef pair <double, pi> pdi;

const double eps = 1e-9;
const double inf = int(1e9);
char c[111];
int s[111];
int p[111], en, n;
int lane[111];
pdi e[11111];
double meet[111][111];

int main() {
	int tests;
	scanf("%d", &tests);
	for (int casenum = 1; casenum <= tests; ++casenum) {
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%c %d %d\n", &c[i], &s[i], &p[i]);			
			if (c[i] == 'L')
				lane[i] = 0;
			else
				lane[i] = 1;				
		} 
		en = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) if (i != j) {
				meet[i][j] = inf;
				if (p[i] < p[j] && s[i] > s[j]) {
					double t = 1.0 * (p[j] - p[i] - 5) / (s[i] - s[j]);
					e[en++] = mp(t, mp(i, j));
					//printf("%.2lf ", e[en - 1].f);
				}
			}
		}
		//puts("");
		sort(e, e + en);
		int k = 0;
		while (k < en) {
			//printf("k=%d\n", k);
			int i = e[k].s.f;
			int j = e[k].s.s;
			if (lane[i] != lane[j]) {
				++k;
				continue;
			}				
			
			bool valid = true;
			for (int m = 0; m < n; ++m) if (lane[m] == 1 - lane[i]) {
				double xi = p[i] + e[k].f * s[i];
				double xm = p[m] + e[k].f * s[m];
				if (fabs(xi - xm - 5.0) < eps) {
					if (s[i] < s[m]) valid = false;
				}
				else if (fabs(xm - xi - 5.0) < eps) {
					if (s[m] < s[i]) valid = false;
				}
				else if (fabs(xm - xi) < 5.0)
					valid = false;
			}
			
			if (valid) {
				lane[i] = 1 - lane[i];
				++k;
				continue;
			}		
			valid = true;
			for (int m = 0; m < n; ++m) if (lane[m] == 1 - lane[j]) {
				double xj = p[j] + e[k].f * s[j];
				double xm = p[m] + e[k].f * s[m];
				if (fabs(xj - xm - 5.0) < eps) {
					if (s[j] < s[m]) valid = false;
				}
				else if (fabs(xm - xj - 5.0) < eps) {
					if (s[m] < s[j]) valid = false;
				}
				else if (fabs(xm - xj) < 5.0)
					valid = false;			
			}	
			if (valid) {
				lane[j] = 1 - lane[j];
				++k;
				continue;
			}	
			
			break;
		}
		
		printf("Case #%d: ", casenum);
		if (k < en)
			printf("%.10lf\n", e[k].f);
		else
			puts("Possible");			
	}
	return 0;		
}

