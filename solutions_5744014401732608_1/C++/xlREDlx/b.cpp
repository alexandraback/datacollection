#include <iostream>
#include <bitset>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int cas = 1; cas <= cases; ++cas) {
		cout << "Case #" << cas << ": ";
		unsigned long long b, m;
		cin >> b >> m;
		unsigned long long ma = (1LL << (b - 2LL));
		//cerr << ma << endl;
		if (m > ma) cout << "IMPOSSIBLE" << endl;
		else {
			cout << "POSSIBLE" << endl;
			vector<bool> v(b);
			v[b-1LL] = true;
			m--;
			for (unsigned long long i = 1LL; i < b; ++i) {
				v[b-1LL-i] = m&(1LL<<(i-1LL));
			}
			for (int i = 0; i < b; ++i) cout << v[i];
			cout << endl;
			for (unsigned long long i = 1LL; i < b; ++i) {
				for (unsigned long long j = 0; j < b; ++j) {
					if (j > i) cout << 1;
					else cout << 0;
				}
				cout << endl;
			}
		}
	}
}

