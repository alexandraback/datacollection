#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define bits(x) __builtin_popcount(x)
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)

#define MAX 101000

double probs[MAX];
double acum[MAX];

int main() {
	int n,A,B;
	scanf("%d", &n);
	for (int caso = 1; caso <= n; caso++) {
		scanf("%d %d", &A, &B);
		
		for (int i=0;i<A;i++) {
			scanf("%lf", &probs[i]);
		}
		
		double ans = 2+B;
		
		acum[0]=probs[0];
		for (int i=1;i<=A;i++) {
			ans = min(ans, acum[i-1]*(2*(A-i)+B-A+1) + (1-acum[i-1])* (2*(A-i)+B-A+1+B+1));
			if (i<A) acum[i]=acum[i-1]*probs[i];
		}
		
		printf("Case #%d: %.9lf\n", caso, ans);
	}
	return 0;
}
