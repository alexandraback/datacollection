#include <bits/stdc++.h>
using namespace std;
int main() {
#ifdef youmu
	freopen("D-small-attempt4.in", "r", stdin);
	freopen("D.ou", "w", stdout);
#endif
	int T, x, r, c, cases = 0;
	cin >> T;
	while(T--) {
		cin >> x >> r >> c;
		if(r > c) swap(r, c);
		bool flag = 0;
		if(x == 1) {
			 flag = 1;
		} 
		if(x == 2) {
			if((r * c) % 2 == 1) flag = 0; else flag = 1;
		} 
		if(x == 3) {
			if((r == 2 || r == 3) && c == 3) flag = 1; else flag = 0;
		}
		if(x == 4) {
			if((r == 3 || r == 4) && c == 4) flag = 1; else flag = 0;
		}
		printf("Case #%d: %s\n", ++cases, flag ? "GABRIEL" : "RICHARD");
	}
	return 0;
}
