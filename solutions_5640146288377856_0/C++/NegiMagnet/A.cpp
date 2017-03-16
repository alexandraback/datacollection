#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int,int> pii;

int main() {
	int t;
	cin >> t;
	for(int dt=1; dt<=t; dt++) {
		int r, c, w;
		cin >> r >> c >> w;
		cout << "Case #" << dt << ": ";
		if(w==1) {
			cout << r*c << endl;
		} else {
			int ans = r * (c/w) + w - 1;
			if(c%w) ans++;
			cout << ans << endl;
		}
	}
	return 0;
}
