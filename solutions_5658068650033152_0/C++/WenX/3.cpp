#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int cc, tt;
	scanf("%d", &tt);
	for (cc = 1; cc <= tt; cc++){
		int m, n, k;
		int sm, sn, ans;
		scanf("%d%d%d", &m, &n, &k);
		
		ans = k;
		for (sm = 3; sm <= m; sm++)
		for (sn = 3; sn <= n; sn++){
			if (sm*sn - 4 >= k){
				if (ans == -1 || ans > sm * 2 + sn * 2 - 8)
					ans = sm * 2 + sn * 2 - 8;
			}
			else if (sm*sn - 3 >= k){
				if (ans == -1 || ans > sm * 2 + sn * 2 - 7)
					ans = sm * 2 + sn * 2 - 7;
			}
			else if (sm*sn - 2 >= k){
				if (ans == -1 || ans > sm * 2 + sn * 2 - 6)
					ans = sm * 2 + sn * 2 - 6;
			}
			else if (sm*sn - 1 >= k){
				if (ans == -1 || ans > sm * 2 + sn * 2 - 5)
					ans = sm * 2 + sn * 2 - 5;
			}
			else if (sm*sn - 0 >= k){
				if (ans == -1 || ans > sm * 2 + sn * 2 - 4)
					ans = sm * 2 + sn * 2 - 4;
			}
			if (sm != m || sn!=n)
			if (sm*sn == k+1)
			if (ans == -1 || ans > sm * 2 + sn * 2 - 4 + 1)
				ans = sm * 2 + sn * 2 - 4 + 1;
		}

		cout << "Case #" << cc << ": " << ans << endl;
		
	}
}