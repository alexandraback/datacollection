#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int T, s, n, p, a, b, c;
int t[150];
int counter;

int main() {
	scanf("%d", &T);
	
	for (int C = 1; C <= T; C++) {
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i++)
			scanf("%d", &t[i]);
		
		counter = 0;
		for (int i = 0; i < n; i++) {
			a = b = c = t[i] / 3;
			c += t[i] % 3 == 0? 0 : 1;
			b += t[i] % 3 == 2? 1 : 0;
			
			if (c >= p) {
				//cout << "a: " << a << ' ' << b << ' ' << c << endl;
				counter++;
			}
			else if (s) {
				if (t[i] % 3 == 0 && a)
					a--, c++;
				else if (t[i] % 3 == 2 && b)
					b--, c++;
				
				if (c >= p) {
					//cout << "b: " << a << ' ' << b << ' ' << c << endl;
					s--;
					counter++;
				}
			}
		}
		
		printf("Case #%d: %d\n", C, counter);
	}
	return 0;
}
