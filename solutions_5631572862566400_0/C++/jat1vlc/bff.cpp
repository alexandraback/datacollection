#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int t, n, x, ca = 1;
	cin >> t;
	while (t--) {
		cin >> n;
		unordered_map<int, int> m;
		for (int i = 1; i <= n; i++) {
			cin >> x;
			m.insert(make_pair(i, x));
		}
		int maxSize = 0;
		for (int i = 1; i <= n; i++) {
			unordered_set<int> currCir;
			currCir.insert(i);
			int prev = i, prevprev = 0;
			while (currCir.find(m[prev]) == currCir.end()) {		
				currCir.insert(m[prev]);
				prevprev = prev;
				prev = m[prev];
			}
			int currSize = currCir.size();		
			 
			if (m[prev] != i) {
				currSize--;
				if (m[prev] == prevprev) {
					currSize++;
					for (auto it = m.begin(); it != m.end(); it++) {
						if (it->second == prev && currCir.find(it->first) == currCir.end()) {
							currSize++;
							break;
						}
					}
				}
			}	

			if (maxSize < currSize) {
				maxSize = currSize;
			}
		}
		cout << "Case #" << ca++ << ": " << maxSize << endl;
	}
}
