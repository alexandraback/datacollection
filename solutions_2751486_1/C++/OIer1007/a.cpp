#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <climits>
#include <algorithm>
using namespace std;


int dp[1000005], pos[1000005];
bool fuck[1000005];

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int t;
	cin >> t;
	for (int l = 1; l <= t; l++) {
		string s;
		int m, n;
		cin >> s >> m;
		n = s.size();
		memset(dp, -1, sizeof(dp));
		memset(pos, -1, sizeof(pos));
		for (int i = 0; i < n; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') fuck[i] = true;
			else fuck[i] = false; 
		}
		if (fuck[0]) dp[0] = 0;
		else {
			dp[0] = 1;
			if (dp[0] >= m) pos[0] = 0;
		}
		for (int i = 1; i < n; i++) {
			if (fuck[i]) {
				dp[i] = 0;
				pos[i] = pos[i - 1];
			}
			else {
				dp[i] = dp[i - 1] + 1;
				if (dp[i] >= m) pos[i] = i - m + 1;
				else pos[i] = pos[i - 1];
			}
		}
		
		long long res = 0;
		for (int i = 0; i < n; i++) {
			if (pos[i] != -1) res += (long long)(pos[i] + 1);
		} 
		cout << "Case #" << l << ": " << res << "\n";
	}
		return 0;
}
			
						
			
			 
		
	
