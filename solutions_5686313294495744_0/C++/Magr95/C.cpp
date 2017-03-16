#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	freopen("C-small-attempt1.in-2.txt", "r", stdin);
	freopen("small.txt", "w", stdout);
	int n;
	cin >> n;
	
	for (int l = 1; l <= n; l++) {
		map<string, int> w1, w2;
		map<string, set<string> > ms;
		printf("Case #%d: ", l);
		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			w1[s1]++;
			w2[s2]++;
			ms[s1].insert(s2);
		}
		int cont = 0;
		for (auto it = w1.begin(); it != w1.end(); ++it) {
			if (it->second > 1){
				int fake = it->second - 1;
				int pos = 0;
				bool ok = true;

				for (auto it2 = ms[it->first].begin(); it2 != ms[it->first].end(); ++it2) {
					//if (it2->second > 1) pos += it2->second
					if (w2[*it2] > 1) {
						pos++;
					} else ok = false; 
					w2[*it2]--;
				}
				cont += pos;
				if (pos > 0 && ok) cont--;
			} else {
				//w2[*(ms[it->first].begin())]--;
			}
		}
		cout << cont << endl;
	}
	return 0;
}