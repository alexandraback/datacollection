#include <iostream>
#include <map>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <bitset>
#include <string.h>

using namespace std;

#define ll long long
#define mp make_pair

int a, b, c, k, tt;
vector<pair<int, pair<int, int> > > v;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> tt;
	for (int ii = 0; ii < tt; ii++) {
		cin >> a >> b >> c >> k;
		v.clear();
		if (k >= 3) {
			for (int i = 1; i <= a; i++) {
				for (int j = 1; j <= b; j++) {
					for (int z = 1; z <= c; z++) {
						v.push_back(mp(i, mp(j, z)));
					}
				}
			}
		}
		else if (k == 1) {
			if (a == 1 && b == 1) {
				v.push_back(make_pair(1, make_pair(1, 1)));
			}
			else if (a == 1 && b == 2) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
			}
			else if (a == 1 && b == 3) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
				v.push_back(make_pair(1, make_pair(3, 3)));
			}
			else if (a == 2 && b == 2) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
				v.push_back(make_pair(2, make_pair(1, 2)));
				v.push_back(make_pair(2, make_pair(2, 1)));
			}
			else if (a == 2 && b == 3) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
				v.push_back(make_pair(1, make_pair(3, 3)));
				v.push_back(make_pair(2, make_pair(1, 2)));
				v.push_back(make_pair(2, make_pair(2, 3)));
				v.push_back(make_pair(2, make_pair(3, 1)));
			}
			else if (a == 3) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
				v.push_back(make_pair(1, make_pair(3, 3)));
				v.push_back(make_pair(2, make_pair(1, 2)));
				v.push_back(make_pair(2, make_pair(2, 3)));
				v.push_back(make_pair(2, make_pair(3, 1)));
				v.push_back(make_pair(3, make_pair(1, 3)));
				v.push_back(make_pair(3, make_pair(2, 1)));
				v.push_back(make_pair(2, make_pair(3, 2)));
			}
		}
		else if (k == 2) {
			if (a == 1 && b == 1 && c == 1) {
				v.push_back(make_pair(1, make_pair(1, 1)));
			}
			else if (a == 1 && b == 1 && c == 2) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 2)));
			}
			else if (a == 1 && b == 1 && c == 3) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 2)));
			}
			else if (a == 1 && b == 2) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 2)));
				v.push_back(make_pair(1, make_pair(2, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
			}
			else if (a == 1 && b == 3) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 2)));
				v.push_back(make_pair(1, make_pair(2, 1)));
				v.push_back(make_pair(1, make_pair(2, 3)));
				v.push_back(make_pair(1, make_pair(3, 2)));
				v.push_back(make_pair(1, make_pair(3, 3)));
			}
			else if (a == 2 && b == 2) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 2)));
				v.push_back(make_pair(1, make_pair(2, 1)));
				v.push_back(make_pair(1, make_pair(2, 2)));
				v.push_back(make_pair(2, make_pair(1, 1)));
				v.push_back(make_pair(2, make_pair(1, 2)));
				v.push_back(make_pair(2, make_pair(2, 1)));
				v.push_back(make_pair(2, make_pair(2, 2)));
			}
			else if (a == 2 && b == 3) {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 2)));
				v.push_back(make_pair(1, make_pair(2, 1)));
				v.push_back(make_pair(1, make_pair(2, 3)));
				v.push_back(make_pair(1, make_pair(3, 2)));
				v.push_back(make_pair(1, make_pair(3, 3)));
				v.push_back(make_pair(2, make_pair(1, 1)));
				v.push_back(make_pair(2, make_pair(1, 2)));
				v.push_back(make_pair(2, make_pair(2, 1)));
				v.push_back(make_pair(2, make_pair(2, 3)));
				v.push_back(make_pair(2, make_pair(3, 2)));
				v.push_back(make_pair(2, make_pair(3, 3)));
			}
			else {
				v.push_back(make_pair(1, make_pair(1, 1)));
				v.push_back(make_pair(1, make_pair(1, 3)));
				v.push_back(make_pair(1, make_pair(2, 1)));
				v.push_back(make_pair(1, make_pair(3, 3)));
				v.push_back(make_pair(2, make_pair(1, 2)));
				v.push_back(make_pair(2, make_pair(2, 2)));
				v.push_back(make_pair(2, make_pair(2, 3)));
				v.push_back(make_pair(3, make_pair(2, 1)));
				v.push_back(make_pair(3, make_pair(2, 3)));
				v.push_back(make_pair(1, make_pair(2, 2)));
				v.push_back(make_pair(1, make_pair(3, 2)));
				v.push_back(make_pair(2, make_pair(1, 1)));
				v.push_back(make_pair(2, make_pair(3, 3)));
				v.push_back(make_pair(2, make_pair(3, 1)));
				v.push_back(make_pair(3, make_pair(1, 2)));
				v.push_back(make_pair(3, make_pair(1, 3)));
				v.push_back(make_pair(3, make_pair(3, 1)));
				v.push_back(make_pair(3, make_pair(3, 2)));
			}
		}
		cout << "Case #" << ii + 1 << ": " << v.size() << endl;
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second << endl;
		}
	}
	return 0;
}