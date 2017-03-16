#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node {
	int j, p, s;
};

int main () {
	int t;
	cin >> t;
	for (int casei = 1; casei <= t; casei++) {
		int j, p, s, k;
		cin >> j >> p >> s >> k;
		vector<Node> possible;
		map<pair<int, int>, int> fs, st, ft;
		for (int x = 1; x <= j; x++) {
			for (int y = 1; y <= p; y++) {
				for (int z = 1; z <= s; z++) {
					Node n;
					n.j = x;
					n.p = y;
					n.s = z;
					fs[make_pair(n.j, n.p)]++;
					st[make_pair(n.p, n.s)]++;
					ft[make_pair(n.j, n.s)]++;
					if (fs[make_pair(n.j, n.p)] <= k && st[make_pair(n.p, n.s)] <= k && ft[make_pair(n.j, n.s)] <= k) {
						possible.push_back (n);
					} else {
						fs[make_pair(n.j, n.p)]--;
						st[make_pair(n.p, n.s)]--;
						ft[make_pair(n.j, n.s)]--;
					}
				}
			}		
		}
		cout << "Case #" << casei << ": " << possible.size() << endl;
		int size = possible.size();
		for (int i = 0; i < size; i++) {
			cout << possible[i].j << " " << possible[i].p << " " << possible[i].s << endl;
		}
	}
	return 0;
}