#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool compare1 (pair <pair <int, int> , pair <int, int> > a, pair <pair <int, int> , pair <int, int> > b) {
	return a.first.first < b.first.first;
}

int main () {
	int T, pocet, d, n, w, e, s, dd, dp, ds, victories;
	scanf("%d", &T);
	bool issucc;
	vector <pair <pair <int, int> , pair <int, int> > > attacks;
	vector <int> wall, todo;
	for (int kolkoskusam = 0; kolkoskusam < T; kolkoskusam ++) {
		scanf("%d", &pocet);
		victories = 0;
		for (int i = 0; i < pocet; i++) {
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			w += 300;
			e += 300;
			for (int j = 0; j < n; j++) {
				attacks.push_back(make_pair (make_pair (d + dd*j, s + ds * j), make_pair (w + dp * j, e + dp * j)));
			}
		}
		attacks.push_back (make_pair (make_pair (1000000, -1), make_pair (-1, -1)));
		sort (attacks.begin(), attacks.end(), compare1);
		wall.resize(800, 0);
		for (int i = 0; i < (int) attacks.size() - 1; i++) {
//			printf("interval: %d %d\n", attacks [i].second.first, attacks [i].second.second);
			issucc = false;
			for (int j = attacks [i].second.first; j < attacks [i].second.second; j++) {
				if (wall [j] < attacks [i].first.second) issucc = true;
			}
			if (issucc) {
//				cout << "jupi " << attacks [i].second.first << ' ' << attacks [i].second.second << endl;
				victories ++;
				todo.push_back(i);
				if (attacks [i].first.first != attacks [i + 1].first.first) {
					for (int j = 0; j < (int) todo.size(); j++) {
						for (int k = attacks [todo [j]].second.first; k < attacks [todo [j]].second.second; k++) {
							wall [k] = max (wall [k], attacks [todo [j]].first.second);
						}
					}
					todo.clear();
				}
			}
		}
		printf("Case #%d: %d\n", kolkoskusam + 1, victories);
		attacks.clear();
		wall.clear();
		todo.clear();
	}
	return 0;
}