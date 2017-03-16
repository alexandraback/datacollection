#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

int ps[210];

int main() {
	int T;
	cin >> T;
	for(int c = 1; c <= T; ++c) {
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> ps[i];
		printf("Case #%d:", c);
		int x = 0;
		for(int i = 0; i < n; ++i) x += ps[i];
		for(int i = 0; i < n; ++i) {
			double r = 0, l = 1;
			for(int lp = 0; lp < 100; ++lp) {
				double h = (r + l) / 2;
				double sc = ps[i] + x * h, sum = 0;
				bool ok = false;
				for(int j = 0; j < n; ++j) if(j != i && ps[j] < sc){
					if(sc - ps[j] > x) ok = true;
					sum += min(1.0, (sc - ps[j]) / x);
				}
				if(!ok && sum + h <= 1.0) r = h;
				else l = h;
			}
			printf(" %.8f", l * 100);
		}
		puts("");
	}
	return 0;
}
