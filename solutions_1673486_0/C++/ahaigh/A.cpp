/*
 ID: aandrew
 PROG: GCJ round 1A, problem A
 URL: 
 LANG: C++
 
 
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <utility>
#include <cassert>
#include <queue>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pt;

int T, A, B;
double p[100005];

int main() {
	cin >> T;
	REP(t, T) {
		cin >> A >> B; B -= A;
		REP(i, A) cin >> p[i];
		
		double best = 1 + (A + B) + 1;
		double z = 1;
		for (int n = A; n >= 0; n--) {
			best = min(best, z * (n + B + n + 1) + (1 - z) * (n + B + n + 1 + (A + B) + 1));
			z *= p[A - n];
		}
		
		printf("Case #%d: %0.9lf\n",t+1,best);
	}
}