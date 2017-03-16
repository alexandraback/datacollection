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
	int cs;
	cin >> cs;
	for(int ccase = 1; ccase <= cs; ccase++){
		cout << "Case #" << ccase << ":\n";
		int len, nums;
		cin >> len >> nums;
		for(int i = 0; i < nums; i++){
			string res(len , '1');
			int mask = i;
			for(int pos = 2; pos < len - 2; pos += 2){
				res[pos] = res[pos+1] = '0' + (mask & 1);
				mask >>= 1;
			} // this should be divisible for (base + 1) for every base
			cout << res;
			for(int base = 2; base <= 10; base++){
				cout << " " << base + 1;
			}
			cout << "\n";
		}
	}

	return 0;
}
