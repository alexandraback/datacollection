#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define N 300
int n;
int s[N];

int main() {
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; I++) {
		scanf("%d", &n);
		int total = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", s + i);
			total += s[i];
		}
		int k = 0;
		int m = 0;
		double average = total * 2.0 / n;
		int t;
		do {
			t = k;
			k = 0;
			m = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] < average) {
					k++;
					m += s[i];
				}
			}
			average = (total + m) * 1.0 / k;
		} while (t != k);
		
		printf("Case #%d:", I + 1);
		for (int i = 0; i < n; i++) {
			if (s[i] > average) printf(" %.6f", 0.0);
			else printf(" %.6f", (average - s[i]) / total * 100);
		}
		printf("\n");
	}
}
