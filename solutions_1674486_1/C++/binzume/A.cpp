#include <iostream>
#include <set>

using namespace std;

int main() {

	int T;
	cin >> T;

	int N,M;
	for (int tt=0;tt<T;tt++) {
		set<int> map[1024];
		int ff[1024] = {0};
		cin >> N;
		for (int i=1;i<=N; i++) {
			ff[i] = 0;
			cin >> M;
			for (int j=0;j<M; j++) {
				int c;
				cin >> c;
				map[i].insert(c);
			}
		}

		bool f;
		bool dia = false;
		do {
			f = false;
			for (int i=1;i<=N; i++) {
				if (ff[i] == 1) continue;
				bool ok = true;
				for (auto it=map[i].begin();it != map[i].end(); ++it) {
					if (ff[*it] == 0) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ff[i] = 1;
					set<int> tmp = map[i];
					for (auto it=tmp.begin();it != tmp.end(); ++it) {
						for (auto it2=map[*it].begin();it2 != map[*it].end(); ++it2) {
							if (map[i].find(*it2) != map[i].end()) {
								// cout << "dup:" << *it2 << endl;
								dia = true;
								break;
							}
							map[i].insert(*it2);
						}
					}
					// cout << i << endl;
					f = true;
				}
			}
		} while(f);

		cout << "Case #" << (tt+1) << ": ";
		cout << (dia?"Yes":"No");
		cout << endl;
	}

	return 0;
}

// 75
// 34.666667 + 26.666667 + 38.666667


