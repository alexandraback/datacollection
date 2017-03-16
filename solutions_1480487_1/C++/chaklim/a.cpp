#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int t, n;
int s[1000], s2[1000];
double d[1000];

int main() {
	cin >> t;
	
	for (int C = 1; C <= t; C++) {
	
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		
		int minimum = s[0], total = 0;
		for (int i = 0; i < n; i++) {
			minimum = min(minimum, s[i]);
			total += s[i];
		}
		memcpy(s2, s, sizeof s);
		sort(s2, s2 + n);
		int second = s2[1];
		
		double target = 2.0f * total / (n + 0.0);
		double over = 0.0;
		int counter = 0;
		for (int i = 0; i < n; i++) {
			d[i] = (target - s[i] + 0.0) / (total + 0.0);
			d[i] *= 100;
			
			if (d[i] < 0.0) {
				over += -1 * d[i];
				d[i] = 0.0;
				counter++;
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (d[i] > 0.0) {
				d[i] -= (over / (n - counter + 0.0));
			}
		}
		
		printf("Case #%d:", C);
		
		for (int i = 0; i < n; i++)
			printf(" %.6f", d[i]);
		puts("");
	}
	
	return 0;
}
