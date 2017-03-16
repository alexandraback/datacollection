#include <bits/stdtr1c++.h>

using namespace std;

typedef __int128 ll;

struct jcoin {
	int val;
	int div[11];
};

int main() {
    ios::sync_with_stdio(0);
	const int n = 32, m = 500;
	vector<jcoin> coins;
	for (int num = (1<<(n-1)) + 1; coins.size() < m; num += 2) {
		bitset<n> coin(num);
		
		bool jam = true;
		jcoin res;
		res.val = num;
		
		for (int b = 2; b <= 10; b++) {
			ll cnum = 0, cb = 1;
			for (int i = 0; i < n; i++) {
				cnum += coin[i] * cb;
				cb *= b;
			}
			
			res.div[b] = -1;
			for (int k = 2; k < 100/*k*k <= cnum*/; k++) {
				if (cnum % k == 0) {
					res.div[b] = k;
					break;
				}
			}
			if (res.div[b] == -1) {
				jam = false;
				break;
			}
		}
		
		if (jam) {
			coins.push_back(res);
			//cerr << "coin found! " << coin << " " << coins.size() << endl;
		}
	}
	
    int t = 1;
    for (int ca = 1; ca <= t; ca++) {
        cout << "Case #" << ca << ":" << endl;
		for (const auto& coin : coins) {
			cout << bitset<n>(coin.val);
			for (int b = 2; b <= 10; b++) {
				cout << " " << coin.div[b];
			}
			cout << endl;
		}
    }
	return 0;
}