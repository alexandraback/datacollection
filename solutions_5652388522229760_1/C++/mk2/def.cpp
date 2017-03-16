#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = 2e9;
const ll LINF = 8e18;
const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int cx = 1; cx <= n; cx++){
		int k;
		cout << "Case #" << cx << ": ";
		cin >> k;
		if(k == 0){
			cout << "INSOMNIA\n";
			continue;
		}
		int xx = 0;
		int rs;
		for(rs = k; xx < 1023; rs += k){
			int r = rs;
			while(r){
				xx |= 1 << (r % 10);
				r /= 10;
			}
		}
		cout << rs - k << "\n";
	}
	return 0;
}
