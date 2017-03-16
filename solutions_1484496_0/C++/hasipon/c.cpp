#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		int N;
		cin >> N;
		vector<int> S(N);
		for (int i = 0; i < N; ++ i) {
			cin >> S[i];
		}
		printf("Case #%d:\n", tt);
		map<int, vector<int> > a;
		for (int i = 1; i < 1<<N; ++ i) {
			int s = 0;
			for (int j = 0; j < N; ++ j) if ((i>>j)&1) {
				s += S[j];
			}
			a[s].push_back(i);
		}
		for (map<int,vector<int> >::iterator i = a.begin(); i != a.end(); ++ i) {
			for (int j = 0; j < (int)i->second.size(); ++ j) {
				for (int k = j+1; k < (int)i->second.size(); ++ k) {
					if ((i->second[j] & i->second[k]) == 0) {
						vector<int> a, b;
						for (int p = 0; p < N; ++ p) {
							if ((i->second[j]>>p)&1) a.push_back(S[p]);
							if ((i->second[k]>>p)&1) b.push_back(S[p]);
						}
						for (int p = 0; p < (int)a.size(); ++ p) {
							if (p) cout << " ";
							cout << a[p];
						}
						cout << endl;
						for (int p = 0; p < (int)b.size(); ++ p) {
							if (p) cout << " ";
							cout << b[p];
						}
						cout << endl;
						goto next;
					}
				}
			}
			//goto next;
		}
		cout << "Impossible" << endl;
		next:;
	}
}
