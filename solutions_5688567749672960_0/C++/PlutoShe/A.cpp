#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <memory>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "sstream"

using namespace std;

string s;

long long ans;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	// n = 100;
	for (int i = 0; i < n; i++) {
		long long j;
		cin >> j;
		long long sss = j;
// cout << "Case #" << i + 1 << ":" << ans << endl;
		ans = 0;
		while (j != 0) {
			long long newj = j - 1;
			int len = 0;
			// cout << j << endl;
			while (newj != 0) {
				newj = newj / 10;
				len++;
			}
			newj = j - 1;
			long long  w = 1;
			// cout << len << ' ' << newj << " "  << endl;
			for (int cd = 0; cd < (len + 1) / 2; cd++) {
				w = w * 10;
				newj = newj / 10;
			}
			long long w1 = w / 10;
			
			// cout << "!!" << endl;
			
			if (len % 2 == 1 && w1 != 1) {
				w1 = w1 / 10;
			}
			// cout << len << ' ' << newj << " " << w << " " << w1 << endl;
			if (newj != w1) {
				newj = newj * w + 1;
				
			} else {
				if (len % 2 == 1) {
					newj = newj * 10;
				}
				newj = newj - 1;
				// cout << newj << w << endl;
				for (int cd = 0; cd < len / 2; cd++) {
					newj = newj *10;
				}
				newj += 1;
				// newj = newj * (w / 10) + 1;
			}
			ans += j - newj + 1;
			// cout << "!!!" << j << " " << newj << endl;
			stringstream ss;
			ss << newj;
			string t = ss.str();
			reverse(t.begin(),t.end());
			// j = ltoi(t.c_str());
			sscanf(t.c_str(), "%lld\n",&j);
			// cout << "convert" << j << " " << ans << endl;
		}
		if (sss == 1) 
		cout << "Case #" << i + 1 << ": " << 1<< endl;
		else
		cout << "Case #" << i + 1 << ": " << ans - 2 << endl;
	}
	return 0;
}