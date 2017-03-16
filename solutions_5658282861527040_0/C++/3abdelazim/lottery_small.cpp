#include <iostream>
#include <cstdio>

using namespace std;

#define For(i,a,b) for (int i = a; i < b; i++)

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	
	int tt;
	cin >> tt;
	For (t, 1, tt+1) {
		int a, b, k;
		cin >> a >> b >> k;
		int res = 0;
		For (i,0,a) {
			For (j,0,b) {
				if ((i & j) < k)
					res++;
			}
		}
		cout << "Case #" << t << ": " << res << endl;
	}
} 
