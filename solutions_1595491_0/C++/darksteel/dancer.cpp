#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int i, j, T;
	cin >> T;
	for(i = 1; i <= T; i++) {
		int n, s, p;
		cin >> n >> s >> p;
		int t, ans = 0;
		for(j = 0; j < n; j++) {
			cin >> t;
			if(t < p) continue;
			int d = (p < 2 ? 0 : p - 2);
			d = 2 * d + p;
			switch(t % 3) {
				case 0: if(t/3 >= p) ans++; 
					else if(t >= d && s) { s--; ans++; }
					break;
				case 1: if((t+2)/3 >= p) ans++; 
					else if(t >= d && s) { s--; ans++; }
					break;
				case 2: if((t+1)/3 >= p) ans++; 
					else if(t >= d && s) { s--; ans++; }
					break;
			}
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}
