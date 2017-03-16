#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define MAXN 100500

int a, b;
double v[MAXN];
double prob[MAXN];

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d %d", &a, &b);
		b = b - a;
		prob[0] = 1.0;
		for (int i = 0; i < a; i++) {
			scanf("%lf", &v[i]);
			prob[i+1] = prob[i] * v[i];
		}
		double res;
		double p = prob[a];
		res = a + b + 2;
		res = min(res, (b + 1) * p + (b + 1 + a + b + 1) * (1 - p));
		
		double x;
		for (int i = 1; i <= a; i++) {
			x = (1 + 2*(i) + b) * prob[a-i] + (2 + 2*(i) + b + a + b) * ( 1 - prob[a-i]);
			res = min(res, x);	
		}
		printf("Case #%d: %.6lf\n", k+1, res);
	}
	return 0;
}