#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
using namespace std;
int main() {
	
	freopen("in.in","r",stdin);
	int t; cin >> t;
	freopen("out.out","w",stdout);
	for(int i = 1; i <= t; i++) {
		int r, c, w;
		cin >> r >> c >> w;
		int ans = 0;
		if(c % w == 0) {
			ans = c/w + w - 1;
		}
		else ans = c/w + w;
		cout << "Case #" << i << ": " << ans << '\n';
	}
	return 0;
}