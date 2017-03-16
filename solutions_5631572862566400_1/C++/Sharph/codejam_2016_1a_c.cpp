#include <iostream>
#include <deque>
#include <cassert>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

int F[1024];
int idx[1024];

tuple<int, int, int, int> xd(int v) {
	fill(idx, idx + 1024, -1);
	int i = 0;
	while(idx[v] == -1) {
		idx[v] = i++;
		v = F[v];
	}
	int m = 1024;
	int s = v;
	do {
		m = min(m, v);
		v = F[v];
	} while(v != s);
	return make_tuple(idx[v], i - idx[v], m, v);
}

int main() {
	int T;
	cin >> T;
	
	for(int Te = 0; Te < T; ++Te) {
		int N;
		cin >> N;
		for(int i = 0; i < N; ++i) {
			cin >> F[i];
			--F[i];
		}
		
		int ret = 3;
		map<int, map<int, int>> asd;
		for(int i = 0; i < N; ++i) {
			int p, c, m, v;
			tie(p, c, m, v) = xd(i);
			if(c == 2) {
				asd[m][v] = max(asd[m][v], p);
			} else {
				assert(c > 2);
				ret = max(ret, c);
			}
		}
		int asdsum = 0;
		for(pair<int, map<int, int>> p : asd) {
			for(pair<int, int> p2 : p.second) {
				asdsum += p2.second;
			}
			asdsum += 2;
		}
		ret = max(ret, asdsum);
		
		cout << "Case #" << Te + 1 << ": " << ret << "\n";
	}
	
	return 0;
}
