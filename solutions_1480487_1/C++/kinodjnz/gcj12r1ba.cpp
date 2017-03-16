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

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int N;
		scanf("%d", &N);
		int s[210];
		pair<int, int> ss[210];
		int t = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &s[j]);
			t += s[j];
			ss[j].first = s[j];
			ss[j].second = j;
		}
		sort(ss, ss+N);
		double a[210] = {};
		for (int j = 0; j < N; j++) {
			int k;
			int u = 0;
			for (k = 0; k < N; k++) {
				if (ss[k].second == j)
					break;
				u += ss[k].first;
			}
			for (; k < N; k++) {
				u += ss[k].first;
				double d = (double)(t + u)/(k+1);
				if ((k == N-1 || ss[k+1].first >= d) && ss[k].first <= d) {
					//printf("d=%g t=%d k=%d u=%d\n", d, t, k, u);
					a[j] = (d-s[j])/t;
					break;
				}
			}
		}
		printf("Case #%d:", i+1);
		for (int j = 0; j < N; j++)
			printf(" %.9f", a[j]*100);
		printf("\n");
	}
}
