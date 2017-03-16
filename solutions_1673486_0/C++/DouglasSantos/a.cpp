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

int a, b;
double v[10];
double prob[10];

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d %d", &a, &b);
		b = b - a;
		for (int i = 0; i < a; i++) {
			scanf("%lf", &v[i]);	
		}
		for (int i = 0; i < (1 << a); i++) {
			prob[i] = 1.0;
			for (int j = 0; j < a; j++) {
				if ((1 << j) & i) {
					prob[i] = prob[i] * v[j];
				}
				else {
					prob[i] = prob[i] * (1 - v[j]);	
				}
			}	
		}
		double res = 1e50;
		double x;
		x = 0.0;
		for (int i = 0; i < (1 << a); i++) {
			if (i == (1 << a) - 1) {
				x = x + (b + 1) * prob[i];
			}
			else {
				x = x + (b + 1 + a + b + 1) * prob[i];
				//printf("%d\n", (b + 1 + a + b + 1));	
			}
		}
		res = min(res, x);
		
		x = 0.0;		
		for (int i = 0; i < (1 << a); i++) {
			x = x + (a + b + 2) * prob[i];
		}
		res = min(res, x);
		
		for (int j = 0; j < a; j++) {
			x = 0.0;
			for (int i = 0; i < (1 << a); i++) {
				bool erro = false;
				for (int c = 0; c < a - 1 -j; c++) {
					if (! ((1 << c) & i)) {
						erro = true;
						break;	
					}
				}
				if (!erro) {
					x = x + (1 + 2*(j+1) + b) * prob[i];
				}
				else {
					x = x + (2 + 2*(j+1) + b + a + b) * prob[i];	
				}	
			}
			//printf("%lf\n", x);
			res = min(res, x);
		}	
		printf("Case #%d: %.6lf\n", k+1, res);
	}
	return 0;
}