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
//	freopen("attempt0.in", "r", stdin);
//	freopen("output.out", "w", stdout);
#endif
	int csn;
	cin >> csn;
	for(int ccase = 1; ccase <= csn; ccase++){
		cout << "Case #" << ccase << ": ";
		int c, k, s;
		cin >> k >> c >> s;
		if(s * c < k){
			cout << "IMPOSSIBLE\n";
			continue;
		}
		for(int check = k - 1; check >= 0; check -= c){
			ll pos = 0;
			for(int add = 0; add < c; add++){
				pos = pos * k + max(0, check - add);
			}
			cout << pos + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}
