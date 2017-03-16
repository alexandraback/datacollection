#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int> > prev;
void ppath(int x, int i) {
	if (x) {
		ppath(prev[x][i], 0);
		cout << (prev[x][i] ? " " : "") << x-prev[x][i];
	}
}

int main() {
	int T, NC = 1, n;
	cin >> T;
	while (T-- && cin >> n) {
		map<int, int> m, mm;
		prev.clear();
		m[0] = 1;
		mm = m;
		cout << "Case #" << NC++ << ":" << endl;
		int a;
		bool f = false;
		for (int i = 0; i < n && cin >> a; ++i) {
			if (f) continue;
			for (map<int,int>::iterator it = m.begin(); it != m.end(); ++it) {
				int b = it->first;
				mm[b + a] += mm[b];
				prev[b + a].push_back(b);
				if (mm[b + a] > 1) {
					f = true;
					ppath(b+a, 0); cout << endl;
					ppath(b+a, 1); cout << endl;
					break;
				}
			}
			m = mm;
		}
		if (!f)
			cout << "Impossible" << endl;
	}
}