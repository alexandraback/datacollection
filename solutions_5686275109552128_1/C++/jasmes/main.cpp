#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
#include <string>
#include <map>
#include <functional>

using namespace std;

#define upto(i,n) for(int i = 0; i<n; ++i)


int cnt[1002];


int main() {
	int t, n, tmp, maxi;
	int res;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		maxi = 0;
		upto(i, n) {
			cin >> tmp;
			cnt[tmp]++;
			maxi = max(maxi, tmp);
		}
		res = maxi;
		int moves = 0;
		for (int i = 1; i < maxi; i++) {
			moves = 0;
			for (int j = i+1; j <= maxi; j++) {
				moves += cnt[j] * (j/i - (j%i==0) );
			}
			res = min(res, moves + i);
		}

		cout << "Case #" << tc << ": " << res << endl;

		
	}

return 0;
}