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

double p[111111], pmis[111111];
int a, b;

int main() {
	int tests;
	scanf("%d", &tests);
	for (int casenum = 1; casenum <= tests; ++casenum) {
		scanf("%d%d", &a, &b);
		double cur = 1.0;
		for (int i = 1; i <= a; ++i) {
			scanf("%lf", &p[i]);
			cur *= p[i];
			pmis[i] = 1.0 - cur;
			//printf("%.2lf ", pmis[i]);
		}			
		pmis[0] = 0.0;
		
		double res = b + 2;
		
		for (int k = 0; k <= a; ++k) {
			double cur = k + b - a + k + 1;
			cur += pmis[a - k] * (b + 1);
			res = min(res, cur);
		}
		printf("Case #%d: %.10lf\n", casenum, res);
	}
	
	return 0;		
}

