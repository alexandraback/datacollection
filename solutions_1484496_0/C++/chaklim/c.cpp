#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int t, n, s;
int a[1000];
map<int, int> m;

int main() {
	cin >> t;
	
	for (int C = 1; C <= t; C++) {
	
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		
		int limit = 1;
		for (int i = 0; i < n; i++)
			limit <<= 1;
		
		m.clear();
		
		printf("Case #%d:\n", C);
		bool printed = 0;
		for (int i = 1; i < limit; i++) {
			s = 0;
			for (int j = 1, k = 0; j <= limit; j <<= 1, k++) {
				if (i & j) {
					s += a[k];
				}
			}
			
			if (m.find(s) != m.end()) {
				// have solution
				
				int s1 = m[s], s2 = i;
				bool sp = 0;
				for (int j = 1, k = 0; j <= limit; j <<= 1, k++) {
					if (s1 & j) {
						if (sp)
							cout << ' ';
						cout << a[k];
						sp = 1;
					}
				}
				puts("");
				sp = 0;
				for (int j = 1, k = 0; j <= limit; j <<= 1, k++) {
					if (s2 & j) {
						if (sp)
							cout << ' ';
						cout << a[k];
						sp = 1;
					}
				}
				puts("");
				printed = 1;
				break;
			}
			else {
				m[s] = i;
			}
		}
		
		if (!printed)
			puts("Impossible");
		
	}
	
	return 0;
}
