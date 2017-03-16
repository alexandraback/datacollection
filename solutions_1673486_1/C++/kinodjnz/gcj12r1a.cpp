#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

double p[110000];
double q[110000];

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		for (int j = 0; j < A; j++)
			scanf("%lf", &p[j]);
		double x = 1.0;
		for (int j = 0; j < A; j++) {
			x *= p[j];
			q[j] = x;
		}
		double ans = B+2;
		for (int j = 0; j < A; j++) {
			double y = (1.0-q[A-1-j])*(B+1) + (B - A + 2*j+1);
			if (y < ans)
				ans = y;
		}
		printf("Case #%d: %.9f\n", i+1, ans);
	}
}
