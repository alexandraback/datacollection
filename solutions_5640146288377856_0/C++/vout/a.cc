#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int T; 
    cin >> T;
    for (int re = 1; re <= T; ++re) {
    	int r, c, w;
    	cin >> r >> c >> w;
    	int l = c % w;
    	int ans = max(0, c - w - l) / w;
    	ans += w + (min(c, w + l) != w);

    	cout << "Case #" << re << ": " << ans << endl;
    }
    return 0;
}