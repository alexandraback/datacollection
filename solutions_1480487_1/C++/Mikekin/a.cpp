#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

const double eps = 1e-9;
const double www = 1e-7;
int t, n, s, c;
double sum, l, r, mid, tmp, q;
int f[300];

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> t; c = 0;
	while (t--) {
		++c;
		cin >> n;
		s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &f[i]);
			s += f[i];
		}
		printf("Case #%d:", c);
		for (int i = 0; i < n; i++) {
			l = 0; r = 100;
			while (r - l >= www) {
				mid = (l + r) / 2.0;
				sum = s; tmp = f[i]; tmp += mid / 100.0 * sum + eps;
			   	for (int j = 0; j < n; j++) {
					q = f[j]; q = tmp - q;
					if (q > eps) sum -= q;
				}
				if (sum > -eps) l = mid; else r = mid;
			}
			mid = (l + r) / 2.0;
			printf(" %.6lf", mid);
		}
		printf("\n");
	}
	return 0;
}

