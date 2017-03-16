#include <iostream>
#include <deque>
#include <cassert>
#include <vector>

using namespace std;

int count[3030];

int main() {
	int T;
	cin >> T;
	
	for(int Te = 0; Te < T; ++Te) {
		fill(count, count + 3030, 0);
		
		int n;
		cin >> n;
		for(int i = 0; i < 2 * n - 1; ++i) {
			for(int j = 0; j < n; ++j) {
				int x;
				cin >> x;
				++count[x];
			}
		}
		
		vector<int> ls;
		for(int i = 0; i < 3030; ++i) {
			if(count[i] & 1) ls.push_back(i);
		}
		assert((int)ls.size() == n);
		
		cout << "Case #" << Te + 1 << ':';
		for(int x : ls) {
			cout << ' ' << x;
		}
		cout << '\n';
	}
	
	return 0;
}
